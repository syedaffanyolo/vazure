#include <SD.h>
#include "I2Cdev.h"
#include "vars.h"
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
Adafruit_BMP280 bmp;
Adafruit_MPU6050 mpu;
#include "func.h"
#include "bigbrain.h"
//huh??



void setup( ) 
{
  pinMode(r,OUTPUT);
    pinMode(g,OUTPUT);
      pinMode(b,OUTPUT);
  digitalWrite(r,HIGH);
   digitalWrite(g,HIGH);
    digitalWrite(b,HIGH);
     pinMode(buzz, OUTPUT);
     pinMode(py1,OUTPUT);
     pinMode(py2,OUTPUT);
    
 play_tune(oo7);


  //STARTUP
  
  Wire.begin();
  Serial.begin(115200);
 
delay(2000);
Serial.println("Hey, its the OnBoard Gordon Avionics, Ready for some flight checks");
delay(1000);

//LED

Serial.println("Led sequence, now.");
    digitalWrite(r,LOW);
     delay(500);
      digitalWrite(r,HIGH);
      digitalWrite(g,LOW);
    delay(500);
     digitalWrite(g,HIGH);
      digitalWrite(b,LOW);
      delay(500);
        digitalWrite(b,HIGH);
delay(1000);

//buzz
//Serial.println("buzz sequence, now.");

//BMP


 Serial.println(F("BMP280 test"));
 delay(1000);
  
  if (!bmp.begin()) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring or "
                      "try a different address!"));
    digitalWrite(r,HIGH);
    while (1) delay(10);
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); 

 Serial.print(F("Temperature = "));
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");


    Serial.print(F("Pressure = "));
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");

    Serial.print(F("Approx altitude = "));
    Serial.print(bmp.readAltitude(1013.25)); /* Adjusted to local forecast! */
    Serial.println(" m");
    
    Serial.println();
    digitalWrite(g,LOW);
    delay(1000);
     digitalWrite(g,HIGH);
    delay(2000);
groundAlt = bmp.readAltitude(1013.25);




 //IMU
 Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");
digitalWrite(g,LOW);
    delay(1000);
     digitalWrite(g,HIGH);
    delay(2000);
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  Serial.print("Accelerometer range set to: ");
  switch (mpu.getAccelerometerRange()) {
  case MPU6050_RANGE_2_G:
    Serial.println("+-2G");
    break;
  case MPU6050_RANGE_4_G:
    Serial.println("+-4G");
    break;
  case MPU6050_RANGE_8_G:
    Serial.println("+-8G");
    break;
  case MPU6050_RANGE_16_G:
    Serial.println("+-16G");
    break;
  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  Serial.print("Gyro range set to: ");
  switch (mpu.getGyroRange()) {
  case MPU6050_RANGE_250_DEG:
    Serial.println("+- 250 deg/s");
    break;
  case MPU6050_RANGE_500_DEG:
    Serial.println("+- 500 deg/s");
    break;
  case MPU6050_RANGE_1000_DEG:
    Serial.println("+- 1000 deg/s");
    break;
  case MPU6050_RANGE_2000_DEG:
    Serial.println("+- 2000 deg/s");
    break;
  }

  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.print("Filter bandwidth set to: ");
  switch (mpu.getFilterBandwidth()) {
  case MPU6050_BAND_260_HZ:
    Serial.println("260 Hz");
    break;
  case MPU6050_BAND_184_HZ:
    Serial.println("184 Hz");
    break;
  case MPU6050_BAND_94_HZ:
    Serial.println("94 Hz");
    break;
  case MPU6050_BAND_44_HZ:
    Serial.println("44 Hz");
    break;
  case MPU6050_BAND_21_HZ:
    Serial.println("21 Hz");
    break;
  case MPU6050_BAND_10_HZ:
    Serial.println("10 Hz");
    break;
  case MPU6050_BAND_5_HZ:
    Serial.println("5 Hz");
    break;
  }

  Serial.println("");
  delay(100);


 



  //SD CARD

  Serial.println(" SD card test, now...");
  delay(500);
//  SPI.setMOSI(0);
//  SPI.setMISO(1);
//  SPI.setSCK(20);

  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN,HIGH);
    SPI.begin();
  // we'll use the initialization code from the utility libraries
  // since we're just testing if the card is working!
  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed!");
    digitalWrite(r,LOW);
    while(1>0){
play_tune(oo7);
delay(300);
}
  }
 else {
    Serial.println("Wiring is correct and a card is present.");
    digitalWrite(g,LOW);
      delay(1000);
     digitalWrite(g,HIGH);
     // print the type of carz
    if (SD.remove("gor.csv") and SD.remove("gorFig.txt")){
      Serial.println("done");
    }else{
      Serial.println("no");
    }
  Serial.print("\nCard type: ");
  switch(card.type()) {
    case SD_CARD_TYPE_SD1:
      Serial.println("SD1");
      
      
    case SD_CARD_TYPE_SD2:
      Serial.println("SD2");
      
      
    case SD_CARD_TYPE_SDHC:
      Serial.println("SDHC");
      
      
    default:
       Serial.println("unknown");
     
      

  
    
     
   
   
  }


 //delay(3000);
  }

 
   

  
}



void loop() {



for(int i=0;i<1;i++){

//IMU


    //  Serial.println("IMU/MPU6050 test.../..");
  // set accelerometer range to +-8G
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

  // set gyro range to +- 500 deg/s
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);

  // set filter bandwidth to 21 Hz
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  delay(100);
    while(thres <= 20){
  sensors_event_t ac, gr, tempmpu;
  mpu.getEvent(&ac, &gr, &tempmpu);
  
  acelx = ac.acceleration.x;
  acely = ac.acceleration.y;
  acelz = ac.acceleration.z;

  gyrox = gr.gyro.x;
  gyroy = gr.gyro.y;
  gyroz = gr.gyro.z;

//  imutemp = tempmpu;
  
   groundAccerinY = ac.acceleration.y;
  Serial.print("Acceleration X: ");
  Serial.print(acelx);
  Serial.print(", Y: ");
  Serial.print(acely);
  Serial.print(", Z: ");
  Serial.print(acelz);
  Serial.println(" m/s^2");

  Serial.print("Rotation X: ");
  Serial.print(gyrox);
  Serial.print(", Y: ");
  Serial.print(gyroy);
  Serial.print(", Z: ");
  Serial.print(gyroz);
  Serial.println(" rad/s");

  Serial.print("Temperature: ");
  Serial.print(tempmpu.temperature);
  Serial.println(" degC");

  Serial.println("");
  delay(300);





thres = thres + 1;
  }
  sensors_event_t ac, gr, tempmpu;
  mpu.getEvent(&ac, &gr, &tempmpu);
  groundAccerinY = ac.acceleration.y;
  //Serial.println("this is pad accerelation in Y axis" +String(groundAccerinY));
   
    delay(2000);
     
}
  ready();
while (ison == true){
         
     // CHANGE SEENS FOR LAUNCH
      sensors_event_t ac, gr, tempmpu;
  mpu.getEvent(&ac, &gr, &tempmpu);
  
  // accelgyro.getAcceleration(&ax, &ay, &az);
   //accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  

  if(ac.acceleration.y > groundAccerinY + 1){
    digitalWrite(g,HIGH);
    digitalWrite(r,LOW);
    digitalWrite(b,LOW);
    digitalWrite(py2,LOW);
    flight = true;
    ison = false;
  }else{
     //digitalWrite(py2,LOW);
    digitalWrite(buzz,HIGH);
    delay(200);
    digitalWrite(buzz,LOW);
    delay(200);
    Serial.println(ac.acceleration.y);
  }
   }
    

//big brain logic stuff here


bigbrain();
  

while(1>0){
play_tune(oo7);
delay(300);
}
}
