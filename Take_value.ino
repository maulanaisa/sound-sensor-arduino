//***********************************************************//
//                      [ Source Code ]
// Name              : Isa Maulana <isamaulana@windowslive.com>
// Date              : November 10, 2021
// Dependency        : -
//
// Description: Read value from KY-037 Sound Sensor
//***********************************************************//

int num_Measure = 1024 ; // number of measurement 
int pinSignal = A0; // analog pin
long Sound_signal; // keep analog value from sensor
long sum = 0 ; 
long level = 0 ; //keep final value of sensor in dBA

void setup () 
{ 
  pinMode (pinSignal, INPUT); // Set the signal pin as input 
  Serial.begin (9600); 
} 
 
void loop () 
{ 
 // read the sensor 1024 times
 sum = 0; 
 for ( int i = 0 ; i <num_Measure; i ++) 
 { 
 Sound_signal = analogRead (pinSignal); 
 sum =sum + Sound_signal; 
 } 
 //find the average read value from sensor 
 level = sum / num_Measure;
 Serial.println (level); 
 delay(500);
}
