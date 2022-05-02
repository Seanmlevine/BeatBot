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
          case 40: // Drummer Boy Activation
              playDrummerBoy();
              break;      
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
 
