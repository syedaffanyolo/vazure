//VARS 
int currenttime = 0;
float acelx = 0;
float acely = 0;
float acelz = 0;
float gyrox= 0;
float gyroy = 0;
float gyroz = 0;
float imutemp = 0;
bool touchdownloop = true;
bool potensialApogee = true;
bool loo = true;
int stime = 0;
int  ctone = 3830;  // 261 Hz
int  dtone = 3400;  // 294 Hz
int  etone = 3038;  // 329 Hz
int buzz = 16;
#define qt     170
#define oo7 220    // 007 jingle
#define EN    330     // 658 Hz
#define FS    370     // 740 Hz
#define GN    392     // 784 Hz
long elapsedtime = 0;
long duration = 500000;
bool oneloop = true;
int consttime = 0;
bool figures = true;
float tdis = 0;
float tspeed = 0;
float ttime = 0;
int py1 = 8;
int py2 = 7;
bool tt = true;
float filterroll,filterpitch,filteryaw;
float gyroAngleX;
float gyroAngleY;
float elaptime = 0;
int crtime = 0;
int prevtime = 0;
float groundAlt = 0;
bool donee = false;
bool la = false;
bool flight = false;
bool ison = true;
const float groundAltcc = 0;
double timee = millis();
int CS_PIN = 3;  
int thres = 10;
//SoftSPI mySPI(0, 1, 20); 
File myFile;
File figurefile;
Sd2Card card;
SdVolume volume;
SdFile root;
const int chipSelect = 3;
float heading;
int groundAccerinY;                                                                                                                                                                                                    
float alt = 0;
int r = 21;
int g = 15;
int b = 2;
float w = 0;
float x = 0;
float y = 0;
float z = 0;
float yaw = 0;
float pitch = 0;
float roll = 0;
