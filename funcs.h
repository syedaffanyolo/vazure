//functions 

#include "math.h"
//#include <vector_type.h>


void fig(){
    tdis = alt - groundAlt;
  ttime = (currenttime - stime)/1000;
  tspeed = tdis/ttime;
  figurefile = SD.open("gorFig.txt",FILE_WRITE);
  if(figurefile){
    figurefile.print("total distance traveled ");
     figurefile.print(tdis);
      figurefile.print("m ");
      figurefile.println("total time traveled ");
     figurefile.print(ttime);
      figurefile.print("sec ");
      figurefile.println("speed ");
     figurefile.print(tspeed);
      figurefile.print("m/s ");
      figurefile.println("apogee timing ");
      figurefile.print(currenttime);
      figurefile.print(" miliseconds into flight");
      figurefile.close();
}
}

void storeData(){
   float alt = bmp.readAltitude(1013.25); 
   
//Serial.println(millis());
while(tt==true){
stime = millis();

tt = false;
}
prevtime = crtime;
 crtime = millis();
  elaptime = (crtime - prevtime) / 1000;
 currenttime = crtime;
  float pres = bmp.readPressure();
   float temp = bmp.readTemperature();
   //  accelgyro.getAcceleration(&ax, &ay, &az);
  sensors_event_t ac, gr, tempmpu;
  mpu.getEvent(&ac, &gr, &tempmpu);
  
roll = gr.gyro.y;
pitch = gr.gyro.x;
yaw = gr.gyro.z;

//  gyroAngleX = gyroAngleX + gr.gyro.x * elaptime; 
//  gyroAngleY = gyroAngleY + gr.gyro.y * elaptime;
//  filteryaw =  yaw + gr.gyro.z * elaptime;
Serial.print(crtime);
Serial.print(",");
Serial.print(gr.gyro.x);
Serial.print(",");
//  // Complementary filter - combine acceleromter and gyro angle values
//  filterroll = 0.96 * gyroAngleX + 0.04 * roll;
//  filterpitch = 0.96 * gyroAngleY + 0.04 * pitch;
//Serial.print(" pitch: ");
Serial.print(gr.gyro.y);
Serial.print(",");
//Serial.print(" roll: ");
Serial.println(gr.gyro.z);

 myFile = SD.open("gor.csv",FILE_WRITE);
    String dataString = String(alt);
    String dataStringtimeee = String(crtime);
    String dataString2 = String(ac.acceleration.y);
    String dataString3 = String(ac.acceleration.x);
    String dataString4 = String(ac.acceleration.z);
    String dataString5 = String(temp);
    String dataString6 = String(pres);
    String dataString7 = String(gr.gyro.x);
    String dataString8 = String(gr.gyro.y);
    String dataString9 = String(gr.gyro.z);
    String dataString10 = String(pitch);
    String dataString11 = String(roll);
    String dataString12 = String(yaw);
    //Serial.println("this is current altccy" + String(ac.acceleration.y));
   if (myFile) {
            if (la == false){
            myFile.println("timeee,alt,accy,accx,accz,gyx,gyy,gyz,temp,pres,pitch,yaw,roll");
            la = true;
            }
            myFile.print(dataStringtimeee + ",");
            myFile.print(dataString + ",");
            myFile.print(dataString2 + ",");          
            myFile.print(dataString3 + ",");            
            myFile.print(dataString4 + ",");           
            myFile.print(dataString7 + ",");            
            myFile.print(dataString8 + ",");
            myFile.print(dataString9 + ","); 
            myFile.print(dataString5 + ",");        
            myFile.print(dataString6 + ",");
            myFile.print(dataString10 + ",");
            myFile.print(dataString12 + ",");   
            myFile.print(dataString11);
            myFile.println();       
            myFile.close();
          }  
          else {
            Serial.println("error opening gor.csv");
          }
}



void touchdownCheck(){
   alt = bmp.readAltitude(1013.25);
   
  if (alt <= groundAlt + 0.5){
       digitalWrite(r,LOW);
  digitalWrite(b,LOW);
  digitalWrite(g,LOW);
  myFile.close();
    flight = false;
    touchdownloop = false;
   
  }else{
    storeData();
  }
  
}



void testTrueApogee(){
  sensors_event_t ac, gr, tempmpu;
  mpu.getEvent(&ac, &gr, &tempmpu);
  int arr[] = {0};
  
    for(int i=0;i<2;i++){
      delay(200); // this is where there are delays in data while apogge code.
      arr[i] = ac.acceleration.y;
}

int apcheck1  = arr[0]; 
int apcheck2  = arr[1]; 

  if (apcheck1 < 1 and apcheck2 < 1 ){
  
    
      digitalWrite(r,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(g,LOW);

  while(donee == false){
digitalWrite(buzz,HIGH);
delay(200);
digitalWrite(buzz,LOW);
fig();
 //here is ejection charge sequence
//aaaaaaaa fuck
 donee = true;
  }
    while(touchdownloop == true){
  int timeafap = millis();
    while(oneloop == true){
      consttime = timeafap;
      oneloop = false;
    }
  if (timeafap/1000 >= (consttime/1000) + 5){
     digitalWrite(py1,LOW);
  }else{
     digitalWrite(py1,HIGH);
  }
      touchdownCheck();

       

  }


    }
 
}






void potensialApogeefunc(){
    sensors_event_t ac, gr, tempmpu;
  mpu.getEvent(&ac, &gr, &tempmpu);
   if (ac.acceleration.y < 1 ){
    
      testTrueApogee();
      
   }
}
