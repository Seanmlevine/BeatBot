/*Moved to final_build
 * 
#include <USB-MIDI.h>

// instances 
USBMIDI_CREATE_DEFAULT_INSTANCE();

*/

void printChannel(int inChannel)
{
    Serial.print("[");
    Serial.print(inChannel);
    Serial.print("] ");
}

void printNoteName(int note)
{
    int octave = note / 12;
    int nnumber = note % 12;
    Serial.print(notenames[nnumber]);
    Serial.print(octave - 2);
}

void handleNoteOn(byte inChannel, byte inNumber, byte inVelocity)
{
    printChannel(inChannel);
    printNoteName(inNumber);
    Serial.print(" NoteOn  ");
    Serial.print(inNumber);
    Serial.print("\tvelocity: ");
    Serial.println(inVelocity);

    noteToSolenoid(inChannel, inNumber);
    noteToMotor(inChannel,inNumber);
    noteToLED(inChannel,inNumber);
    noteToRhythmTrigger(inChannel,inNumber);
}

void handleNoteOff(byte inChannel, byte inNumber, byte inVelocity)
{
    printChannel(inChannel);
    printNoteName(inNumber);
    Serial.print(" NoteOff ");
    Serial.print(inNumber);
    Serial.print("\tvelocity: ");
    Serial.println(inVelocity);
}

void noteToSolenoid(byte inChannel, byte inNumber) 
{   
    if (inChannel == 1)
    {
        switch(inNumber) {
  
          // Solenoid Cases
          // Coordinating solenoid will hit when the MIDI note is played
          case 36:  // C1
              digitalWrite(SOLENOID_0, HIGH); // switch solenoid ON
              delay(20);
              digitalWrite(SOLENOID_0, LOW); // switch solenoid OFF
              break;
          case 37: // C#1
              digitalWrite(SOLENOID_1, HIGH); // switch solenoid ON
              delay(20);
              digitalWrite(SOLENOID_1, LOW); // switch solenoid OFF
              break;
          case 38: // D1
              digitalWrite(SOLENOID_2, HIGH); // switch solenoid ON
              delay(20);
              digitalWrite(SOLENOID_2, LOW); // switch solenoid OFF
              break;
          case 39: // D#1
              digitalWrite(SOLENOID_3, HIGH); // switch solenoid ON
              delay(20);
              digitalWrite(SOLENOID_3, LOW); // switch solenoid OFF
              break;
//          case 40: // Drummer Boy Activation
//              playDrummerBoy();
//              break;      
      }
    }
}

void noteToMotor(byte inChannel, byte inNumber) 
{   
    if (inChannel == 2)
    {
        switch(inNumber) {
  
          // Stepper Case
          // Make sure to place stepper notes an 1/8th note before the down beat
          case 36:  // Row 1
              CURR_ROW = changeRow(CURR_ROW, 0);
              break;
          case 37: // Row 2
              CURR_ROW = changeRow(CURR_ROW, 1);
              break;
          case 38: // Row 3
              CURR_ROW = changeRow(CURR_ROW, 2);
              break;
          case 39: // Row 4
              CURR_ROW = changeRow(CURR_ROW, 3);
              break;

          case 40:  // Col 1
              CURR_COL = moveCol(CURR_COL, 0);
              break;
          case 41: // Col 2
              CURR_COL = moveCol(CURR_COL, 1);
              break;
          case 42: // Col 3
              CURR_COL = moveCol(CURR_COL, 2);
              break;
          case 43: // Col 4
              CURR_COL = moveCol(CURR_COL, 3);
              break;

          case 44:  // Col -1
              CURR_COL = moveCol(CURR_COL, -1);
              break;
          case 45: // Col -2
              CURR_COL = moveCol(CURR_COL, -2);
              break;
          case 46: // Col -3
              CURR_COL = moveCol(CURR_COL, -3);
              break;
//          case 32: // Col -4
//              CURR_COL = moveCol(CURR_COL, -4);
//              break;
      }
    }
}

void noteToLED(byte inChannel, byte inNumber) 
{   
    if (inChannel == 3)
    {
        switch(inNumber) {
  
          // Stepper Case
          case 36:  // Head Movement
              //Head Bob Toggle
              if (toggle) {
                displayLedImage(smile_closed);
                toggle = false;
                Serial.println(toggle);
              } else {
                displayLedImage(smile_open);
                toggle = true;
                Serial.println(toggle);
              }
              
              break;
          case 37: // Color 1
            changeLEDColor(smile_closed, blue); // Face color: blue, small grin
            changeLEDColor(smile_open, blue);
            displayLedImage(smile_closed);
              break;
          case 38: // Color 2
            changeLEDColor(smile_closed, purple); // Face color: purple, smile
            changeLEDColor(smile_open, purple);
            displayLedImage(smile_closed);
              break;
          case 39: // Color 3
            changeLEDColor(smile_closed, green); // Face color: green, open mouth
            changeLEDColor(smile_open, green);
            displayLedImage(smile_closed);
              break;

          case 40: // Color 4
            changeLEDColor(smile_closed, red); // Face color: green, open mouth
            changeLEDColor(smile_open, red);
            displayLedImage(smile_closed);
              break;

          case 41: // Clear
            strip.clear();
              break;
              
          case 42: // theaterchase
            theaterChase(strip.Color(127, 127, 127), 50);
              break;

              
        }
    }
}

void noteToRhythmTrigger(byte inChannel, byte inNumber) 
{   
    if (inChannel == 4)
    {
        switch(inNumber) {
  
          // Stepper Case
          case 36:
            playRandMeasures(1);
            break;

          case 37:
            playSection(sec1_end, 32);
            break;

          case 38:
            playSection(sec2_mid, 32);
            break;

          case 39:
            playSection(sec3_mid, 32);
            break;

          case 40:
            playSection(sec4_mid, 32);
            break;

          case 41:
            playSection(sec4_end, 32);
            break;

          case 42:
            setNoteWeights(10, 20, 30, 40, 0, 0); // slow note rhythms
            break;

          case 43:
            setNoteWeights(5, 15, 30, 30, 20, 0); // medium-slow note rhythms
            break;

          case 44:
            setNoteWeights(0, 5, 35, 33, 20, 2);  // medium-fast note rhythms
            break;

          case 45:
            setNoteWeights(0, 0, 45, 30, 20, 5);  // fast note rhythms
            break;
        }
    }
}
// Added to final_build
/*
void setup()
{
    Serial.begin(115200);
    while (!Serial)
        ;
    MIDI.begin(MIDI_CHANNEL_OMNI);
    MIDI.setHandleNoteOn(handleNoteOn);
    MIDI.setHandleNoteOff(handleNoteOff);
    Serial.println("Arduino MIDI note detector.");
}


void loop()
{
    MIDI.read();
*/
 
