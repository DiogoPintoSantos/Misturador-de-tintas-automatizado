//temperatura
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP32Servo.h>
#define ONE_WIRE_BUS 5
#define buzer 22
OneWire oneWire(ONE_WIRE_BUS);
int temperaturaFinal,pesoFinal;

DallasTemperature sensors(&oneWire);

 float Celcius=0;
 float Fahrenheit=0;

//cor
// Define color sensor pins
 
#define S0 4
#define S1 2
#define S2 19
#define S3 21
#define sensorOut 18
 
// Calibration Values
// Get these from Calibration Sketch
 
int redMin = 35; // Red minimum value
int redMax = 153; // Red maximum value
int greenMin = 36; // Green minimum value
int greenMax = 185; // Green maximum value
int blueMin = 30; // Blue minimum value
int blueMax = 152; // Blue maximum value
 
// Variables for Color Pulse Width Measurements
 
int redPW = 0;
int greenPW = 0;
int bluePW = 0;
 
// Variables for final Color values
 
int redValue;
int greenValue;
int blueValue;

void setup() {
  pinMode(10, OUTPUT);

 // Set S0 - S3 as outputs
 Serial.begin(9600);
 pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(buzer,OUTPUT);
  // Set Sensor output as input
  pinMode(sensorOut, INPUT);
  
  // Set Frequency scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
   
  sensors.begin(); 
  // Setup Serial Monitor

  
}


void loop() { 
  while(

  temperatura();


  cor(); 
  
  buzzer();
  
//cor
}
//temperatura
 void temperatura(){
 sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
  Fahrenheit=sensors.toFahrenheit(Celcius);
  Serial.print(" C  ");
  Serial.print(Celcius);
  Serial.print(" F  ");
  Serial.println(Fahrenheit);
  delay(1000);
 }

  


//funções
//cor
// Function to read Red Pulse Widths
void cor(){
  redPW = getRedPW();
  // Map to value from 0-255
  redValue = map(redPW, redMin,redMax,255,0);
  // Delay to stabilize sensor
  delay(200);
  greenPW = getGreenPW();
  // Map to value from 0-255
  greenValue = map(greenPW, greenMin,greenMax,255,0);
  // Delay to stabilize sensor
  delay(200);
  
  // Read Blue value
  bluePW = getBluePW();
  // Map to value from 0-255
  blueValue = map(bluePW, blueMin,blueMax,255,0);
  // Delay to stabilize sensor
  delay(200);
  
  // Print output to Serial Monitor
  Serial.print("Red = ");
  Serial.print(redValue);
  Serial.print(" - Green = ");
  Serial.print(greenValue);
  Serial.print(" - Blue = ");
  Serial.println(blueValue);
}
int getRedPW() {
 
  // Set sensor to read Red only
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
 
}
int getGreenPW() {
 
  // Set sensor to read Green only
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
 
}
 
// Function to read Blue Pulse Widths
int getBluePW() {
 
  // Set sensor to read Blue only
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
 


}
void buzzer() {
// play e4
  delay(300);
  tone(22, 329.63, 300);
  delay(175);
  // play d4# 
  tone(22, 311.13, 300);
  delay(175);
  // play e4
  tone( 22, 329.63, 300);
  delay(175);
  // play d4# 
  tone( 22,311.13, 300);
  delay(175);
  // play e4
  tone(22, 329.63, 300);
  delay(175);
  // play b3
  tone( 22, 246.94, 300);
  delay(200);
  // play d4
  tone(22, 293.66,300);
  delay(200);
  // play c4
  tone(22, 261.63,300);
  delay(200);
  // play a3
  tone(22, 220, 900);
  delay(500);
  // play d3
  tone(22,146.83, 300);
  delay(175);
  //play f3
  tone(22, 174.61, 300);
  delay(200);
  //play a3
  tone(22, 220, 300);
  delay(200);
  // play b3
  tone(22, 246.94, 900);
  delay(500);
  // play f3
  tone(22, 174.61, 300);
  delay(200);
  // play a3#
  tone(22, 233.08, 300);
  delay(200);
  // play b3
  tone(22, 246.94, 300);
  delay(200);
  // play c4
  tone(22, 261.63, 900);
  delay(500);
  delay(150);
  // play e4
  tone(22, 329.63, 300);
  delay(200);
  // play d4#
  tone(22, 311.13, 300);
  delay(200);
  // play e4
  tone(22, 329.63, 300);
  delay(200);
  // play d4#
  tone(22, 311.13, 300);
  delay(200);
  // play e4
  tone(22, 329.63, 300);
  delay(200);
  // play b3
  tone(22, 246.94, 300);
  delay(200);
  // play d4
  tone(22, 293.66, 300);
  delay(200);
  // play c4
  tone(22, 261.63, 300);
  delay(200);
  // play a3
  tone(22, 220, 900);
  delay(500);
  // play d3
  tone(22, 146.83, 300);
  delay(200);
  // play f3
  tone(22, 174.61, 300);
  delay(200);
  // play a3
  tone(22, 220, 300);
  delay(200);
  // play b3
  tone(22, 246.94, 900);
  delay(500);
  // play f3
  tone(22, 174.61, 300);
  delay(200);
  // play c4
  tone(22, 261.63, 300);
  delay(200);
  // play b3
  tone(22, 246.94, 300);
  delay(200);
  // play a3
  tone(22, 220, 900);
  delay(500);
  // play b3
  tone(22,246.94, 300);
  delay(200);
   // play c4
  tone(22, 261.63, 300);
  delay(200);
  // play d4
  tone(22, 293.66, 300);
  delay(200);
  // play e4
  tone(22, 329.63, 900);
  delay(500);
  // play g3
  tone(22, 196, 300);
  delay(200);
  // play f4
  tone(22, 349.23, 300);
  delay(200);
  //play e4
  tone(22, 329.23, 300);
  delay(200);
  // play d4
  tone(22, 293.63, 900);
  delay(500);
  // play e3
  tone(22,164.81, 300);
  delay(200);
  // play e4
  tone(22, 329.63, 300);
  delay(200);
  // play d4
  tone(22, 293.63, 300);
  delay(200);
  // play c4
  tone(22, 261.63, 900);
  delay(500);
  // play d3
  tone(22, 146.83, 300);
  delay(200);
    // play d4
  tone(22, 293.63, 300);
  delay(200);
  // play c4
  tone(22, 261.63, 300);
  delay(200);
  // play b3
  tone(22, 246.94, 900);
  delay(500);
  delay(200);
  // play e4
  tone(22, 329.63, 300);
  delay(200);
  // play d4# 
  tone(22, 311.13, 300);
  delay(175);
  // play e4
  tone( 22, 329.63, 300);
  delay(175);
  // play d4# 
  tone( 22,311.13, 300);
  delay(175);
  // play e4
  tone(22, 329.63, 300);
  delay(175);
  // play b3
  tone(22, 246.94, 300);
  delay(200);
  // play d4
  tone(22, 293.66,300);
  delay(200);
  // play c4
  tone(22, 261.63,300);
  delay(200);
  // play a3
  tone(22, 220, 900);
  delay(500);
  // play d3
  tone(22,146.83, 300);
  delay(175);
  //play f3
  tone(22, 174.61, 300);
  delay(200);
  //play a3
  tone(22, 220, 300);
  delay(200);
  // play b3
  tone(22, 246.94, 900);
  delay(500);
  // play f3
  tone(22, 174.61, 300);
  delay(200);
  // play a3
  tone(22, 233.08, 300);
  delay(200);
  // play b3
  tone(22, 246.94, 300);
  delay(200);
  // play c4
  tone(22, 261.63, 900);
  delay(500);
  delay(150);
  // play e4
  tone(22, 329.63, 300);
  delay(200);
  // play d4#
  tone(22, 311.13, 300);
  delay(200);
  // play e4
  tone(22, 329.63, 300);
  delay(200);
  // play d4#
  tone(22, 311.13, 300);
  delay(200);
  // play e4
  tone(22, 329.63, 300);
  delay(200);
  // play b3
  tone(22, 246.94, 300);
  delay(200);
  // play d4
  tone(22, 293.66, 300);
  delay(200);
  // play c4
  tone(22, 261.63, 300);
  delay(200);
  // play a3
  tone(22, 220, 900);
  delay(500);
  // play d3
  tone(22, 146.83, 300);
  delay(200);
  // play f3
  tone(22, 174.61, 300);
  delay(200);
  // play a3
  tone(22, 220, 300);
  delay(200);
  // play b3
  tone(22, 246.94, 900);
  delay(500);
  // play f3
  tone(22, 174.61, 300);
  delay(200);
  // play c4
  tone(22, 261.63, 300);
  delay(200);
  // play b3
  tone(22, 246.94, 300);
  delay(200);
  // play a3
  tone(22, 220, 900);
  delay(500);
  
  delay(2500);


}
