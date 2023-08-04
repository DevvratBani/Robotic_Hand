#include <nRF24L01.h> 
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

#include <Wire.h>
#include <Servo.h>
#include <Adafruit_PWMServoDriver.h>

#define SERVOS_ADDRESS 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(SERVOS_ADDRESS);

RF24 radio(9, 10); // CE, CSN pins
const byte address[6] = "00001";

int data[5];


void setup() 
{
  pwm.begin();
  pwm.setPWMFreq(60);

  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, address);
  radio.startListening();
}

void loop() 
{
 if(radio.available())
 {
   int data[5] = {0};
   radio.read(&data, sizeof(data));

   int little = data[0];
   int ring = data[1];
   int middle = data[2];
   int index = data[3];
   int thumb = data[4];

   pwm.setPWM(0, 0, little); 
   pwm.setPWM(1, 0, ring);
   pwm.setPWM(2, 0, middle); 
   pwm.setPWM(3, 0, index);
   pwm.setPWM(4, 0, thumb);

   delay(50);
 }
}
