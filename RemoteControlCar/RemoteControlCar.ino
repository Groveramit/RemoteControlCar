#include <IRremote.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

int RECV_PIN = 11;
int LEDPin = 5;  //LED pin 5
int ledState = LOW;   
long interval = 3000;    

const int motorPin3  = 10; // Pin  7 of L293
const int motorPin4  = 9;  // Pin  2 of L293

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
//  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(LEDPin, OUTPUT);      // sets the digital pin as output
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
}

void loop()
{
  if (irrecv.decode(&results))
    {
      long int hexCode = results.value;
     // Serial.println(hexCode,HEX);
      if(hexCode == 0XE0E020DF || hexCode == 0X92DF9279) //when you press 1
      {
          digitalWrite(LEDPin, HIGH);
          digitalWrite(motorPin3, HIGH);
          digitalWrite(motorPin4, LOW);
          delay(10000);
          digitalWrite(LEDPin, LOW);
          digitalWrite(motorPin3, LOW);
          digitalWrite(motorPin4, LOW);
          //Serial.println("Success");
      }
      else
      {
          digitalWrite(LEDPin, LOW);
          digitalWrite(motorPin3, LOW);
          digitalWrite(motorPin4, LOW);
          
       //   Serial.println("Fail");
      }
      irrecv.resume(); // Receive the next value
    }
}

