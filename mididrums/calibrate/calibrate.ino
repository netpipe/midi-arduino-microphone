

const int OUT_PIN = 3;
const int OUT_PIN1 = 0;
const int OUT_PIN2 = 1;
const int OUT_PIN3 = 1;
const int OUT_PIN4 = 1;
const int OUT_PIN5 = 1;


//to calibrate get hits over 10 thresh and  average them together for 1



////leonardo
//const int sampleWindow = 28; // Sample window width in mS (50 mS = 20Hz)
//const int threshold1 = 22;    // 350 higher value for larger sample window
//const int threshold2 = 140;
////const int threshold4 = 140; 
//const int threshold3 = 300; //rename to 4 after


//for arduino nano
const int sampleWindow = 25; // Sample window width in mS (50 mS = 20Hz)
const int threshold1 = 5;    // 350 higher value for larger sample window
const int threshold2 = 90;
const int threshold4 = 140; 
const int threshold3 = 200; //rename to 4 after

int samplebuffer = 0;

int count = 0;
int count2 = 0;
int countavg = 0;

unsigned long startMillis;
long elapsedmilis = 0;


int hits;
int hits1;
int hits2;

byte note = 0;

#define MIDI_ON 144
#define MIDI_OFF 128

int avg;
int avgnum;

int channel=0;
char status = 0;


void setup() {
    Serial.begin(9600);
}

void PrintCount(){
           count++;
         Serial.println(count);      
}

void loop() {
  
  startMillis = millis(); // Start of sample window
  while (elapsedmilis < sampleWindow)
  {
    if (digitalRead(OUT_PIN) < 1) {
      samplebuffer++;
    }
        elapsedmilis = millis() - startMillis;
  }
  
    if (samplebuffer >= threshold1)
    {
      avgnum += samplebuffer;
      PrintCount();
      countavg++;
      Serial.println(avgnum/countavg);
    }

  //  PrintCount();
    
  samplebuffer = 0;
//  samplebuffer1 = 0;
//  samplebuffer2 = 0;
//  samplebuffer3 = 0;
//  samplebuffer4 = 0;
//  samplebuffer5 = 0;

  elapsedmilis = 0;

  delay(1);

}
    
