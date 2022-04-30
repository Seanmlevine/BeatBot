// Time signature
const int beats = 4;
const int beatnote = 4;

// Note lengths
const int minNoteLength = 5;  // Make 5 to include 32nd notes
const int minSignalLength = pow(2, minNoteLength);

// Tempo
int bpm = 100;
float beatTime = 60000 / bpm; // time of 1 beat in milliseconds
float beatTimeMinNote = beatTime * beats / pow(2, minNoteLength);

// Playback
int beatIndex = 0;
int measure = 0;
unsigned long currentMillis;
unsigned long previousMillis;

// Chance multipliers (in %)
int pauseChance = 20;

const int pauseInSequenceChance = 25; //Chance of having a pause in a triplet sequence
const int tripletChance = 0;  // Note sure we can handle this, so 0% chance for triplets for now

const int singledotChance = 20;
const int doubledotChance = 5;

const int overrideChance = 50;
float wholeNoteChance = 5;
float halfNoteChance = 10;
float quarterNoteChance = 30;
float eighthNoteChance = 30;
float sixteenthNoteChance = 15;
float thirtysecondNoteChance = 10;

// A list with the length (in beats x 1000) of all types of notes generated in the setup()
int noteLen[6];

// Arrays for the generated rhythm in note delays (ms) and in signal inputs (1s and 0s)
int r0[33];
int r1[33];
int r2[33];
int r3[33];
int genSignals[minSignalLength][4];

// For MIDI note names
const char *notenames[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
