// Basic Car Functionality Program

// Define pins
const int lDip = 3; //Left & right dipped beam
const int rDip = 4;
const int lLight = 2; //Left & right full beam
const int rLight = 5;
const int lInd = 6; //Left indicator light
const int rInd = 7; //Right indicator light
const int lBrake = 8; //Left & right brake light
const int rBrake = 9;
const int btn1 = 10; //Button 1 - for dipped beam on
const int btn2 = 11; //Button 2 - for full beam on
const int btn3 = 12; //Button 3 - for left indicator
const int btn4 = 13; //Button 4 - for right indicator
const int btn5 = 14; //Button 5 - for brake lights
const int btn6 = 15; //Button 6

// Define variables
int indFlashInterval = 2000; //Time for static activation of indicator
boolean lIndOn = false;
boolean rIndOn = false;
boolean dipOn = false;
boolean lightOn = false;
int setupLightInterval = 1000; //Time for lights on at setup

// Board setup loop
void setup() {
  // Setup digital I/O
  pinMode(lDip, OUTPUT);
  pinMode(rDip, OUTPUT);
  pinMode(lLight, OUTPUT);
  pinMode(rLight, OUTPUT);
  pinMode(lInd, OUTPUT);
  pinMode(rInd, OUTPUT);
  pinMode(lBrake, OUTPUT);
  pinMode(rBrake, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
  //pinMode(btn5, INPUT);

  digitalWrite(lInd, HIGH);
  digitalWrite(rInd, HIGH);
  delay(setupLightInterval);
  digitalWrite(lInd, LOW);
  digitalWrite(rInd, LOW);
}

// Main board loop
void loop() {
  if (digitalRead(btn1) == HIGH) { //Dipped beam on
    if (dipOn == true) {
      digitalWrite(lDip, LOW);
      digitalWrite(rDip, LOW);
      dipOn = false;
    } else {
      digitalWrite(lDip, HIGH);
      digitalWrite(rDip, HIGH);
      dipOn = true;
    }
  }
  if (digitalRead(btn2) == HIGH) {
    if (dipOn == true) {
      //Can have full beam activated
      if (lightOn == true) {
        digitalWrite(lLight, LOW);
        digitalWrite(rLight, LOW);
        lightOn = false;
      } else {
        digitalWrite(lLight, HIGH);
        digitalWrite(rLight, HIGH);
        lightOn = true;
      }
    } //else {
    //  digitalWrite(lLight, HIGH);
      //digitalWrite(rLight, HIGH);
      //delay(indFlashInterval);
      //digitalWrite(lLight, LOW);
      //digitalWrite(rLight, LOW);
    //}
  }
  if (lIndOn == true) {
    //Indicator is on
  }
  if (digitalRead(btn3) == HIGH) {
    // Left indicator triggered

  }

}
