const int hotPin = 6; 
const int isikPin=7;
const int nemPin=8;
bool startedHot= false;
bool endedHot  = false;
char incomingByte ; 
char msgHot[4];    
byte indexHot ; 

bool startedNem= false;
bool endedNem  = false;

char msgNem[4];    
byte indexNem; 

bool startedisik= false;
bool endedisik  = false;

char msgisik[4];    
byte indexisik; 

     
void setup() {

    Serial.begin(9600); 
  pinMode(hotPin, OUTPUT);
  pinMode(isikPin,OUTPUT);
  pinMode(nemPin,OUTPUT);
}
void loop() {
  while (Serial.available()>0){
  incomingByte = Serial.read();
    if(incomingByte == '-')
   {
     startedHot = true;
     indexHot = 0;
     msgHot[indexHot] = '\0'; 
   }
else if(incomingByte == '+')
   {
     endedHot = true;
     break ;
   }
   else
   {
     if(indexHot < 5)      {
       msgHot[indexHot] = incomingByte; 
       indexHot++;
       msgHot[indexHot] = '\0'; 
     }
   }

    if(incomingByte == '<')
   {
     startedNem = true;
     indexNem = 0;
     msgNem[indexNem] = '\0';
   }
   else if(incomingByte == '>')
   {
     endedNem = true;
     break;    }
   else
   {
     if(indexNem < 5)
     {
       msgNem[indexNem] = incomingByte; 
       indexNem++;
       msgNem[indexNem] = '\0';
     }
   }
   if(incomingByte == '{')
   {
     startedisik = true;
     indexisik = 0;
     msgisik[indexisik] = '\0';
   }
   else if(incomingByte == '}')
   {
     endedisik = true;
     break;    }
   else
   {
     if(indexisik < 5)
     {
       msgisik[indexisik] = incomingByte; 
       indexisik++;
       msgisik[indexisik] = '\0';
     }
   }
 }
if(startedHot && endedHot)
 {
   int values = atoi(msgHot);
   Serial.print("Sensor SICAKLIK:");
   Serial.print(values);
   Serial.print("\n");
  if(values>8){
    digitalWrite(hotPin,HIGH);
  }else{
    digitalWrite(hotPin,LOW);
  }
   indexHot = 0;
   msgHot[indexHot] = '\0';
   startedHot = false;
   endedHot = false;
 }
 if(startedNem && endedNem)
 {
   int value = atoi(msgNem);
   Serial.print("Sensor NEM:");
   Serial.print(value);
   Serial.print("\n");
  if(value>5){
    digitalWrite(nemPin,HIGH);
  }else{
    digitalWrite(nemPin,LOW);
  }
   indexNem = 0;
   msgNem[indexNem] = '\0';
   startedNem = false;
   endedNem = false;
 }
 if(startedisik && endedisik)
 {
   int value = atoi(msgisik);
   Serial.print("Sensor_ISIK:");
   Serial.print(value);
   Serial.print("\n");
  if(value>60){
    digitalWrite(isikPin,HIGH);
  }else{
    digitalWrite(isikPin,LOW);
  }
   indexisik = 0;
   msgisik[indexisik] = '\0';
   startedisik = false;
   endedisik = false;
 }
delay(1000);
}
