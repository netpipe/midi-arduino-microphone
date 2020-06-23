/*
   Bas on Tech
   This course is part of the courses on https://arduino-tutorials.net
   (c) Copyright 2020 - Bas van Dijk / Bas on Tech
   This code and course is copyrighted. It is not allowed to use these courses commercially
   without explicit written approval
   YouTube:    https://www.youtube.com/c/BasOnTech
   Facebook:   https://www.facebook.com/BasOnTechChannel
   Instagram:  https://www.instagram.com/BasOnTech
   Twitter:    https://twitter.com/BasOnTech
   
*/

//using microphone arduino module the blue one

const int OUT_PIN = 8;
const int SAMPLE_TIME = 50;
unsigned long millisCurrent;
unsigned long millisLast = 0;
unsigned long millisElapsed = 0;

const int OUT_PIN1 = 7;
const int OUT_PIN2 = 7;
const int OUT_PIN3 = 7;
const int OUT_PIN4 = 7;
const int OUT_PIN5 = 7;

const int threshold1 = 50;
const int threshold2 = 700;
const int threshold3 = 1500;

// if loud then residual dont count them knock3

int sampleBufferValue = 0;
int sampleBufferValue1 = 0;
int sampleBufferValue2 = 0;
int sampleBufferValue3 = 0;
int sampleBufferValue4 = 0;
int sampleBufferValue5 = 0;


void setup() {
  Serial.begin(9600);
}

int count=0;
int count2=0;


void loop() {

  millisCurrent = millis();
  millisElapsed = millisCurrent - millisLast;

  if (digitalRead(OUT_PIN) == LOW) {
    sampleBufferValue++;
  }
  
  if (digitalRead(OUT_PIN1) == LOW) {
    sampleBufferValue1++;
  }

  if (digitalRead(OUT_PIN2) == LOW) {
    sampleBufferValue2++;
  }

  if (digitalRead(OUT_PIN3) == LOW) {
    sampleBufferValue3++;
  }

  if (digitalRead(OUT_PIN4) == LOW) {
    sampleBufferValue4++;
  }
  if (digitalRead(OUT_PIN5) == LOW) {
    sampleBufferValue5++;
  }

  if (millisElapsed > SAMPLE_TIME) {
    // start processing loop

    
    if (sampleBufferValue > 0){
    //Serial.println(sampleBufferValue);
    
    if (sampleBufferValue >= threshold1) 
   {
        Serial.println(sampleBufferValue);
        count++;
            Serial.println(count);
            Serial.println("Knock1!");
      if (sampleBufferValue >= threshold2) 
       {
            Serial.println("Knock2!");
          if (sampleBufferValue >= threshold3) 
          {
            Serial.println("Knock3!");
          }
        }
   }
   }

  if (sampleBufferValue1 > 0){
  //  Serial.println(sampleBufferValue);
    if (sampleBufferValue1 <= threshold1) 
    {
    Serial.println(sampleBufferValue1);
    count2++;
    Serial.println(count2);
    Serial.println("Knock1!");
    
     if (sampleBufferValue1 >= threshold2) 
       {
        
            Serial.println("Knock2!");
        if (sampleBufferValue1 >= threshold3) 
        {
            Serial.println("Knock3!");
        }
      }
     }
    }

    
  if (sampleBufferValue2 > 0){
  //  Serial.println(sampleBufferValue);
    if (sampleBufferValue1 <= threshold1) 
    {
    Serial.println(sampleBufferValue2);
    count2++;
    Serial.println(count2);
    Serial.println("Knock1!");
    
     if (sampleBufferValue2 >= threshold2) 
       {
        
            Serial.println("Knock2!");
        if (sampleBufferValue2 >= threshold3) 
        {
            Serial.println("Knock3!");
        }
      }
     }
    }

  if (sampleBufferValue3 > 0){
  //  Serial.println(sampleBufferValue);
    if (sampleBufferValue3 <= threshold1) 
    {
    Serial.println(sampleBufferValue3);
    count2++;
    Serial.println(count2);
    Serial.println("Knock1!");
    
     if (sampleBufferValue3 >= threshold2) 
       {
        
            Serial.println("Knock2!");
        if (sampleBufferValue3 >= threshold3) 
        {
            Serial.println("Knock3!");
        }
      }
     }
    }

  if (sampleBufferValue4 > 0){
  //  Serial.println(sampleBufferValue);
    if (sampleBufferValue4 <= threshold1) 
    {
    Serial.println(sampleBufferValue4);
    count2++;
    Serial.println(count2);
    Serial.println("Knock1!");
    
     if (sampleBufferValue4 >= threshold2) 
       {
        
            Serial.println("Knock2!");
        if (sampleBufferValue3 >= threshold3) 
        {
            Serial.println("Knock3!");
        }
      }
     }
    }

      if (sampleBufferValue5 > 0){
  //  Serial.println(sampleBufferValue);
    if (sampleBufferValue5 <= threshold1) 
    {
    Serial.println(sampleBufferValue5);
    count2++;
    Serial.println(count2);
    Serial.println("Knock1!");
    
     if (sampleBufferValue5 >= threshold2) 
       {
        
            Serial.println("Knock2!");
        if (sampleBufferValue5 >= threshold3) 
        {
            Serial.println("Knock3!");
        }
      }
     }
    }
    
    
  }

  if (millisElapsed > SAMPLE_TIME) {
    sampleBufferValue = 0;
    millisLast = millisCurrent;
  }
  

  
}

void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}
