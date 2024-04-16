#include <DHT.h>
#include <DHT_U.h>



#define DHTPIN 2
#define DHTTYPE DHT22

//Declare DHT object:
DHT dht(DHTPIN, DHTTYPE);
//Intialize the sensor.
int myNumb; 
//Commented the int Numb
int buzzPin=8;
//commented the buzz numb
int dt=2000; //3 seconds




void setup (){
  Serial.begin(115200); 
  dht.begin();
    pinMode(buzzPin,OUTPUT);
}

void loop (){
// delay(2);
 delay(1000);
//read humidity
float humi = dht.readHumidity();
//read temperature as Celsius
float tempC = dht.readTemperature();
//read temperature as Farenheit
float tempF = dht.readTemperature(true);



//Trigger Sensor
  if (tempC>30){
    digitalWrite(buzzPin, HIGH);
    delay(dt);
    digitalWrite(buzzPin, LOW);
  }
  //commented by shirlyne

//check if any reads failed
if (isnan(humi) || isnan(tempC) || isnan(tempF)){
  Serial.println("Failed to read from DHT sensor!");

}else {
// Serial.print("The Temp is:");
//   Serial.print(humi);
   Serial.print("Temperature:");
  Serial.print(tempC);
  Serial.print(",");
    
 

  Serial.print("Humidity:");
  Serial.println(humi);
    // Serial.print(",");
   
 

}
}


