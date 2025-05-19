void peso();
void peso(){
 
  Serial.print("Reading: ");
  String data = String(get_units_kg()+offset, DEC_POINT);
  lerPeso = data.toFloat();
  Serial.print(data);
 // lerPeso == atof (data.c_str());
  Serial.println(" kg");
 Serial.println(lerPeso);
}
float get_units_kg()

{
  return(scale.get_units()*0.453592);
}
