/*
Author: Isaiah Shriver
Class: ENGR103
Purpose: Interactive Game -- Press or Die
*/

// Background Information

  // Libraries
    #include <Adafruit_CircuitPlayground.h>
    #include <AsyncDelay.h>   
  // Libraries

  // Global Variables

      // Inputs

        // Buttons
          volatile bool RightFlag = 0;
          bool RightVal;
          volatile bool LeftFlag = 0;
          bool LeftVal;
        // Buttons

        // LightSensor
          int FlashLight = 700;
        // LightSensor

        // Switch
          volatile bool switchFlag = 0;
          bool switchVal = 0;
        // Switch

      // Inputs

      // AsyncDelay
        AsyncDelay delay_1s;
        AsyncDelay delay_2s;
        AsyncDelay delay_4s;
        AsyncDelay delay_5s;
        AsyncDelay delay_8s;
        AsyncDelay delay_9s;
      // AsyncDelay

      // Game
        int count;
        int Score;
      // Game

      // Thresholds
        // Level Thresholds
          int Level_0_Threshold = 0;
          int Level_1_Threshold;
          int Level_2_Threshold;
          int Level_3_Threshold;
          int Level_4_Threshold;
          int Level_5_Threshold;
        // Level Thresholds
      // Thresholds
  // Global Variables

// Background Information

// Loop and Setup

  void setup() {
    // Start
      Serial.begin(9600);
      CircuitPlayground.begin();
    // Start

    // Interrupts Button
      pinMode(5, INPUT_PULLDOWN);
      attachInterrupt(digitalPinToInterrupt(5), buttonright, RISING);
      pinMode(4, INPUT_PULLDOWN);
      attachInterrupt(digitalPinToInterrupt(4), buttonleft, RISING);
    // Interrupts Buttons  

    // Interrupt Switch
      pinMode(7, INPUT_PULLUP);
      attachInterrupt(digitalPinToInterrupt(7), onOff, CHANGE);
    // Interrupt Switch

    // AsyncDelay
      delay_1s.start(5000, AsyncDelay::MILLIS);
      delay_2s.start(10, AsyncDelay::MILLIS);
      delay_5s.start(5000, AsyncDelay::MILLIS);
      delay_8s.start(10000, AsyncDelay::MILLIS);
      delay_9s.start(20000, AsyncDelay::MILLIS);;
    // AsyncDelay

    // Level Thresholds
      Level_1_Threshold = 10;
      Level_2_Threshold = 20;
      Level_3_Threshold = -40;
      Level_4_Threshold = 30;
      Level_5_Threshold = 100;
    // Level Thresholds
  }
  
  void loop() {

    // LightSensor
     int LightReading = CircuitPlayground.lightSensor();
    // LightSensor

    // Game is on
      if (switchFlag) {
        delay(5);
        switchVal = digitalRead(7);
        delay_4s.start(10, AsyncDelay::MILLIS);
        switchFlag = 0;
      }
      if (delay_4s.isExpired() && !switchVal) {
        if (delay_9s.isExpired()) {
          Serial.println( "////////////////////////////////////////////////////////////////////////////////////////////////");
          Serial.println( "Thank You for Playing ButtonMasher2000 ");
          Serial.println( "Increase = right button, Decrease = left button, Reset = Flip switch and press both buttons");
          Serial.println( "To confirm your answer, flash your light at the cpx board");
          Serial.println( "It'll give you a new prompt so you can continuosuly button mash until you need a new board!");
          Serial.println( "The game isn't meant to be difficult or complex. It's supposed to be simple and peaceful to relive stress");
          Serial.println( "To begin confirm a count of 0");
          Serial.println( "////////////////////////////////////////////////////////////////////////////////////////////////");
          delay_9s.restart();
      }

      // Interrupts Buttons
        if (LeftFlag) {
          delay(5);
          LeftVal = digitalRead(4);
          count--;
          Serial.print( "The count is ");
          Serial.println(count);
          LeftFlag = 0;
        }

        if (RightFlag) {
          delay(5);
          RightVal = digitalRead(5);
          count++;
          Serial.print( "The count is ");
          Serial.println(count);
          RightFlag = 0;
        }
      // Interrupts Buttons

      // LightSensor
        if (LightReading > FlashLight) {
          if (delay_2s.isExpired()) {
           if (delay_1s.isExpired()) {
            if (count == Level_0_Threshold) {
              Serial.println( "///////////////////////////////////////////// ");
              Serial.println( "Confirming Answer");
              CorrectLight(50);
              CircuitPlayground.playTone(1000,100);
              CorrectLight(50);
              CircuitPlayground.playTone(1000,200);
              Score++;
              count = 0;
              Serial.print( "Total Score is ");
              Serial.print(Score);
              Serial.print( " out of 5 points. ");
              Serial.println( " ");
              Serial.println( "Starting Level 1. You need to reach ");
              Serial.print(Level_1_Threshold);
              Serial.println( "///////////////////////////////////////////// ");
              Serial.println( " ");
            }
            if (count == Level_1_Threshold) {
              Serial.println( "///////////////////////////////////////////// ");
              Serial.println( "Confirming Answer");
              CorrectLight(50);
              CircuitPlayground.playTone(1000,100);
              CorrectLight(50);
              CircuitPlayground.playTone(1000,200);
              Score++;
              count = 0;
              Serial.print( "Total Score is ");
              Serial.print(Score);
              Serial.print( " out of 5 points. ");
              Serial.println( " ");
              Serial.println( "Starting Level 2. You need to reach . ");
              Serial.print(Level_2_Threshold);
              Serial.println( ".");
              Serial.println( " ");
              Serial.println( "///////////////////////////////////////////// ");
              Serial.println( " ");
            }
            if (count == Level_2_Threshold) {
              Serial.println( "///////////////////////////////////////////// ");
              Serial.println( "Confirming Answer");
              CorrectLight(50);
              CircuitPlayground.playTone(1000,100);
              CorrectLight(50);
              CircuitPlayground.playTone(1000,200);
              Score++;
              count = 0;
              Serial.print( "Total Score is ");
              Serial.print(Score);
              Serial.print( " out of 5 points. ");
              Serial.println( " ");
              Serial.println( "Starting Level 3. You need to reach ");
              Serial.print(Level_3_Threshold);
              Serial.println( "///////////////////////////////////////////// ");
              Serial.println( " ");
            }
            if (count == Level_3_Threshold) {
              Serial.println( "///////////////////////////////////////////// ");
              Serial.println( "Confirming Answer");
              CorrectLight(50);
              CircuitPlayground.playTone(1000,100);
              CorrectLight(50);
              CircuitPlayground.playTone(1000,200);
              Score++;
              count = 0;
              Serial.print( "Total Score is ");
              Serial.print(Score);
              Serial.print( " out of 5 points. ");
              Serial.println( " ");
              Serial.println( "Starting Level 4. You need to reach ");
              Serial.print(Level_4_Threshold);
              Serial.println( "///////////////////////////////////////////// ");
              Serial.println( " ");
            }
            if (count == Level_4_Threshold) {
              Serial.println( "///////////////////////////////////////////// ");
              Serial.println( "Confirming Answer");
              CorrectLight(50);
              CircuitPlayground.playTone(1000,100);
              CorrectLight(50);
              CircuitPlayground.playTone(1000,200);
              Score++;
              count = 0;
              Serial.print( "Total Score is ");
              Serial.print(Score);
              Serial.print( " out of 5 points. ");
              Serial.println( " ");
              Serial.println( "Starting Level 5. You need to reach ");
              Serial.print(Level_5_Threshold);
              Serial.println( "///////////////////////////////////////////// ");
              Serial.println( " ");
            }
            if (count == Level_5_Threshold) {
              Serial.println( "/////////////////////////////////////////////  ");
              Serial.println( "Confirming Answer");
              CorrectLight(50);
              CircuitPlayground.playTone(1000,100);
              CorrectLight(50);
              CircuitPlayground.playTone(1000,200);
              Score++;
              count = 0;
              Serial.print( "Total Score is ");
              Serial.print(Score);
              Serial.print( " out of 5 points. ");
              Serial.println( " ");
              Serial.println( "End of Game. Your score is being calculated.");              
              Serial.println( "///////////////////////////////////////////// ");
              Serial.println( " ");
            }
            delay_1s.restart();
           }
           if (delay_5s.isExpired()) {
            if (count != Level_0_Threshold && count != Level_1_Threshold && count != Level_2_Threshold && count != Level_3_Threshold && count != Level_4_Threshold && count != Level_5_Threshold) {
              count = 0;
              Serial.println( "///////////////////////////////////////////// ");
              Serial.println( "Confirming Answer");
              ErrorLight(50);
              CircuitPlayground.playTone(100,100);
              ErrorLight(50);
              CircuitPlayground.playTone(100,100);
              Score--;
              Serial.print( "Total Score is ");
              Serial.print(Score);
              Serial.print( " out of 5 points. ");
              Serial.println( " ");
              Serial.println( "///////////////////////////////////////////// ");
              Serial.println( " ");
             }
             delay_5s.restart();
           }
            delay_2s.restart();
          } 
        } 
      // LightSensor
      }
    // Game is on

    // Game is OFF
        if (!switchFlag) {
          if (RightFlag && LeftFlag) {
            if (delay_8s.isExpired()) {
              ResetLight(50);
              Serial.println( "Reset in Order.");
              delay(5);
              Serial.println( "Count is set to Zero.");
              ResetLight(50);
              Serial.println( "Score is set to Zero.");
              Serial.println( "Flip the switch back on to begin!");
              ResetLight(50);
              Serial.println( "Good Luck!");
              count = 0;
              Score = 0;
              delay_8s.restart();
            }
          }
        }
    // Game is OFF

  }
    
// Loop and Setup

// Patterns
  // CorrectLight
    void CorrectLight(int period) {
            for (int i = 0; i < 10; i++) {
              CircuitPlayground.setPixelColor(i, 0, 255, 0);
              CircuitPlayground.clearPixels();
              delay(period/2);
              CircuitPlayground.setPixelColor(i, 0, 255, 0);
              CircuitPlayground.clearPixels();
              delay(period/2);
              CircuitPlayground.setPixelColor(i, 0, 255, 0);
              CircuitPlayground.clearPixels();
            }
    }
  // CorrectLight

  // ErrorLight
    void ErrorLight(int period) {
            for (int i = 0; i < 10; i++) {
              CircuitPlayground.setPixelColor(i, 255, 0, 0);
              CircuitPlayground.clearPixels();
              delay(period/2);
              CircuitPlayground.setPixelColor(i, 255, 0, 0);
              CircuitPlayground.clearPixels();
              delay(period/2);
              CircuitPlayground.setPixelColor(i, 255, 0, 0);
              CircuitPlayground.clearPixels();
            }
    }
  // ErrorLight

  // ResetLight
    void ResetLight(int period) {
            for (int i = 0; i < 10; i++) {
              CircuitPlayground.setPixelColor(i, 0, 0, 255);
              CircuitPlayground.clearPixels();
              delay(period/2);
              CircuitPlayground.setPixelColor(i, 0, 0, 255);
              CircuitPlayground.clearPixels();
              delay(period/2);
              CircuitPlayground.setPixelColor(i, 0, 0, 255);
              CircuitPlayground.clearPixels();
            }
    }
  // ResetLight
// Patterns

// ISRs

  void onOff() {
    switchFlag = 1;
  }

  void buttonright() {
    RightFlag = 1;
  }

  void buttonleft() {
    LeftFlag = 1;
  }

// ISRs

