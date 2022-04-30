// In the setup loop:
// setMinNoteLength(3);
// setTempo(80);
// makeSignals();  // Initial signal creation

// Create drummer_boy piece in total

// Generates the drummer boy piece to then be played back.
void drummer_boy() {
/*
 * ==Section 1 (0:00-0:31)==
 * Face color: blue, small grin
 * BPM = 92
 * 
 * S1 plays four 4th notes
 * S2 joins in for four more 4th notes
 * S3 plays two 4th notes
 * S4 joins in for the last two 4th notes of this measure
 * S1-S4 play a single 8th note at a time
 * S1-S4 play a single 16th note at a time
 * S1-S4 play a single 32nd note at a time, twice
 * 
 * Random rhythms of 1st, 2nd, 4th, and 8th notes for 7 measures
 * S1 and S3 alternate from S2 and S4 for four 8th notes
 * S1-S4 play a single 8th note at a time, then the same happens in reverse from S4-S1
 * 
 * ==Section 2 (0:31-1:05)==
 * Face color: purple, smile
 * BPM = 112
 * 
 * Random rhythms of 1st, 2nd, 4th, 8th and 16th notes for 7 measures
 * S1-S3 play four 16th notes one after another, then S4 plays a single 4th note
 * Random rhythms of 1st, 2nd, 4th, 8th and 16th notes for 7 measures
 * S1 and S3 alternate from S2 and S4 for four 8th notes
 * S1-S4 play a single 8th note at a time, then the same happens in reverse from S4-S1
 * 
 * ==Section 3 (1:05-1:35)==
 * Face color: green, open mouth
 * BPM = 128
 * 
 * Random rhythms of 1st, 2nd, 4th, 8th and 16th with low chance for 32nd notes for 7 measures
 * S1 and S3 alternate with S2 and S4 in syncopated 16th rhythm
 * Random rhythms of 1st, 2nd, 4th, 8th and 16th with low chance for 32nd notes for 7 measures
 * S1 and S3 alternate from S2 and S4 for four 8th notes
 * S1-S4 play a single 8th note at a time, then the same happens in reverse from S4-S1
 * 
 * ==Intermission (1:35-1:37)==
 * Two second delay to stop face before showing animation of glitching out and becomes red devil
 * 
 * ==Section 4 (1:37-2:06)==
 * Face color: red, devil
 * BPM = 144
 * 
 * One measure pause (as is to count off) to highlight devil face after switching
 * Random rhythms of 4th, 8th 16th and 32nd notes for 3 measures
 * S1-S4 play a single 8th note at a time
 * S1-S4 play a single 16th note at a time
 * S1-S4 play a single 32nd note at a time, twice
 * Random rhythms of 4th, 8th 16th and 32nd notes for 3 measures
 * S1-S3 play four 16th notes one after another, then S4 plays a single 4th note
 * Random rhythms of 4th, 8th 16th and 32nd notes for 3 measures
 * S1 and S3 alternate with S2 and S4 in syncopated 16th rhythm
 * Random rhythms of 4th, 8th 16th and 32nd notes for 3 measures
 * S1-S4 play a single 16th note at a time, twice, then S1-S4 all hit at once
*/
}

// Called in a loop
void play() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= beatTimeMinNote)
  {
    previousMillis = currentMillis;

    readHit(genSignals[beatIndex][0], genSignals[beatIndex][1], genSignals[beatIndex][2], genSignals[beatIndex][3]);
    beatIndex++;
  }

  if (beatIndex > minSignalLength-1)
  {
    beatIndex = 0;
    makeSignals();
  }
}
