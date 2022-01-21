/*   ~ Simple Arduino - xBee Transmitter sketch ~

  Read an analog value from potentiometer, then convert it to PWM and finally send it through serial port to xBee.
  The xBee serial module will send it to another xBee (resiver) and an Arduino will turn on (fade) an LED.
  The sending message starts with '<' and closes with '>' symbol. 
  
  Dev: Michalis Vasilakis // Date:2/3/2016 // Info: www.ardumotive.com // Licence: CC BY-NC-SA                    */

//Constants: 
const int potPin = A0; //Pot at Arduino A0 pin 
//Variables:
int SuSeviyesivalue ; //Value from pot
int isikvalue;

float sicaklikValue;
 float NemValue;
 int count=1;
//#include <DHT11> 
#include <DHT.h> 
#define DHTPIN A2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
 DHT dht(DHTPIN, DHTTYPE);


void setup() {

  //Start the serial communication
  Serial.begin(9600); //Baud rate mustsame as is on xBee module

 dht.begin();

}

void loop() {
    
    //Read the analog value from pot and store it to "value" variable
    SuSeviyesivalue = analogRead(A0);
    isikvalue=analogRead(A1);
int sicaklikValue=dht.readTemperature();
int NemValue = dht.readHumidity();
    isikvalue=map(isikvalue, 0, 1023, 0, 255);  
    //Map the analog value to pwm value
    //SuSeviyesivalue = map (SuSeviyesivalue, 0, 1023, 0, 255);
    NemValue= map (NemValue, 0, 1023, 0, 255);
    sicaklikValue = map (sicaklikValue, 0, 1023, 0, 255);
    
  //Send the message:
 
if(count==1){
  Serial.print('-');
 
  Serial.print(sicaklikValue);
  Serial.print('+');
  Serial.print('\n');
  count=2;
  
}else if(count==2){
  Serial.print('<');
 
  Serial.print(NemValue);
  Serial.print('>');
  Serial.print('\n');
  count=3;
}else if(count==3){
   Serial.print('{');
   
  Serial.print(isikvalue);
 
  Serial.print('}');
   Serial.print('\n');
  count=1;
}


  

  

  
delay(1500);
}
