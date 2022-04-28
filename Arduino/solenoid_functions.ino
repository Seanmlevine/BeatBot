// One single hit of a solenoid based on the beat time
void hitOnBeat(float beat_time, int pin, bool use_delay) {
  digitalWrite(pin, HIGH); // switch solenoid ON
  delay(20);
  digitalWrite(pin, LOW); // switch solenoid OFF
  if(use_delay) {
    delay(beat_time);
  }
}

// Read in a 4-item list and actuate the solenoids as appropriate
void readHit(int sig0, int sig1, int sig2, int sig3) {
  digitalWrite(SOLENOID_0, sig0);
  digitalWrite(SOLENOID_1, sig1);
  digitalWrite(SOLENOID_2, sig2);
  digitalWrite(SOLENOID_3, sig3);

  delay(10);
  allLow();
}

// Sets all solenoids to LOW (off)
void allLow() {
  digitalWrite(SOLENOID_0, LOW);
  digitalWrite(SOLENOID_1, LOW);
  digitalWrite(SOLENOID_2, LOW);
  digitalWrite(SOLENOID_3, LOW);
}

void makeSignals() {
  // 1) Make rhythms for each solenoid
  makeRhythm(r0);
  makeRhythm(r1);
  makeRhythm(r2);
  makeRhythm(r3);

  // 2) Turn rhythm into signals
  // R0
  int sigIndex = 0;
  for (int i = 0; i < sizeof(r0); i++) // Loop through rhythm list
  {
    if (r0[i] == 0) break;
    
    if (r0[i] < 0)
    {
      genSignals[sigIndex][0] = 0;
    } else {
      genSignals[sigIndex][0] = 1;
    }
    sigIndex++;
    
    int dur = abs(r0[i]) / noteLen[maxNoteLength-1];
    
    for (int j = 0; j < dur-1; j++) {
      //Serial.print(sigIndex);
      genSignals[sigIndex][0] = 0;
      sigIndex++;
    }
  }

  // R1
  sigIndex = 0;
  for (int i = 0; i < sizeof(r1); i++) // Loop through rhythm list
  {
    if (r1[i] == 0) break;
    
    if (r1[i] < 0)
    {
      genSignals[sigIndex][1] = 0;
    } else {
      genSignals[sigIndex][1] = 1;
    }
    sigIndex++;
    
    int dur = abs(r1[i]) / noteLen[maxNoteLength-1];
    
    for (int j = 0; j < dur-1; j++) {
      //Serial.print(sigIndex);
      genSignals[sigIndex][1] = 0;
      sigIndex++;
    }
  }

  // R2
  sigIndex = 0;
  for (int i = 0; i < sizeof(r2); i++) // Loop through rhythm list
  {
    if (r2[i] == 0) break;
    
    if (r2[i] < 0)
    {
      genSignals[sigIndex][2] = 0;
    } else {
      genSignals[sigIndex][2] = 1;
    }
    sigIndex++;
    
    int dur = abs(r2[i]) / noteLen[maxNoteLength-1];
    
    for (int j = 0; j < dur-1; j++) {
      //Serial.print(sigIndex);
      genSignals[sigIndex][2] = 0;
      sigIndex++;
    }
  }

  // R3
  sigIndex = 0;
  for (int i = 0; i < sizeof(r3); i++) // Loop through rhythm list
  {
    if (r3[i] == 0) break;
    
    if (r3[i] < 0)
    {
      genSignals[sigIndex][3] = 0;
    } else {
      genSignals[sigIndex][3] = 1;
    }
    sigIndex++;
    
    int dur = abs(r3[i]) / noteLen[maxNoteLength-1];
    
    for (int j = 0; j < dur-1; j++) {
      //Serial.print(sigIndex);
      genSignals[sigIndex][3] = 0;
      sigIndex++;
    }
  }

  for (int j = 0; j < 4; j++)
  {
    for (int i = 0; i < maxSignalLength; i++)
    {
      Serial.print(genSignals[i][j]);
    }
    Serial.println(' ');
  }
  Serial.println(' ');
}
