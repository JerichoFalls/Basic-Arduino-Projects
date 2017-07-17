// Traffic Lights Program

// Define pins
const int westButton = 7;
const int eastButton = 13;
const int westRed = 6;
const int westYellow = 5;
const int westGreen = 4;
const int eastRed = 12;
const int eastYellow = 11;
const int eastGreen = 10;

int yellowBlinkTime = 0; // Time between blinks, ms
int yellowTime = 1000; // Time on yellow

boolean trafficWest = true; // West = True, East = False
int flowTime = 10000; // Time assigned for traffic flowTime
int changeDelay = 2000; // Time assigned for colour changes

void setup() {
  // Setup digital I/O
  pinMode(westButton, INPUT);
  pinMode(eastButton, INPUT);
  pinMode(westRed, OUTPUT);
  pinMode(westYellow, OUTPUT);
  pinMode(westGreen, OUTPUT);
  pinMode(eastRed, OUTPUT);
  pinMode(eastYellow, OUTPUT);
  pinMode(eastGreen, OUTPUT);

  // Assign initial light state, West green first
  digitalWrite(westRed, LOW);
  digitalWrite(westYellow, LOW);
  digitalWrite(westGreen, HIGH);
  digitalWrite(eastRed, HIGH);
  digitalWrite(eastYellow, LOW);
  digitalWrite(eastGreen, LOW);
}

void loop() {
  if (digitalRead(westButton) == HIGH) { // West to East flow has been requested
    if (trafficWest != true) { // Checks traffic direction isn't already for West
      trafficWest = true; // Change traffic flow direction
      delay(flowTime); // Time for traffic to flow
      digitalWrite(eastGreen, LOW); // Change east lights from green to yellow to red
      digitalWrite(eastYellow, HIGH);
      delay(changeDelay);
      digitalWrite(eastYellow, LOW);
      digitalWrite(eastRed, HIGH);
      delay(changeDelay);
      //for (int a=0; a<5; a++) { // Blinks yellow light for West to prepare for green
      //  digitalWrite(westYellow, LOW);
      //  delay(yellowBlinkTime);
      digitalWrite(westYellow, HIGH);
      delay(yellowTime);
      //  delay(yellowBlinkTime);
      //}
      digitalWrite(westYellow, LOW);
      digitalWrite(westRed, LOW);
      digitalWrite(westGreen, HIGH);
    }
  }
  if (digitalRead(eastButton) == HIGH) { // West to East flow has been requested
    if (trafficWest == true) { // Checks traffic direction isn't already for West
      trafficWest = false; // Change traffic flow direction
      delay(flowTime); // Time for traffic to flow
      digitalWrite(westGreen, LOW); // Change east lights from green to yellow to red
      digitalWrite(westYellow, HIGH);
      delay(changeDelay);
      digitalWrite(westYellow, LOW);
      digitalWrite(westRed, HIGH);
      delay(changeDelay);
      //for (int a=0; a<5; a++) { // Blinks yellow light for West to prepare for green
      //  digitalWrite(eastYellow, LOW);
      //  delay(yellowBlinkTime);
      digitalWrite(eastYellow, HIGH);
      delay(yellowTime);
      //  delay(yellowBlinkTime);
      //}
      digitalWrite(eastYellow, LOW);
      digitalWrite(eastRed, LOW);
      digitalWrite(eastGreen, HIGH);
    }
  }

}
