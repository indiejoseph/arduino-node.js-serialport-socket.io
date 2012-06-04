const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

int sensorValue = 0;        // value read from the pot
int prevsensorValue = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);

  // If the previous value is the same as the new one, the do not send to save
  // communication link between the Arduino and the PC. 
  if (prevsensorValue != sensorValue) {
    // print the results to the serial monitor:
    Serial.print("A"); // Print the letter A to signal the beginning of an Input
    Serial.print(sensorValue); // Send the sensor Value (this is an integer)
    Serial.print("B"); // Print the letter B to signal the end of an Input
    prevsensorValue = sensorValue; // Change the previous sensor value
  }
  // wait 100 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading. If you are sending too fast
  // there is also a tendency to flood the communication line.
  delay(100);                     
}
