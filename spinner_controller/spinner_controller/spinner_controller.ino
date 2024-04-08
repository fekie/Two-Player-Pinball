const int blueFan = 6;
const int redFan = 5;
const int spinner = 4;

void setup() {
  pinMode(blueFan, OUTPUT);
  pinMode(redFan, OUTPUT);
  //pinMode(spinner, OUTPUT);
  delay(1000);

  // We keep the spinner spinning for the entire time the machine is on.
  
}

void loop() {
  //digitalWrite(spinner, HIGH);
  // Turn on fans
  digitalWrite(blueFan, HIGH);
  digitalWrite(redFan, HIGH);
  delay(3000);
  
  digitalWrite(blueFan, LOW);
  digitalWrite(redFan, HIGH);
  delay(3000);
}