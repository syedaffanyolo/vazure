
//#include "vars.h"
//ok

void ToneOut(int pitch, int duration){  // pitch in Hz, duration in ms
  int delayPeriod;
  long cycles, i;

  //pinMode(buzz, OUTPUT);           // turn on output pin
  delayPeriod = (500000 / pitch) - 7;   // calc 1/2 period in us -7 for overhead
  cycles = ((long)pitch * (long)duration) / 1000; // calc. number of cycles for loop

  for (i=0; i<= cycles; i++){           // play note for duration ms 
    digitalWrite(buzz, HIGH); 
    delayMicroseconds(delayPeriod);
    digitalWrite(buzz, LOW); 
    delayMicroseconds(delayPeriod - 1); // - 1 to make up for digitaWrite overhead
  }
  //pinMode(buzz, INPUT);            // shut off pin to avoid noise from other operations
}

void ready(){
 digitalWrite(r,LOW);
   digitalWrite(g,LOW);
   Serial.println("Avionics ready! go for flight!");
  for(int i=0;i<=9;i++){
     digitalWrite(buzz,HIGH);
   delay(500);
   digitalWrite(buzz,LOW);
   delay(500);
   
  }
 
  
   //10 SECOND TIMER TILL IGNITION
   
 //add a func for flight abort after 5 sec.
  
    digitalWrite(py2,HIGH);

}
void play_tune(int tune){               // play a tune . . .
  switch (tune) {                       // a case for each tune 
  case oo7:                             // 007  E, F#, G (mult by 2 for next higher octave)
    ToneOut(EN*2,qt);                    
    ToneOut(FS*2,qt);
    ToneOut(GN*2,qt);
    delay(300);
    break;
  }
}
