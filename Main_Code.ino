//temperatura
#include <OneWire.h>
#include <HX711.h>
#include <DallasTemperature.h>
#include <ESP32Servo.h>
#include "pitches.h"


#define ONE_WIRE_BUS 5
#define buzer 22
#define DT 14
#define SCK 27
#define bomba1 32
#define bomba2 33
#define zero_factor -324559
#define DEC_POINT  2
const int corrente= 23 ;
float offset=0;
float get_units_kg();
float Pararbombadetintabranca ;
float Pararbombadetintapreta ;
// BluetoothSerial SerialBT;

OneWire oneWire(ONE_WIRE_BUS);

HX711 scale;

DallasTemperature sensors(&oneWire);

extern void buzzer();
extern void temperatura();
extern void cor();
extern int getRedPW();
extern int getGreenPW();
extern int getBluePW();
extern void peso();


int peso1=0;
int pesoMax=2;


 float CelciusMax=26;
 float Celcius=0;
 float pesoFinal = 2.918;
float massaPresente = 0;
float lerPeso = 0;
float percentagem=0.5;
float calibration_factor =-1388779.00;//-158779
//cor
// Define color sensor pins
 
#define S0 4
#define S1 2
#define S2 19
#define S3 21
#define sensorOut 18
 
// Calibration Values
// Get these from Calibration Sketch
 
int redMin = 389; // Red minimum value
int redMax = 443; // Red maximum value
int greenMin = 458; // Green minimum value
int greenMax = 530; // Green maximum value
int blueMin = 376; // Blue minimum value
int blueMax = 432; // Blue maximum value
 
// Variables for Color Pulse Width Measurements
 
int redPW = 0;
int greenPW = 0;
int bluePW = 0;
// Variables for final Color values
 
int redValue;
int greenValue;
int blueValue;
float branco = (blueValue/2.55);

//COnfiguração de variaveis
int configtemperatura = 0;
int configpeso = 0;
float configpercentagem = 0;
float percentagemdebranco;
float preto ;
void setup() {
  
  Serial.print("PesoFinal");
Serial.print(pesoMax);
Serial.print("   Temperatura máxima:");
Serial.print(CelciusMax);
//Serial.print( "  Tinta preta:");
//Serial.print(Pararbombadetintapreta*pesoMax); 
//Serial.print( "  Tinta branca:");
//Serial.print(Pararbombadetintabranca*pesoMax); 
//Serial.println(" ");
  
  //configuracaovariaveis(); 
  pinMode(10, OUTPUT);
  pinMode(bomba1,OUTPUT);
  pinMode (bomba2, OUTPUT);
  pinMode (corrente,  OUTPUT); 
  scale.begin (DT, SCK);
  scale.set_scale(calibration_factor); 
   
  scale.set_offset(zero_factor); 
Serial.begin(115200);
 // Set S0 - S3 as outputs
 
 pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(buzer,OUTPUT);
  // Set Sensor output as input
  pinMode(sensorOut, INPUT);
  digitalWrite (corrente, LOW);
  // Set Frequency scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
   
  sensors.begin(); 
  // Setup Serial Monitor

  
}

void loop() {
  buzzer();
  peso();
  while(lerPeso < pesoMax){
  cor();
  percentagemdebranco = (branco/100);
  float preto = 1 - percentagemdebranco;
  Pararbombadetintapreta = preto;
  Pararbombadetintabranca = percentagemdebranco;

  Serial.println (percentagemdebranco);
  Serial.println (preto);
  
  cor();
  peso(); 
  

 temperatura();
  
  peso();
  Serial.println();
  
  Serial.println (Celcius);
  Serial.println ("ºC");
 
   
   
    while(lerPeso< (percentagemdebranco* pesoMax)){
      digitalWrite (bomba1, HIGH);
    }
    while (lerPeso > percentagemdebranco*pesoMax && lerPeso < pesoMax){
    digitalWrite (bomba1, LOW);
    digitalWrite (bomba2, HIGH);
    }
    if (lerPeso >= pesoMax){
      digitalWrite (bomba1, LOW);
      digitalWrite (bomba2, LOW);
    }
    temperatura();
    Serial.println(Celcius);
     if(Celcius<CelciusMax){
        digitalWrite(corrente,HIGH);
      }else{
        digitalWrite(corrente,LOW);
         buzzer();
      } 
  }
 }
 
