#include <module.h>
#include <pi.h>
#include <pump.h>
#include <temperature.h>
#include <turbidity.h>
#include <waterLevel.h>

#include <OneWire.h>
#include <DallasTemperature.h>


using namespace std;

//declaration of constants and global variables
//define sensors pin
//digital pin
#define TEMP_SENSOR_PIN  4
#define WATER_LEVEL_SENSOR_PIN  2
#define TURBIDITY_SENSOR_DIG_PIN 7
//analog pin
#define TURBIDITY_SENSOR_ANA_PIN A0

//Create a water level sensor 
  waterLevel lvl(WATER_LEVEL_SENSOR_PIN, INPUT); //D2 
//Create a turbidity sensor
  Turbidity turbi;
//Create a temperature sensor 
  Temperature temp(TEMP_SENSOR_PIN);
 


int State = 5; // variable for reading the pushbutton

void setup() {

  // start serial port
  Serial.begin(9600);
  
  //*** Water level sensor ***//
  lvl.setPin(2);


  //*** Turbidity sensor ***//
  //Analog pin
   turbi.setAnalogPin(TURBIDITY_SENSOR_ANA_PIN); //A0

  //digitalPin
  turbi.setDigitalPin(TURBIDITY_SENSOR_DIG_PIN,INPUT); //D3  
    
}

void loop() {
 
 //--------- Water level sensor - PIN D2 --------------//
  Serial.println( "WATER LEVEL RESULTS" );

  int waterLvlPin=lvl.getPin();
  State = lvl.getState();
  Serial.print( "State: ");
  Serial.println(digitalRead(lvl.getPin()));
  Serial.print( "Pin: ");
  Serial.println(waterLvlPin);


  if (State == HIGH) {
    Serial.println( "water level - HIGH");
  } else {
    Serial.println( "water level - LOW" );
  }
  delay(300);

  //--------- Turbidity sensor - PIN A0 D7 --------------//
  //The turbidity sensor increase with the clarity of the water
  Serial.println( " " );
  Serial.println( "TURBIDITY SENSOR RESULTS" );
 

  // Analog analysis
  //Serial.println( " " );
  Serial.println( "Analog analysis..." );

  int aVal = turbi.getAnalogValue();
  float voltage = turbi.getVoltage();
  int apin =turbi.getAnalogPin();
   Serial.print("Turbidity analog pin: " );
  Serial.println( apin );
  Serial.print("Turbidity analog value: " );
  Serial.println( aVal );
  Serial.print("Turbidity voltage: " );
  Serial.println( voltage );

  // Digital analysis
  Serial.println( " " );
  Serial.println( "Digital analysis..." );
 
  int dVal = turbi.getDigitalValue();
  int dpin =turbi.getDigitalPin();
  Serial.print("Turbidity digital pin: " );
  Serial.println( dpin );

  Serial.print("Turbidity digital value: " );
  Serial.println( dVal );

  delay(300);

   //--------- Temperature sensor - PIN D4 --------------//
  Serial.println( " " ); 
  Serial.println( "TEMPERATURE SENSOR RESULTS" );
 
 //get the sensor's pin 
  uint8_t tempPin=temp.getPin();
  Serial.print("temperature sensor pin: ");
  Serial.println(tempPin);
  
 //display temp 
  float c = temp.getTempCel();
  Serial.print("temperature in C° = ");
  Serial.println(c,2 );//number of decimal places
  float f = temp.getTempFah();
  Serial.print("temperature in °F = ");
  Serial.println(f,2);
  Serial.println("------------");
  Serial.println("");
  delay(3000);
}
