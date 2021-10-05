#include <Servo.h>

Servo myservo;

//10 is ongeveer haaks     -> Top: Open   Bodem: Dicht   Naam: Open
//105 is ongeveer parallel -> Top: Dicht  Bodem: Open    Naam: Closed

int pos = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pos = myservo.read();
  delay(1000);
}


char rx_byte = 0;

void loop() {
  if (Serial.available() > 0) {
    rx_byte = Serial.read();
    Serial.print("Input received: ");
    Serial.println(rx_byte);
    if (rx_byte == 't') {
      Top();
    } else if (rx_byte == 'b') {
      Bottom();
    } else if (rx_byte == 'r') {
      Serial.print("Current rotation: ");
      Serial.println(myservo.read());
    }
  }
  delay(100); //Already tried removing this line, didn't work
}

void Top() {
  Serial.println("Opening Top...");
  while (myservo.read() > 10) { //adding short delays in this loop also doesn't work
    pos--;
    myservo.write(pos);
  }
  Serial.println("Top Opened");
}

void Bottom() {
  Serial.println("Opening Bottom...");
  while (myservo.read() < 110) { //adding short delays in this loop also doesn't work
    pos++;
    myservo.write(pos);
  }
  Serial.println("Bottom Opened");
}
