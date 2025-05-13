#include <EEPROM.h>

#define BUZZER  8
#define LEDO    9
#define LEDT    10
#define SWITCHO  7
//Soil Sensors added from A0 to A2

int EEPROMadd ;

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

          if ( EEPROMadd < EEPROM.length() ) 
          {
            EEPROM.put( EEPROMadd, mappedValx ) ;
            EEPROMadd++ ;
          }
          else
            Serial.println("EEPROM address full") ;
          
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

void ReadEEPROMData()
{
  int counter = 0, value = 0 ;
  
  Serial.println("Reading EEPROM values") ;
  for( counter = 0; counter <= EEPROM.length() ; counter++ )
  {
    EEPROM.get(counter, value);
    Serial.print("EEPROM [");
    Serial.print(counter);
    Serial.print("] = ");
    Serial.println(EEPROM.read(counter));    
  }
}

void loop() 
{
  int buttonstate = 0 ;
  String input ;
  
  buttonstate = digitalRead(SWITCHO) ;

  if(buttonstate == HIGH)
  {
    Soilsense() ;
    delay(3600) ;
    Buzzer() ;
  }
  else
    digitalWrite(LEDT,HIGH) ;

  if( Serial.available() > 0 )
  {
    input = Serial.readStringUntil("\n") ;
    input.trim() ;  //ignores spaces or newlines

    if( input.equalsIgnoreCase("readeeprom") )
    ReadEEPROMData() ;
 } 
}
