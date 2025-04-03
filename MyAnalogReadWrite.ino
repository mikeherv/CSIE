/*
  Excersise: Read the analog value from A0
  map it with the map function to normalize it to 8 bit 
  0-255 then do the analogWrite (PWM) and analyze the behavior in the scope. 
*/

// These constants won't change. They're used to give names to the pins used:
const int lowestPin = 2;
const int highestPin = 3;
const int analogInPin = A0;

int sensorValue =0;
int outputValue =0;

void setup() {
 
 Serial.begin(9600);
  
  // set pins 2 through 13 as outputs:
  for (int thisPin = lowestPin; thisPin <= highestPin; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void loop() {

  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1023, 0, 255);

  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.print(outputValue);
  Serial.print("\n");
  // iterate over the pins:
  for (int thisPin = lowestPin; thisPin <= highestPin; thisPin++) {
    // fade the LED on thisPin from off to brightest:
    for (int brightness = 0; brightness < outputValue; brightness++) {
      analogWrite(thisPin, brightness);
      delay(2);
    }
    // fade the LED on thisPin from brightest to off:
    for (int brightness = outputValue; brightness >= 0; brightness--) {
      analogWrite(thisPin, brightness);
      delay(2);
    }
    // pause between LEDs:
    delay(100);
  }
}
