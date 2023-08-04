
#include <nRF24L01.h> // nrf library moment
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

#include <Servo.h>

RF24 radio(9, 10); // CE, CSN pins
const byte address[6] = "00001";

int little, ring, middle, index, thumb;

void setup() 
{
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);

  Serial.begin(9600);

}

void loop() 
{
  little = analogRead(A0);
  ring = analogRead(A1);
  middle = analogRead(A2);
  index = analogRead(A3);
  thumb = analogRead(A4);

int data[5];
data[0] = map(little, 0, 1023, 0, 180);
data[1] = map(ring, 0, 1023, 0, 180);
data[2] = map(middle, 0, 1023, 0, 180);
data[3] = map(index, 0, 1023, 0, 180);
data[4] = map(thumb, 0, 1023, 0, 180);

radio.write(&data, sizeof(data));

delay(50);
}






















