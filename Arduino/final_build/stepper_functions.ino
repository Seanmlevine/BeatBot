// Keep track of current position (row 1, 2, 3, 4, etc.)
// Use MIDI Channel 2 for Stepper motor movement


// Updated Stepper functions

// All of these are included in final_build

//#include <Stepper.h>
//
//const int stepsPerRevolution = 5000;  // actual = 200 (microstep) 
//const int STEP_SIZE =  5000;
//

//const int stepsPerRevolution = 5000;  // actual = 200 (microstep) 
//const int STEP_SIZE =  5000;
Stepper stepperY(stepsPerRevolution, 2, 3);
Stepper stepperX(stepsPerRevolution, 4, 5);


// Move row, single position change
// @param CURR_ROW - The current row
// @param NEXT_ROW - The target row 
// @returns CURR_ROW - the current row
int changeRow(int CURR_ROW, int NEXT_ROW){

//  int STEP_SIZE = 5000;
  stepperY.setSpeed(200);
  int STEP = abs(NEXT_ROW - CURR_ROW);
    if(CURR_ROW == NEXT_ROW) {
    } else if(CURR_ROW < NEXT_ROW) {
        Serial.println("forward:" + STEP);
        stepperY.step(STEP*STEP_SIZE);
        CURR_ROW = NEXT_ROW;
        delay(20);
        
    } else {
        Serial.println("back:" + STEP);
        stepperY.step(-(STEP*STEP_SIZE));
        CURR_ROW = NEXT_ROW;
        delay(20);
    }

    return CURR_ROW;
  }


int moveRow(int CURR_ROW, int NEXT_ROW) {
   Serial.print(NEXT_ROW);
    Serial.print('\n');
    delay(20);
    int STEP = abs(NEXT_ROW - CURR_ROW);
    if(CURR_ROW != NEXT_ROW) {
      if(CURR_ROW < NEXT_ROW) {
        Serial.println("forward:" + STEP);
        stepperY.step(STEP*STEP_SIZE);
        CURR_ROW = NEXT_ROW;
        delay(20);
        
      } else {
         Serial.println("back:" + STEP);
          stepperY.step(-(STEP*STEP_SIZE));
          CURR_ROW = NEXT_ROW;
          delay(20);
      }
    }

   return CURR_ROW;
}

// Move rows, array or positions up to 10
// @param positions - array of row positions 
// @returns CURR_ROW - the current row
int moveRows(uint8_t positions[10], int CURR_ROW) {
  for (byte i = 0; i < 11; i = i + 1) {
    int NEXT_ROW = positions[i];
    Serial.print(NEXT_ROW);
    Serial.print('\n');
    delay(500);
    int STEP = abs(NEXT_ROW - CURR_ROW);
    if(CURR_ROW == NEXT_ROW) {
      continue;
    } else if(CURR_ROW < NEXT_ROW) {
        Serial.println("forward:" + STEP);
        stepperX.step(STEP*STEP_SIZE);
        CURR_ROW = NEXT_ROW;
        delay(500);
        
    } else {
       Serial.println("back:" + STEP);
        stepperX.step(-(STEP*STEP_SIZE));
        CURR_ROW = NEXT_ROW;
        delay(500);
    }
  }
  
  return CURR_ROW;
}

// Move column, single position change
// @param CURR_COL - The current column
// @param NEXT_COL - The target column 
// @returns CURR_COL - the current column
int moveCol(int CURR_COL, int NEXT_COL) {
   Serial.print(NEXT_COL);
    Serial.print('\n');
    delay(500);
    int STEP = abs(NEXT_COL - CURR_COL);
    if(CURR_COL != NEXT_COL) {
      if(CURR_COL < NEXT_COL) {
          Serial.println("forward:" + STEP);
          stepperY.step(STEP*STEP_SIZE);
          CURR_COL = NEXT_COL;
          delay(500);
          
      } else {
         Serial.println("back:" + STEP);
          stepperY.step(-(STEP*STEP_SIZE));
          CURR_COL = NEXT_COL;
          delay(500);
      }
    }
    
   return CURR_COL;
}

// Move columns, array or positions up to 10
// @param positions - array of column positions 
// @returns CURR_COL - the current column
//int moveCols(uint8_t positions[], int CURR_COL) {
// // size_t movements = sizeof(positions)/sizeof(positions[0]);
//  for (byte i = 0; i < 11; i = i + 1) {
//    int NEXT_COL = positions[i];
//    Serial.print(NEXT_COL);
//    Serial.print('\n');
//    delay(500);
//    int STEP = abs(NEXT_COL - CURR_COL);
//    if(CURR_COL == NEXT_COL) {
//      continue;
//    } else if(CURR_COL < NEXT_COL) {
//        Serial.println("forward:" + STEP);
//        stepperY.step(STEP*STEP_SIZE);
//        CURR_COL = NEXT_COL;
//        delay(500);
//        
//    } else {
//       Serial.println("back:" + STEP);
//        stepperY.step(-(STEP*STEP_SIZE));
//        CURR_COL = NEXT_COL;
//        delay(500);
//    }
//  }
//
//  return CURR_COL;
//}


// Move # of steps in x direction
// @param steps - number of steps (rows or columns [0,3])
// @param dir - Direction of movement (1 - Y positive, -1 - Y negative, 2 - X Positive, -2 - X Negative) 
// @returns CURR_POS {x,y}
//vector<int> move(int steps, int dir) {
//  switch (dir) {
//    case 1:
//      // Y positive
//      stepperY.step(steps);
//      // getXY()
//      break;
//    case -1:
//      // Y negative
//      stepperY.step(-steps);
//      // getXY()
//      break;
//    case 2:
//      // X positive
//      stepperX.step(steps);
//      // getXY()
//      break;
//    case -2:
//      // X negative
//      stepperX.step(-steps);
//      // getXY()
//      break;
//    default:
//      Serial.print("Invalid Position");
//      break;
//  }

//  return;
//}

// =============================================================================
//Move in the X-direction
//void moveX(uint8_t dirSig, int stepsPerRev, int speedMicroSec) {
//  // Set motor direction: HIGH for clockwise, LOW for counterclockwise
//  digitalWrite(DIR_PIN_X, dirSig);
// 
//  // Spin motor quickly
//  for(int x = 0; x < stepsPerRev; x++)
//  {
//    digitalWrite(STEP_PIN_X, HIGH);
//    delayMicroseconds(speedMicroSec);
//    digitalWrite(STEP_PIN_X, LOW);
//    delayMicroseconds(speedMicroSec);
//  }
//}
//
//// Move in the Y-direction
//void moveY(uint8_t dirSig, int stepsPerRev, int speedMicroSec) {
//  // Set motor direction: HIGH for clockwise, LOW for counterclockwise
//  digitalWrite(DIR_PIN_Y, dirSig);
// 
//  // Spin motor quickly
//  for(int x = 0; x < stepsPerRev; x++)
//  {
//    digitalWrite(STEP_PIN_Y, HIGH);
//    delayMicroseconds(speedMicroSec);
//    digitalWrite(STEP_PIN_Y, LOW);
//    delayMicroseconds(speedMicroSec);
//  }
//}



////Move in the X-direction
//void moveX(uint8_t dirSig, int stepsPerRev, int speedMicroSec) {
//  // Set motor direction: HIGH for clockwise, LOW for counterclockwise
//  digitalWrite(DIR_PIN_X, dirSig);
// 
//  // Spin motor quickly
//  for(int x = 0; x < stepsPerRev; x++)
//  {
//    digitalWrite(STEP_PIN_X, HIGH);
//    delayMicroseconds(speedMicroSec);
//    digitalWrite(STEP_PIN_X, LOW);
//    delayMicroseconds(speedMicroSec);
//  }
//}
//
//// Move in the Y-direction
//void moveY(uint8_t dirSig, int stepsPerRev, int speedMicroSec) {
//  // Set motor direction: HIGH for clockwise, LOW for counterclockwise
//  digitalWrite(DIR_PIN_Y, dirSig);
// 
//  // Spin motor quickly
//  for(int x = 0; x < stepsPerRev; x++)
//  {
//    digitalWrite(STEP_PIN_Y, HIGH);
//    delayMicroseconds(speedMicroSec);
//    digitalWrite(STEP_PIN_Y, LOW);
//    delayMicroseconds(speedMicroSec);
//  }
//}
