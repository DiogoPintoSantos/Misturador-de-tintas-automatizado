void temperatura();
void temperatura(){
 sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
  
  Serial.print(" C  ");
  Serial.print(Celcius);
  
  delay(1000);
 }
 
