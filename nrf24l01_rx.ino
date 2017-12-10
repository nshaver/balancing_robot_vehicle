/* JoyStick module receiver code
By Nazmus
http://www.Easyprogramming.net
http://nazm.us
 - CONNECTIONS: nRF24L01 Modules See:
 http://arduino-info.wikispaces.com/Nrf24L01-2.4GHz-HowTo
   1 - GND
   2 - VCC 3.3V !!! NOT 5V
   3 - CE to Arduino pin 6
   4 - CSN to Arduino pin 7
   5 - SCK to Arduino pin 13
   6 - MOSI to Arduino pin 11
   7 - MISO to Arduino pin 12
   8 - UNUSED
   
   Above connections created by shield
   On Motor Shield connect Servos to servo connections 1 & 2
 */

/*-----( Import needed libraries )-----*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//#include <Servo.h>
/*-----( Declare Constants and Pin Numbers )-----*/
#define CE_PIN 9
#define CSN_PIN 10
  
// NOTE: the "LL" at the end of the constant is "LongLong" type
const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe
//const int servo1 = 9; // first servo
//const int servo2 = 10; // second servo
//int servoVal; // variable to read the value from the analog pin

//Servo myservo1; // create servo1
//Servo myservo2; // create servo2

RF24 radio(CE_PIN, CSN_PIN); // Create a Radio

int joystick[9];

char buf[50];

void setup() {
  Serial.begin(115200);
  delay(1000);
  //myservo1.attach(servo1); // attaches the servo1 
  //myservo2.attach(servo2); // attaches the servo2
  Serial.println("Nrf24L01 Receiver Starting");
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();;
}

void loop() {
  while ( radio.available() ) {
		radio.read( joystick, sizeof(joystick) );
		int joystickX = map(joystick[0],0,1023,0,180); // turn value of 0-1023 to 0-180 degrees
		int joystickY = map(joystick[1],0,1023,0,180);  // turn value of 0-1023 to 0-180 degrees
		
		// the four button variables from joystick array
		int btn_A = joystick[2];
		int btn_B = joystick[3];
		int btn_C = joystick[4];
		int btn_D = joystick[5];
		int btn_E = joystick[6];
		int btn_F = joystick[7];
		int btn_K = joystick[8];
		
		//servoVal = joystickX; // scale it to use it with the servo (result between 0 and 180)
		//myservo2.write(servoVal); // sets the servo position according to the scaled value
		//Serial.println(servoVal); // for debugging
		
		//servoVal = joystickY; // scale it to use it with the servo (result between 0 and 180)
		//myservo1.write(servoVal); // sets the servo position according to the scaled value
		
		//Serial.println(servoVal); // for debugging

		// Fetch the data payload - Debugging code below
		
		sprintf(buf, "x:y %d:%d ABCDEFK %d%d%d%d%d%d%d", joystickX, joystickY, btn_A, btn_B, btn_C, btn_D, btn_E, btn_F, btn_K);
		Serial.println(buf);
	 
		delay(15); // waits for the servo to get there
  }
}
