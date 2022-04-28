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
      }
    }
}

void noteToMotor(byte inChannel, byte inNumber) 
{   
    if (inChannel == 2)
    {
        switch(inNumber) {
  
          // Stepper Case
          case 36:  // Row 1
              CURR_ROW = moveRow(CURR_ROW, 1)
              break;
          case 37: // Row 2
              CURR_ROW = moveRow(CURR_ROW, 2)
              break;
          case 38: // Row 3
              CURR_ROW = moveRow(CURR_ROW, 3)
              break;
          case 39: // Row 4
              CURR_ROW = moveRow(CURR_ROW, 4)
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
              break;
          case 37: // Color 1
              break;
          case 38: // Color 2
              break;
          case 39: // Color 3
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
//}
