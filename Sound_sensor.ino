//***********************************************************//
//                      [ Source Code ]
// Name              : Isa Maulana <isamaulana@windowslive.com>
// Date              : November 10, 2021
// Dependency        : LiquidCrystal.h, math.h
//
// Description: Read value from KY-037 Sound Sensor
//***********************************************************//

#include <math.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7,8,10,11,12,13);

int num_Measure = 1024 ; // Number of measurement 
int pinSignal = A0; // analog pin sensor
int red = 5; //pin to red led sensor
int yellow = 6; //pin to yellow led sensor
long average;
long Sound_signal; // keep analog value from sensor
long sum = 0 ; 
double level; // keep final value of sensor in dBA

//variables of 6 degree polynomial function
//values extracted from regression
long x0 = -4576.851265;
long x1 = 208.2974902;
long x2 = -3.815269323;
long x3 = 3.678654847*pow(10,-2);
long x4 = -1.968202986*pow(10,-4);
long x5 = 5.541234656*pow(10,-7);
long x6 = -6.4158328946*pow(10,-10);


void setup () 
{ 
 pinMode (pinSignal, INPUT); // Set the signal pin as input 
 Serial.begin (9600); 
 lcd.begin(16,2); 
 pinMode(red, OUTPUT);
 pinMode(yellow, OUTPUT);
} 
 
void loop () 
{ 
 // read the sensor 1024 times
 sum = 0; 
 lcd.clear(); 
 digitalWrite(yellow, LOW);
 digitalWrite(red, LOW);
 for ( int i = 0 ; i <num_Measure; i ++) 
 { 
 Sound_signal = analogRead (pinSignal); 
 sum =sum + Sound_signal; 
 } 
 average = sum / num_Measure; // find the average read value from sensor 

 //keep final value of sensor in dBA using 6 degree polynomial function from regression
 level = x6*pow(average,6) + x5*pow(average,5) + x4*pow(average,4) + x3*pow(average,3) + x2*pow(average,2) + x1*average + x0;
 Serial.println (average);
 Serial.print (level); 
 Serial.println ("dBA");
 lcd.print("Intensitas=");

 lcd.print(level);
 lcd.setCursor(0,2);
 lcd.print("dBA");
 if ((level>95) and (level<105)) //lampu yellow menyala
 digitalWrite(yellow, HIGH);
 if (level>105)
 digitalWrite(red, HIGH); //lampu red menyala
 delay(500);
}
