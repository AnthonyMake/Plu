#define potTempo A2
#define boton 3
#define potPower A0

unsigned long startTime;
unsigned long elapsedTime = 0;
unsigned long Tempo;
unsigned long maxTempMillis = 28800000;

void setup() {
  pinMode(boton,INPUT_PULLUP);
  pinMode(9,OUTPUT);
}

void loop() {
  if(digitalRead(boton)){ 
    delay(10);
    
    while(digitalRead(boton)){
      delay(10);
    }
    Tempo = analogRead(potTempo)/1023.0 * maxTempMillis;
    
    elapsedTime = 0;
    startTime = millis();
      
    while(elapsedTime < Tempo){
      oneCycle();
      elapsedTime = millis() - startTime;
      //Serial.println(elapsedTime); 
        if (digitalRead(boton)){
          elapsedTime = Tempo + 10;
          while(digitalRead(boton)){}
          delay(10);
      }
    }    
  }
}

void oneCycle() {
  int value = analogRead(potPower);
  
  
  value = map(value,0,1023,200,1023);
    if( random(1000) < map(value,200,1023,0,200)){
        digitalWrite(9,HIGH);
        int randelay = random(map(value,200,1023,0,100)); 
        delayMicroseconds(randelay);
        digitalWrite(9,LOW);
        delayMicroseconds(randelay);
    }

}
