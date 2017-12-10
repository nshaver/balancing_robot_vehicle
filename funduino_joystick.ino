/*********************************************************************
** Device: Joystick shield -- Duncan Lam v1.0 **
** File: sketch_jostick_1pa **
** **
** Created by Duncan Lam 4/22/2015 **
** **
** Description: **
** This file is a sample code for you to test the joystick shield **
** 1.A it has the correct pins **
** look at the code below for the correct pin accosicate with the **
** different digital pins and the analog stick with the analog pins**
*********************************************************************/
// Select button is triggered when joystick is pressed
const byte PIN_BUTTON_A = 2;
const byte PIN_BUTTON_B = 3;
const byte PIN_BUTTON_C = 4;
const byte PIN_BUTTON_D = 5;
const byte PIN_BUTTON_E = 6;
const byte PIN_BUTTON_F = 7;
const byte PIN_BUTTON_K = 8;
const byte PIN_ANALOG_X = 0;
const byte PIN_ANALOG_Y = 1;
boolean pressed_a = false;
boolean pressed_b = false;
boolean pressed_c = false;
boolean pressed_d = false;
boolean pressed_e = false;
boolean pressed_f = false;
boolean pressed_k = false;
int analog_x_min = 0;
int analog_y_min = 0;
int analog_x_max = 1021;
int analog_y_max = 1022;
int analog_x_center = 510;
int analog_y_center  = 496;
int analog_x, analog_y;
int analog_x_last, analog_y_last;
int analog_x_deadzone=10;
int analog_y_deadzone=10;

void setup() {
	Serial.begin(115200);
	pinMode(PIN_BUTTON_A, INPUT);
	digitalWrite(PIN_BUTTON_A, HIGH);
	pinMode(PIN_BUTTON_B, INPUT);
	digitalWrite(PIN_BUTTON_B, HIGH);
	pinMode(PIN_BUTTON_C, INPUT);
	digitalWrite(PIN_BUTTON_C, HIGH);
	pinMode(PIN_BUTTON_D, INPUT);
	digitalWrite(PIN_BUTTON_D, HIGH);
	pinMode(PIN_BUTTON_E, INPUT);
	digitalWrite(PIN_BUTTON_E, HIGH);
	pinMode(PIN_BUTTON_F, INPUT);
	digitalWrite(PIN_BUTTON_F, HIGH);
	pinMode(PIN_BUTTON_K, INPUT);
	digitalWrite(PIN_BUTTON_K, HIGH);
}

void loop() {
	if(pressed_a == digitalRead(PIN_BUTTON_A)){
		Serial.print("btn A");
		Serial.println();
	}
	if(pressed_b == digitalRead(PIN_BUTTON_B)){
		Serial.print("btn B");
		Serial.println();
	}
	if(pressed_c == digitalRead(PIN_BUTTON_C)){
		Serial.print("btn C");
		Serial.println();
	}
	if(pressed_d == digitalRead(PIN_BUTTON_D)){
		Serial.print("btn D");
		Serial.println();
	}
	if(pressed_e == digitalRead(PIN_BUTTON_E)){
		Serial.print("btn E");
		Serial.println();
	}
	if(pressed_f == digitalRead(PIN_BUTTON_F)){
		Serial.print("btn F");
		Serial.println();
	}
	if(pressed_f == digitalRead(PIN_BUTTON_K)){
		Serial.print("btn K");
		Serial.println();
	}
	analog_x = analogRead(PIN_ANALOG_X); 
	analog_y = analogRead(PIN_ANALOG_Y); 

	// remap to 0-midpoint-1023
	if (analog_x < analog_x_center) analog_x=map(analog_x, analog_x_min, analog_x_center, 0, 512);
	else if (analog_x > analog_x_center) analog_x=map(analog_x, analog_x_center, analog_x_max, 512, 1023);
	else analog_x=512;

	if (analog_y < analog_y_center) analog_y=map(analog_y, analog_y_min, analog_y_center, 0, 512);
	else if (analog_y > analog_y_center) analog_y=map(analog_y, analog_y_center, analog_y_max, 512, 1023);
	else analog_y=512;

	if (analog_x < 512 + analog_x_deadzone &&
			analog_x > 512 - analog_x_deadzone) {
		analog_x=512;
	}
	if (analog_y < 512 + analog_y_deadzone &&
			analog_y > 512 - analog_y_deadzone) {
		analog_y=512;
	}

	if (analog_x != analog_x_last ||
			analog_y != analog_y_last){
		Serial.print("x:y = "); 
		Serial.print(analog_x);
		Serial.print(":"); 
		Serial.print(analog_y);
		Serial.println(); 
		analog_x_last=analog_x;
		analog_y_last=analog_y;
	}
	delay(100);
}
