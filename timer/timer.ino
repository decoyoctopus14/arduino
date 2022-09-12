#define WORK 23
#define PAUSE 17
#include <Servo.h>

int button_status=0;
int button_pin=10;
int pinBuzzer=7;
int pin_motore=8;

long t = 0;
long debounce_delay = 1000;

 Servo mioServo;

void setup() {
  // put your setup code here, to run once:
     pinMode(button_pin,INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Setup...");
   mioServo.attach(pin_motore);
   mioServo.write(180);
   mioServo.write(90);
   mioServo.write(180);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pin_value=digitalRead(button_pin);
  delay(10);
  //Serial.println(pin_value);
  /*
  if(button_status!=pin_value){
    button_status=pin_value;
    
    Serial.print(button_status);
    Serial.println("Starting countdown...");
    contoAllaRovesciaServo();
    }
    */

     if (pin_value)
       if ( (millis() - t) > debounce_delay) {
        
          Serial.println("Starting countdown...");
          contoAllaRovesciaServo();
        t = millis();  
      }     
}

void buzzer_sound(){
   // Coin Sound da SuperMario
  tone(pinBuzzer, 988,100);    // Nota B5
  delay(100);
  tone(pinBuzzer,1319,850);    // Nota E6
}

void contoAllaRovesciaServo() {
  Serial.println("Conto alla rovescia: ");
  int passi = WORK;

  for (int i = passi; i >= 0; i--) {
    mioServo.write(i * 8);
    
    for (int j=0;j<60;j++)
      delay(1000);
    delay(200);
    Serial.print(i);
    Serial.println(" min");
  }
 
 mioServo.write(180);
 buzzer_sound();
 delay(500);
}
