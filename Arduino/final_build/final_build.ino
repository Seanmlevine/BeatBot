// LED SCREEN LIBRARIES
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
//#include <SoftwareSerial.h>

// STEPPER MOTOR LIBRARY
#include <Stepper.h>

// HEADER FILES
#include "faces.h"
#include "constants.h"

// MIDI LIBRARY AND INITIALIZATION
#include <USB-MIDI.h>
USBMIDI_CREATE_DEFAULT_INSTANCE();

// Arduino pins for NeoPixels, Solenoids, and Stepper Motors
#define LED_PIN 6

// NOT NEEDED
//#define DIR_PIN_X  2
//#define STEP_PIN_X 3
//#define DIR_PIN_Y  4
//#define STEP_PIN_Y 5

#define SOLENOID_0 8 // the output pin on the Arduino we are using
#define SOLENOID_1 9
#define SOLENOID_2 10
#define SOLENOID_3 11

// NeoPixel strip/matrix variables
#define LED_COUNT 256
#define WIDTH 16
#define HEIGHT 16

// Declare our NeoPixel strip object and matrix object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(WIDTH, HEIGHT, LED_PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);

// Stepper motor constants
// NOT NEEDED
//const int stepsPerRevolution = 200;
//const int speedMicroSeconds = 200;


// Row and column starting positions
const int STEP_SIZE = 5000;
const int stepsPerRevolution = 5000;

int CURR_ROW = 0;
int CURR_COL = 0;

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated


void setup() {
  randomSeed(analogRead(0));
  
//  Serial.begin(9600);
//  Serial.println(smiley_test[0]);
//  Serial.println(matrix.Color(255, 0, 0));
  
//  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
//  strip.show();            // Turn OFF all pixels ASAP
//  strip.setBrightness(40); // Set BRIGHTNESS to about 1/6 (max = 255)

  // LED Matrix setup
  matrix.begin();
  matrix.setBrightness(40);
  matrix.show();

  // Stepper Motors setup

  // Possibly Declaring pins twice
//  pinMode(DIR_PIN_X, OUTPUT);
//  pinMode(STEP_PIN_X, OUTPUT);
//  pinMode(DIR_PIN_Y, OUTPUT);
//  pinMode(STEP_PIN_Y, OUTPUT);
  Stepper stepperY(stepsPerRevolution, 2, 3);
  Stepper stepperX(stepsPerRevolution, 4, 5);

  // Solenoid setup
  pinMode(SOLENOID_0, OUTPUT);
  pinMode(SOLENOID_1, OUTPUT);
  pinMode(SOLENOID_2, OUTPUT);
  pinMode(SOLENOID_3, OUTPUT);

//  // Rhythm Generator setup
//  float k = 1000.0;
//  for (int i = 0; i < maxNoteLength; i++) {
//    noteLen[i] = (int)(k * beatnote);
//
//    k /= 2;
//    /* noteLen indexes:
//      0 -> whole note
//      1 -> half note
//      2 -> quarter note
//      3 -> 8th note
//      4 -> 16th note
//      5 -> 32th note
//    */
//  }
//
//  makeSignals();  // Initial signal creation



  // MIDI TESTING

  // Do we need to keep the baud rate at 9600?
  Serial.begin(115200); //this value came from an example
  while (!Serial);
  MIDI.begin(MIDI_CHANNEL_OMNI);
  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);
  
}

void loop() {

  // MIDI TESTING
  MIDI.read();


  // RHYTHM GENERATOR SCRIPT
//  unsigned long currentMillis = millis();
//  
//  if (currentMillis - previousMillis >= beatTimeMinNote)
//  {
//    previousMillis = currentMillis;
//
//    readHit(genSignals[beatIndex][0], genSignals[beatIndex][1], genSignals[beatIndex][2], genSignals[beatIndex][3]);
//    beatIndex++;
//  }
//
//  if (beatIndex > maxSignalLength-1)
//  {
//    beatIndex = 0;
//    makeSignals();
//  }
//  
//  Test array for multiple positions 
//  uint8_t positions[100] = {0,0,0,0,0,0,0,0,0,0,1,2,3,2,1,0,3,2,0,0,3,2,1,0,2,2,0,3,1,0,2,3,0,1,2,0,3,1,0,3,0};
//  moveRows(positions)
//  // Move steppers forward and backward and actuate each solenoid
//  moveX(HIGH, stepsPerRevolution, speedMicroSeconds);
//  moveY(HIGH, stepsPerRevolution, speedMicroSeconds);
  CURR_ROW = changeRow(CURR_ROW, 3); // Y
//
//  hitOnBeat(beat, SOLENOID_0, true);
//  hitOnBeat(beat, SOLENOID_1, true);
//  hitOnBeat(beat, SOLENOID_2, true);
//  hitOnBeat(beat, SOLENOID_3, true);
//
  delay(1000); // Wait a second
//  
//  moveX(LOW, stepsPerRevolution, speedMicroSeconds);
//  moveY(LOW, stepsPerRevolution, speedMicroSeconds);
  CURR_ROW = changeRow(CURR_ROW, 1);
//  
//  hitOnBeat(beat, SOLENOID_0, true);
//  hitOnBeat(beat, SOLENOID_1, true);
//  hitOnBeat(beat, SOLENOID_2, true);
//  hitOnBeat(beat, SOLENOID_3, true);
//
  delay(1000); // Wait a second

//  moveUpDownImage(smile_open, -2);
//  delay(65);
//  moveUpDownImage(smile_open, -1);
//  delay(40);
//  displayLedImage(smile_open);
//  delay(40);
//  moveUpDownImage(smile_open, 1);
//  delay(427.173913);
//  displayLedImage(smile_open);
//  delay(40);



// ------ LED in-progress stuff below ------
  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  //unsigned long currentMillis = millis();


//  if (currentMillis - previousMillis >= intervals[int_index]) {
//    // save the last time you blinked the LED
//    previousMillis = currentMillis;
//
//    // show face
//    if (int_index = 0) moveUpDownImage(smile_open, -1);
//    if (int_index = 1) moveUpDownImage(smile_open, 1);
//
//    // change to next interval
//    int_index++;
//    if (int_index > sizeof(intervals)) int_index = 0; // reset int_index when reaching the last interval
//  }
  
//  // Fill along the length of the strip in various colors...
//  colorWipe(strip.Color(255,   0,   0), 20); // Red
//  colorWipe(strip.Color(  0, 255,   0), 20); // Green
//  colorWipe(strip.Color(  0,   0, 255), 20); // Blue

//  // Do a theater marquee effect in various colors...
//  theaterChase(strip.Color(127, 127, 127), 50); // White, half brightness
//  theaterChase(strip.Color(127,   0,   0), 50); // Red, half brightness
//  theaterChase(strip.Color(  0,   0, 127), 50); // Blue, half brightness
//
//  rainbow(10);             // Flowing rainbow cycle along the whole strip
//  theaterChaseRainbow(50); // Rainbow-enhanced theaterChase variant
}
