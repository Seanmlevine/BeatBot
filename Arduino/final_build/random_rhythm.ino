/*
   Random rhythm generator. Adapted from source.
   Author: allexks
   Source: https://github.com/allexks/RandomRhythm

   Required hardware and circuit setup:
   Speaker attached to pin 9
   Button attached to pin 12
*/

// Speaker
//const int speaker = 9; //pin

// Button
// While the button is pressed, the rhythm plays through the speaker
//int buttonPin = 12;
//int buttonState = 0; //1 means pressed; 0 means not pressed

//int ledState = HIGH;
//int ledPin = 13;

/* Can't use because needs to be constant. Just let it be the smallest subdivision always.*/
// Udpates the minimum subdivision note length and signal lengths
//void setMinNoteLength(int index) {
//  minNoteLength = index;  // Make 5 to include 32nd notes
//  minSignalLength = pow(2, minNoteLength);
//}

// Updates the tempo and all related time measurements
void setTempo(int tempo) {
  bpm = tempo;
  beatTime = 60000 / bpm; // time of 1 beat in milliseconds
  beatTimeMinNote = beatTime * beats / pow(2, minNoteLength);
}

// Updates the random weights for generating a type of note; will normalize weights that do not add up to 100
void setNoteWeights(float one, float two, float four, float eight, float sixteen, float thirtytwo) {
  float total = one + two + four + eight + sixteen + thirtytwo;
  
  wholeNoteChance = one / total * 100.0;
  halfNoteChance = two / total * 100.0;
  quarterNoteChance = four / total * 100.0;
  eighthNoteChance = eight / total * 100.0;
  sixteenthNoteChance = sixteen / total * 100.0;
  thirtysecondNoteChance = thirtytwo / total * 100.0;
}

bool randChance(int chance) {
  int r = random(1, 101);
  return (chance >= r);
}

// Random note length based on the current set % for each note
int randNote() {
  int r = random(1, 101);

  if (r < wholeNoteChance) {
    return 0;
  } else if (r < wholeNoteChance+halfNoteChance) {
    return 1;
  } else if (r < wholeNoteChance+halfNoteChance+quarterNoteChance) {
    return 2;
  } else if (r < wholeNoteChance+halfNoteChance+quarterNoteChance+eighthNoteChance) {
    return 3;
  } else if (r < wholeNoteChance+halfNoteChance+quarterNoteChance+eighthNoteChance+sixteenthNoteChance) {
    return 4;
  } else {
    return 5;
  }
}

bool makeRhythm(int Measure[]) {

  //vars
  bool rhythmReady = false; // shows whether we have successfully generated the rhythm
  //int Measure[33]; // will hold the notes (their lengths in beatsx1000)

  while (rhythmReady == false) {
    int timeLeft = beats * 1000;
    int noteNum = 0;

    while (timeLeft > 0) {
      // NEW NOTE

      // What type of note?
      int lengthn = noteLen[randNote()]; //holds length of current note
//      if (lengthn == noteLen[0] && randChance(overrideChance)) lengthn = noteLen[2];  // % chance whole-notes will become half-notes
      if (timeLeft < lengthn) continue;

      // Pause or tone?
      bool isPause = randChance(pauseChance);

//      // Triplet sequence?
//      int tripletNotesLeft = 0;
//      bool TripletMode = false;
//
//      if ((2 * lengthn) % 1000 == 0 && timeLeft >= 2 * lengthn) {
//        TripletMode = randChance(tripletChance);
//      }
//      if (TripletMode) tripletNotesLeft = 3;
//
//      while (tripletNotesLeft > 0) {
//        isPause = randChance(pauseInSequenceChance);
//
//        int newLength = (int)(lengthn * (2.0 / 3));
//
//        if (isPause) {
//          Measure[noteNum] = -newLength; // if it's a pause, we make it negative
//        } else {
//          Measure[noteNum] = newLength;
//        }
//        noteNum += 1;
//        tripletNotesLeft -= 1;
//      }
//
//      if (TripletMode) {
//        timeLeft -= 2 * lengthn; // clears out the time of all 3 triplets at once
//        continue;
//      }
//      TripletMode = false;

      // Dotted?
//      bool singleDot = randChance(singledotChance);
//      bool doubleDot = randChance(doubledotChance);
//      if (singleDot && doubleDot) doubleDot = false; // single-dotted note trumps double-dotted
//
//      if (singleDot) {
//        if (lengthn < noteLen[3]) continue;
//        lengthn *= 1.5;
//        if (timeLeft < lengthn) continue;
//      } else if (doubleDot) {
//        if (lengthn < noteLen[2]) continue;
//        lengthn *= 1.75;
//        if (timeLeft < lengthn) continue;
//      }

      // Finally, adding the note!
      timeLeft -= lengthn;
      if (isPause) {
        Measure[noteNum] = -lengthn;
        // if it's a pause, it is stored as a negative number
      } else {
        Measure[noteNum] = lengthn;
      }
//      Serial.println(Measure[noteNum]);
      noteNum += 1;
    }

    Measure[noteNum] = 0; // will mark the end of the measure
    rhythmReady = true; // now we are ready to move on to the second part
  }


  // Second part of the process (playing the rhythm):

//  while (rhythmReady) {
//    Serial.println(' ');
//    int sum = 0; //for debug purposes only
//
//    int currentNote = 0;
//    bool firstNoteNotPlayed = true;
//    unsigned long previousMillis = 1; //updates each note
//    unsigned long previousBeatMillis = millis(); //updates each beat
//
//    while (buttonState == 1) {
//
//      unsigned long int duration = abs(Measure[currentNote]) * beatTime / 1000; //ms
//      unsigned long currentMillis = millis();
//
//      if (currentMillis - previousMillis >= duration || firstNoteNotPlayed) {
//        // PLAYS NEXT NOTE OF THE MEASURE
//        noTone(speaker);
//
//        if (!firstNoteNotPlayed) {
//          currentNote += 1;
//        } else {
//          firstNoteNotPlayed = false;
//          // marks the first beat
//          digitalWrite(ledPin, HIGH);
//          Serial.println("BEAT");
//          previousBeatMillis = currentMillis;
//        }
//
//        if (Measure[currentNote] == 0) {
//          buttonState = 0;
//          digitalWrite(ledPin, LOW);
//          previousBeatMillis = currentMillis;
//          break;
//        }
//
//        Serial.println(Measure[currentNote]);
//        Serial.println(currentNote);
//
//        //digitalWrite(ledPin, ledState%2); // change with each note
//        //ledState += 1;
//
//        //Serial.print(int(Measure[currentNote]));
//        sum += abs(Measure[currentNote]);
//        //Serial.print(' ');
//
//        int note = 0;
//        if (Measure[currentNote] > 0) {
//          //if note is not a pause
//          if (currentNote == 0) {
//            note = 440; //A4
//          } else {
//            note = 394; //G4
//          }
//        }
//
//        tone(speaker, note, abs(Measure[currentNote]) * beatTime / 1000);
//        
//        previousMillis = currentMillis;
//      }
//
//
//      if (currentMillis - previousBeatMillis >= (long)beatTime) {
//        // CHANGES THE STATE OF THE LED ON EACH BEAT LIKE A METRONOME
//        
//        digitalWrite(ledPin, !digitalRead(ledPin));
//        Serial.println("BEAT");
//        previousBeatMillis = currentMillis;
//      }
//    }
//
//    Serial.print(" = ");
//    Serial.println(sum);
//
//
//    while (buttonState == 0) {
//      //Sets the playback in a paused state until the button is pressed
//      if (digitalRead(buttonPin) == LOW) {
//        buttonState = 1;
//      }
//    }
//  }
  return rhythmReady;
}
