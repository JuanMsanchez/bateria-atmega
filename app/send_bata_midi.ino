#include <SoftwareSerial.h>

const int note1 = 48; 
const int LEDpin1 = 4; 
const int umbral1 = 500; 
const int note2 = 50; 
const int LEDpin2 = 5; 
const int umbral2 = 500; 
const int note3 = 52; 
const int LEDpin3 = 6; 
const int umbral3 = 500; 
const int note4 = 53; 
const int LEDpin4 = 7; 
const int umbral4 = 500; 

//
int analogValue1 = 0; 
int velocity1 = 0; 
boolean stateMachine1 = false; 
int analogValue2 = 0; 
int velocity2 = 0; 
boolean stateMachine2 = false; 
int analogValue3 = 0; 
int velocity3 = 0; 
boolean stateMachine3 = false; 
int analogValue4 = 0; 
int velocity4 = 0; 
boolean stateMachine4 = false; 

SoftwareSerial midiSerial = SoftwareSerial(2, 3); 

void setup() {
  midiSerial.begin(31250); // inicialización del canal midi;
}

void loop() {
  analogValue1 = analogRead(A1);// leo el piezo
  analogValue2 = analogRead(A2);// leo el piezo
  analogValue3 = analogRead(A3);// leo el piezo
  analogValue4 = analogRead(A5);// leo el piezo


  velocity1 = analogValue1/8; //dimensiono la lectura a un valor de intensidad midi;
  velocity2 = analogValue2/8;
  velocity3 = analogValue3/8;
  velocity4 = analogValue4/8;


  if (analogValue1 > umbral1 && stateMachine1 == false)
  {
    noteOn(153, note1, velocity1);
    stateMachine1 = true;
  }
  else if (analogValue1 < umbral1 && stateMachine1 == true)
  {
    stateMachine1 = false;
  }
  else
  {
  }
  if (analogValue2 > umbral2 && stateMachine2 == false) 
  {
    noteOn(153, note2, velocity2);
    stateMachine2 = true;
  }
  else if (analogValue2 < umbral2 && stateMachine2 == true)
  {
    stateMachine2 = false;
  }
  else
  {
  }
  if (analogValue3 > umbral3 && stateMachine3 == false) 
  {
    noteOn(153, note3, velocity3);
    stateMachine3 = true;
  }
  else if (analogValue3 < umbral3 && stateMachine3 == true)
  {
    stateMachine3 = false;
  }
  else
  {
  }
  if (analogValue4 > umbral4 && stateMachine4 == false)
  {
    noteOn(153, note4, velocity4);
    stateMachine4 = true;
  }
  else if (analogValue4 < umbral4 && stateMachine4 == true)
  {
    stateMachine4 = false;
  }
  else 
  {
  }
}

void noteOn(byte cmd, byte data1, byte  data2) {
  midiSerial.write(cmd);
  midiSerial.write(data1);
  midiSerial.write(data2);
}
