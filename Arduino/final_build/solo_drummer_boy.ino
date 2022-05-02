// Generates the drummer boy piece to then be played back.
/*
 * ==Section 1 (0:00-0:31)==
 * Face color: blue, small grin
 * BPM = 88
 */
/* S1 plays four 4th notes
 * S2 joins in for four more 4th notes
 * S3 plays two 4th notes
 * S4 joins in for the last two 4th notes of this measure
 * S1-S4 play a single 8th note at a time
 * S1-S4 play a single 16th note at a time
 * S1-S4 play a single 32nd note at a time, twice
 */
int intro[128][4] = {
  // measure = 1.1
  {1, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 1.2
  {1, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 1.3
  {1, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 1.4
  {1, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 2.1
  {1, 1, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 2.2
  {1, 1, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 2.3
  {1, 1, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 2.4
  {1, 1, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 3.1
  {1, 1, 1, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 3.2
  {1, 1, 1, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 3.3
  {1, 1, 1, 1},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 3.4
  {1, 1, 1, 1},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 4.1
  {1, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 4.2
  {0, 0, 1, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 1},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 4.3
  {1, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 1},
  {0, 0, 0, 0},
  // measure = 4.4
  {1, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 1},
  {1, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 1},
};
/* 
 * Random rhythms of 1st, 2nd, 4th, and 8th notes for 7 measures
 * S1 and S3 alternate from S2 and S4 for four 8th notes
 * S1-S4 play a single 16th note at a time, then the same happens in reverse from S4-S1
 */
int sec1_end[32][4] = {
  // measure = 12.1
  {1, 0, 1, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 1, 0, 1},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 12.2
  {1, 0, 1, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 1, 0, 1},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 12.3
  {1, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 1},
  {0, 0, 0, 0},
  // measure = 12.4
  {0, 0, 0, 1},
  {0, 0, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 0, 0},
  {1, 0, 0, 0},
  {0, 0, 0, 0},
};

/* ==Section 2 (0:31-1:05)==
 * Face color: purple, smile
 * BPM = 108
 * 
 * Random rhythms of 1st, 2nd, 4th, 8th and 16th notes for 7 measures
 * S1-S3 play four 16th notes one after another, then S4 plays a single 4th note
 * Random rhythms of 1st, 2nd, 4th, 8th and 16th notes for 7 measures
 * S1 and S3 alternate from S2 and S4 for four 8th notes
 * S1-S4 play a single 16th note at a time, then the same happens in reverse from S4-S1
 */
int sec2_mid[32][4] = {
  // measure = 20.1
  {1, 0, 0, 0},
  {0, 0, 0, 0},
  {1, 0, 0, 0},
  {0, 0, 0, 0},
  {1, 0, 0, 0},
  {0, 0, 0, 0},
  {1, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 20.2
  {0, 1, 0, 0},
  {0, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 0, 0},
  // measure = 20.3
  {0, 0, 1, 0},
  {0, 0, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 0},
  // measure = 20.4
  {0, 0, 0, 1},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
};
 
/* ==Section 3 (1:05-1:35)==
 * Face color: green, open mouth
 * BPM = 120
 * 
 * Random rhythms of 2nd, 4th, 8th and 16th with low chance for 32nd notes for 7 measures
 * S1 and S3 alternate with S2 and S4 in syncopated 16th rhythm
 * Random rhythms of 2nd, 4th, 8th and 16th with low chance for 32nd notes for 7 measures
 * S1 and S3 alternate from S2 and S4 for four 8th notes
 * S1-S4 play a single 16th note at a time, then the same happens in reverse from S4-S1
 */
int sec3_mid[32][4] = {
  // measure = 36.1
  {1, 0, 1, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 1, 0, 1},
  {0, 0, 0, 0},
  {1, 0, 1, 0},
  {0, 0, 0, 0},
  // measure = 36.2
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 1, 0, 1},
  {0, 0, 0, 0},
  {1, 0, 1, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 36.3
  {0, 1, 0, 1},
  {0, 0, 0, 0},
  {1, 0, 1, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 1, 0, 1},
  {0, 0, 0, 0},
  // measure = 36.4
  {1, 1, 1, 1},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {1, 1, 1, 1},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
};

/* ==Intermission (1:35-1:37)==
 * Two second delay to stop face before showing animation of glitching out and becomes red devil
 */
 
/* ==Section 4 (1:37-2:06)==
 * Face color: red, devil
 * BPM = 132
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
int count_off[32][4] = {
  // measure = 45.0
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 45.0
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 45.0
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 45.0
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
};

int sec4_mid[32][4] = {
  // measure = 48.1
  {1, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 48.2
  {0, 0, 1, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 1},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 48.3
  {1, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 1},
  {0, 0, 0, 0},
  // measure = 48.4
  {1, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 1},
  {1, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 1},
};

int sec4_end[32][4] = {
  // measure = 60.1
  {0, 0, 0, 1},
  {0, 0, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 0, 0},
  {1, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 60.2
  {0, 0, 0, 1},
  {0, 0, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 0, 0},
  {1, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 60.3
  {1, 1, 1, 1},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  // measure = 60.4
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
};

// Plays a pregenerated array of notes
void playSection(int section[][4], int secLen) {
  beatIndex = 0;
  while (beatIndex < secLen){
    currentMillis = millis();
  
    if (currentMillis - previousMillis >= beatTimeMinNote)
    {
      previousMillis = currentMillis;
  
      readHit(section[beatIndex][0], section[beatIndex][1], section[beatIndex][2], section[beatIndex][3]);
      beatIndex++;
    }
    
    if (beatIndex % 4 == 0 && allowChange)
    {
      allowChange = false;
      if(downBeat) {
        displayLedImage(smile_closed);
        downBeat = false;
      } else {
        displayLedImage(smile_open);
        downBeat = true;
      }
    }
    if (beatIndex % 4 != 0) {allowChange = true;}
  }
}

// Plays a random solo for a specified number of measures
void playRandMeasures(int num_measures) {
  beatIndex = 0;
  measure = 0;
  while (measure < num_measures){
    currentMillis = millis();
    
    if (currentMillis - previousMillis >= beatTimeMinNote)
    {
      previousMillis = currentMillis;
  
      readHit(genSignals[beatIndex][0], genSignals[beatIndex][1], genSignals[beatIndex][2], genSignals[beatIndex][3]);
      beatIndex++;
    }

    if (beatIndex % 4 == 0 && allowChange)
    {
      allowChange = false;
      if(downBeat) {
        displayLedImage(smile_closed);
        downBeat = false;
      } else {
        displayLedImage(smile_open);
        downBeat = true;
      }
    }
    if (beatIndex % 4 != 0) {allowChange = true;}
    
    if (beatIndex > minSignalLength-1)
    {
      Serial.print("Measure = ");
      Serial.println(measure+1);
      measure++;
      beatIndex = 0;
      makeSignals();
    }
  }
}

int tempos[4] = {88, 108, 120, 132};

// Plays Drummer Boy solo
void playDrummerBoy() {
  setTempo(tempos[0]); // BPM = 88

// ====Intro====
  CURR_ROW = changeRow(CURR_ROW, 0);  // Move to Row 1
  delay(1000);
  Serial.println("Intro");
  changeLEDColor(smile_closed, blue); // Face color: blue, small grin
  changeLEDColor(smile_open, blue);
  displayLedImage(smile_closed);
  
  // 0) Play intro
  playSection(intro, 128);

// ====Section 1====
  Serial.println("Section 1");
  
  // 1a) play random section 1
  setNoteWeights(10, 20, 30, 40, 0, 0); // sec1 note chances
  makeSignals();
  playRandMeasures(7);

  // 1b) play sec1_end
  Serial.println("End of Section 1");
  playSection(sec1_end, 32);

// ====Section 2====
  CURR_ROW = changeRow(CURR_ROW, 1);  // Move to Row 2
  Serial.println("Section 2");
  setTempo(tempos[1]); // BPM = 108
  changeLEDColor(smile_closed, purple); // Face color: purple, smile
  changeLEDColor(smile_open, purple);
  displayLedImage(smile_closed);
  
  // 2a) play random section 2a
  setNoteWeights(5, 15, 30, 30, 20, 0); // sec2 note chances
  makeSignals();
  playRandMeasures(7);

  // 2b) play sec2_mid
  Serial.println("Middle of Section 2");
  playSection(sec2_mid, 32);

  // 2c) play random section 2c
  makeSignals();
  playRandMeasures(7);

  // 2d) play sec1_end
  Serial.println("End of Section 2");
  playSection(sec1_end, 32);

// ====Section 3====
  CURR_ROW = changeRow(CURR_ROW, 2);  // Move to Row 3
  Serial.println("Section 3");
  setTempo(tempos[2]); // BPM = 120
  changeLEDColor(smile_closed, green); // Face color: green, open mouth
  changeLEDColor(smile_open, green);
  displayLedImage(smile_closed);
  
  // 3a) play random section 3a
  setNoteWeights(0, 5, 35, 33, 20, 2); // sec3 note chances
  makeSignals();
  playRandMeasures(7);

  // 3b) play sec3_mid
  Serial.println("Middle of Section 3");
  playSection(sec3_mid, 32);

  // 3c) play random section 3c
  makeSignals();
  playRandMeasures(7);

  // 3d) play sec1_end
  Serial.println("End of Section 3");
  playSection(sec1_end, 32);

// ====Intermission====
  delay(2000);
  // glitch animation
  changeLEDColor(smile_closed, red); // Face color: red, devil
  changeLEDColor(smile_open, red);
  displayLedImage(smile_closed);
  delay(1000);

// ====Section 4====
  CURR_ROW = changeRow(CURR_ROW, 3);  // Move to Row 4
  Serial.println("Section 4");
  setTempo(tempos[3]); // BPM = 132

  // 4a) play count off measure
  Serial.println("Count off!");
  playSection(count_off, 32);

  // 4b) play random section 4b
  setNoteWeights(0, 0, 45, 30, 20, 5); // sec3 note chances
  makeSignals();
  playRandMeasures(3);

  // 4c) play sec4_mid
  Serial.println("1st Quarter of Section 4");
  playSection(sec4_mid, 32);

  // 4d) play random section 4d
  makeSignals();
  playRandMeasures(3);

  // 4e) play sec2_mid
  Serial.println("Middle of Section 4");
  playSection(sec2_mid, 32);

  // 4f) play random section 4f
  makeSignals();
  playRandMeasures(3);

  // 4g) play sec3_mid
  Serial.println("3rd Quarter of Section 4");
  playSection(sec3_mid, 32);

  // 4h) play random section 4h
  makeSignals();
  playRandMeasures(3);

  // 4i) play sec4_end
  Serial.println("End of Section 4");
  playSection(sec4_end, 32);
}
