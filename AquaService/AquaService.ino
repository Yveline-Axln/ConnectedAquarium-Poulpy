//Include the labraries needed
#include <chemicalMeasurement.h>
#include <module.h>
#include <PH.h>
#include <pi.h>
#include <pump.h>
#include <salinity.h>
#include <temperature.h>
#include <turbidity.h>
#include <waterLevel.h>

#include <OneWire.h>
#include <DallasTemperature.h>

#include <CurieBLE.h>

//declaration of constants and global variables
//define sensors pin
//digital pin
#define TEMP_SENSOR_PIN  4
#define WATER_LEVEL_SENSOR_PIN  2
#define TURBIDITY_SENSOR_DIG_PIN 7
//analog pin
#define TURBIDITY_SENSOR_ANA_PIN A0

//Create a water level sensor 
  waterLevel lvl(WATER_LEVEL_SENSOR_PIN, INPUT); 
  int State = 5; // variable for reading the pushbutton
//Create a turbidity sensor
  Turbidity turbi;
//Create a temperature sensor 
  Temperature temp(TEMP_SENSOR_PIN);
// Chemical Measurement
 chemicalMeasurement measurement; 

  
// BLE  aquaService
BLEService aquaService("07460000-baca-44ee-aa79-c4d892ae71d0"); 

// ** Characteristics specifications ** //

//  ** For water level sensor
// custom 128-bit UUID, read by central, get notifications if this characteristic changes
BLEUnsignedIntCharacteristic waterLevel("07460001-baca-44ee-aa79-c4d892ae71d0", BLERead | BLEIndicate);

//  ** For temperature sensor in Celsius
// custom 128-bit UUID, read by central, get notifications if this characteristic changes
BLEFloatCharacteristic temperatureC("07460002-baca-44ee-aa79-c4d892ae71d0", BLERead | BLEIndicate);

//  ** For the turbidity sensor analog voltage
// custom 128-bit UUID, read by central, get notifications if this characteristic changes
BLEFloatCharacteristic turbidityAnalogVoltage("07460003-baca-44ee-aa79-c4d892ae71d0", BLERead | BLEIndicate);

//  ** For pH
//custom 128-bit UUID, read and writable by central
BLEFloatCharacteristic pH("07460004-baca-44ee-aa79-c4d892ae71d0", BLERead | BLEWrite | BLENotify); 

//  ** For nitrite
//custom 128-bit UUID, read and writable by central
BLEUnsignedIntCharacteristic nitrite("07460005-baca-44ee-aa79-c4d892ae71d0", BLERead | BLEWrite | BLENotify );

//  ** For nitrate
//custom 128-bit UUID, read and writable by central
BLEUnsignedIntCharacteristic nitrate("07460006-baca-44ee-aa79-c4d892ae71d0", BLERead | BLEWrite | BLENotify );

//  ** For water hardness
//custom 128-bit UUID, read and writable by central
BLEUnsignedIntCharacteristic waterHardness("07460007-baca-44ee-aa79-c4d892ae71d0", BLERead | BLEWrite | BLENotify );


const int ledPin = 13; // pin to use for the LED

void setup() {
  Serial.begin(9600);

  // set LED pin to output mode
  pinMode(ledPin, OUTPUT);

  // begin initialization
  BLE.begin();

  // set advertised local name and service UUID:
  BLE.setLocalName("DATA");
 
  BLE.setAdvertisedService(aquaService);
  
  // add the characteristics to the service
  
  aquaService.addCharacteristic(waterLevel);
  
  aquaService.addCharacteristic(temperatureC);
 
  aquaService.addCharacteristic(turbidityAnalogVoltage);
  
  aquaService.addCharacteristic(pH);
  aquaService.addCharacteristic(nitrite);
  aquaService.addCharacteristic(nitrate);
  aquaService.addCharacteristic(waterHardness);

  // add service
  BLE.addService(aquaService);
  // set the initial value for the characeristic:
  waterLevel.setValue(0);
  temperatureC.setValue(0.0);
  turbidityAnalogVoltage.setValue(0.0);
  
  pH.setValue(0.0);
  nitrite.setValue(0);
  nitrate.setValue(0);
  waterHardness.setValue(0);
  

  // start advertising
  BLE.advertise();

  Serial.println("Bluetooth device active, waiting for connections...");
  
}

void loop() {
  // listen for BLE peripherals to connect:
  BLEDevice central = BLE.central();

  // if a central is connected to peripheral:
  if (central) {
    Serial.print("Connected to central: ");
    // print the central's MAC address:
    Serial.println(central.address());
    // turn on the LED to indicate the connection:
    digitalWrite(13, HIGH);

    // while the central is still connected to peripheral:
    while (central.connected()) {

       Serial.println( " " ); 
       Serial.println( "--- WATER LEVEL SENSOR RESULTS ---" );

      updateWaterLevel();
      delay(300);
      
      Serial.println( " " ); 
      Serial.println( "--- TEMPERATURE SENSOR RESULTS ---" );
      updateTemperatureC(); 
      delay(300);
      
      Serial.println( " " ); 
      Serial.println( "--- TURBIDITY SENSOR RESULTS ---" );
      updateTurbidityAnalogVoltage();
      delay(300);
      
      Serial.println( " " ); 
      Serial.println( "--- pH RESULTS ---" );
      updatePh();
      delay(900);

      Serial.println( " " ); 
      Serial.println( "--- NITRITE RESULTS ---" );
      updateNitrite();
      delay(900);

      Serial.println( " " ); 
      Serial.println( "--- NITRATE RESULTS ---" );
      updateNitrate();
      delay(900);

       Serial.println( " " ); 
      Serial.println( "--- WATER HARDNESS RESULTS ---" );
      updateWaterHardness();
      delay(900);
    }

    
    // when the central disconnects, turn off the LED:
    digitalWrite(13, LOW);
    Serial.print(F("Disconnected from central: "));
    Serial.println(central.address());
  }
}

void updateWaterLevel() {
   State = lvl.getState();
        Serial.print( "State: ");
        Serial.println(digitalRead(lvl.getPin()));
        if (State == HIGH) {
          
           waterLevel.setValue(State);
          Serial.println("Water level sensor is : HIGH ");
        } else {
         
          waterLevel.setValue(State);
          Serial.println("Water level sensor is : LOW");
        }
        Serial.print("Saved value: ");
        Serial.println(waterLevel.value());
}

void updateTemperatureC() {
  float c = temp.getTempCel();
  Serial.print("temperature in C°= ");
  Serial.println(c,2 );//number of decimal places
  temperatureC.setValue(c);
  Serial.print("Saved value: ");
  Serial.println(temperatureC.value());
}


void updateTurbidityAnalogVoltage() {
  //float voltage = turbi.getVoltage();
  Serial.print("Turbidity voltage: " );
  Serial.println( turbi.getVoltage() );
  turbidityAnalogVoltage.setValue(turbi.getVoltage());
  Serial.print("Saved value: ");
  Serial.println(turbidityAnalogVoltage.value()); 
}



void updatePh() {
  // if the client write a value
  if (pH.written()) {
    Serial.println("Data written ");
    
    // the ph interval value is between 0 and 14
     if ( (pH.value()>=0.0) && (pH.value()<=14.0)){
     Serial.print("New pH value: ");
     Serial.println(pH.value());
     measurement.setPH(pH.value()); // we only save a correct value (pH between 0 and 14)
     }
     // if the ph interval value is not between 0 and 14, we set it to 0
     if (((pH.value()<=0.0) || (pH.value()>=14.0))) {
     Serial.println("Le pH has to be between 0 and 14 ");
     Serial.print("Written value: "); 
     Serial.println(pH.value());
     pH.setValue(0.0);
     Serial.print("Wrong value so the pH value is set to 0 ");
     Serial.println("Set value:");
     Serial.println(pH.value());
     }
  }
  Serial.print("pH value: ");
  Serial.println(pH.value());
  
  Serial.print("pH saved value: ");
  Serial.println(measurement.getPH());
}

void updateNitrite() {
  if (nitrite.written()) {
    Serial.println("Envoie de Killian ");
     Serial.print("New nitrite value: ");
     Serial.println(nitrite.value());
  }
  Serial.print("Nitrite value: ");
  Serial.println(nitrite.value());
  measurement.setNitrite(nitrite.value());
  Serial.print("Nitrite saved value: ");
  Serial.println(measurement.getNitrite());
}


void updateNitrate() {
  if (nitrate.written()) {
     Serial.print("New nitrate value: ");
     Serial.println(nitrate.value());
  }
  Serial.print("Nitrate value: ");
  Serial.println(nitrate.value());
  measurement.setNitrate(nitrate.value());
  Serial.print("Nitrate saved value: ");
  Serial.println(measurement.getNitrate());
}

void updateWaterHardness() {
  if (waterHardness.written()) {
     Serial.print("New water hardness value: ");
     Serial.println(waterHardness.value());
  }
   Serial.print("Water hardnesse value: ");
   Serial.println(waterHardness.value());
   measurement.setWaterHardness(waterHardness.value());
   Serial.print("Water hardness saved value: ");
   Serial.println(measurement.getWaterHardness());
}


