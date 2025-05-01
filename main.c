//#define SOILSENSEONE A0
//#define SOILSENSETWO  A1
//#define SOILSENSETH  A2
#define BUZZER  8
#define LEDO    9
#define LEDT    10
#define SWITCHO  7

void setup()
{
  Serial.begin( 9600 ) ;
  pinMode(BUZZER,OUTPUT) ;
  pinMode(LEDO,OUTPUT) ;
  pinMode(LEDT,OUTPUT) ;
  pinMode(SWITCHO,INPUT) ;
}


void Soilsense()
{
  unsigned int counter = 0, sensorValx = 0 , mappedValx = 0, x = 0;
  int sensorpins[3] = {A0, A1, A2} ;
  
  for(  x = 0; x < 3; x++ )
    {
      for ( counter = 0; counter < 5; counter++ )    // 60 readings * 500ms = 30 seconds
        {  
          digitalWrite(LEDO, HIGH) ;
          sensorValx = analogRead(sensorpins[x]) ;
          mappedValx = map(sensorValx, 0, 1023, 255, 0) ;
      
           Serial.print("Sensor ");
          Serial.print(x + 1);
          Serial.print(" reading: ");
          Serial.println(mappedValx) ;
          
          delay(3600) ;  
        }
        digitalWrite(LEDO,LOW) ;
        Serial.println(" ") ;
        delay(1000) ; 
    } 
}

void Buzzer()
{
 digitalWrite(BUZZER,HIGH) ;
  delay(3000) ;
 digitalWrite(BUZZER,LOW) ;
 
}  

void loop() 
{
  int buttonstate = 0 ;
  
  buttonstate = digitalRead(SWITCHO) ;

  if(buttonstate == HIGH)
  {
    Soilsense() ;
    delay(3600) ;
    Buzzer() ;
  }
  else
    digitalWrite(LEDT,HIGH) ;
}
