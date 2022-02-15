
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#define LED 13
#define BAUDRATE 57600
#define DEBUGOUTPUT 0
#define SERVOMIN  150 
#define SERVOMAX  600 
#define USMIN  611
#define USMAX  2441 
#define FREQ 60 

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

uint8_t servonum = 0;

#define powercontrol 10


byte generatedChecksum = 0;
byte checksum = 0; 
int payloadLength = 0;
byte payloadData[64] = {0};
byte poorQuality = 0;
byte attention = 0;
byte meditation = 0;
int period = 4900;
int period2 = 3900;
int period3 = 1900;
unsigned long time_now = 0;
long lastReceivedPacket = 0;
boolean bigPacket = false;

void setup() 

{
  pinMode(LED, OUTPUT);
  Serial.begin(BAUDRATE);  // USB
  Serial.println("8 channel Servo test!");
  pwm.begin();
  pwm.setPWMFreq(FREQ);  // Analog servos run at ~60 Hz updates
  delay(10);
}

byte ReadOneByte() 

{
  int ByteRead;
  while(!Serial.available());
  ByteRead = Serial.read();

#if DEBUGOUTPUT  
  Serial.print((char)ByteRead);   
#endif

  return ByteRead;
}


void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  
  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= FREQ;   // Analog servos run at ~60 Hz updates
  Serial.print(pulselength); Serial.println(" us per period"); 
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit"); 
  pulse *= 1000000;  // convert input seconds to us
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}

void loop() 

{

  if(ReadOneByte() == 170) 
  {
    if(ReadOneByte() == 170) 
    {
        payloadLength = ReadOneByte();
      
        if(payloadLength > 169)                      
        return;
        generatedChecksum = 0;        
        for(int i = 0; i < payloadLength; i++) 
        {  
        payloadData[i] = ReadOneByte();            
        generatedChecksum += payloadData[i];
        }   

        checksum = ReadOneByte();                           
        generatedChecksum = 255 - generatedChecksum;   

        if(checksum == generatedChecksum) 
        {    
          poorQuality = 200;
          attention = 0;
          meditation = 0;

          for(int i = 0; i < payloadLength; i++) 
          {                                         
          switch (payloadData[i]) 
          {
          case 2:
            i++;            
            poorQuality = payloadData[i];
            bigPacket = true;            
            break;
          case 4:
            i++;
            attention = payloadData[i];                        
            break;
          case 5:
            i++;
            meditation = payloadData[i];
            break;
          case 0x80:
            i = i + 3;
            break;
          case 0x83:
            i = i + 25;      
            break;
          default:
            break;
          } // switch
        } // for loop

#if !DEBUGOUTPUT

      

        if(bigPacket) 
        {
          if(poorQuality == 0)
             digitalWrite(LED, HIGH);
          else
            digitalWrite(LED, LOW);
           

 //Code for Robot//
  
          switch(meditation/5)
          {

              
                    case 0:{
                    play_note(1);
                    break;
                    }
                    
                    case 1:{
                    play_note(2);
                    break;
                    }

                    case 2:{
                    play_note(3);
                    break;
                    }
                    case 3:{
                    play_note(4);
                    break;
                    }
                    case 4:{
                    play_note(5);
                    break;
                    }
                    case 5:{
                    play_note(6);
                    break;
                    }
                    case 6:{
                    play_note(7);
                    break;
                    }
                    case 7:{
                    play_note(8);
                    break;
                    }
                    case 8:{
                    play_note(1);
                    break;
                    }
                    case 9:{
                    play_note(2);
                    break;
                    }
                    case 10:{
                    play_note(3);
                    break;
                    }
                    case 11:{
                    play_note(4);
                    break;
                    }
                    case 12:{
                    play_note(5);
                    break;
                    }
                    case 13:{
                    play_note(6);
                    break;
                    }
                    case 14:{
                    play_note(7);
                    break;
                    }
                    case 15:{
                    play_note(8);
                    break;
                    }
                    case 16:{
                    play_note(1);
                    break;
                    }
                    case 17:{
                    play_note(2);
                    break;
                    }
                    case 18:{
                    play_note(3);
                    break;
                    }
                    case 19:{
                    play_note(4);
                    break;
                    }
                    case 20:{
                    play_note(5);
                    break;
                    }
            
          }
       
     }
#endif        
        bigPacket = false;        
      }
      else {
        // Checksum Error
      }  // end if else for checksum
    } // end if read 0xAA byte
  } // end if read 0xAA byte
}
    
 void play_note(byte pitch)
 {
   switch(attention/20)
                {
                  case 1: 
                    {
                      pwm.setPWM(pitch , 0, 500);
                      delay(400);
                      pwm.setPWM(pitch, 0, 350);
                      break;
                    }

                   case 2:
                    { 
                       pwm.setPWM(pitch , 0, 500);
                      delay(800);
                      pwm.setPWM(pitch, 0, 350);
                      break;
                    }

                   case 3:
                    {
                      pwm.setPWM(pitch , 0, 500);
                      delay(1200);
                      pwm.setPWM(pitch, 0, 350);
                      break;
                     
                    }

                   case 4:
                    {
                      pwm.setPWM(pitch , 0, 500);
                      delay(800);
                      pwm.setPWM(pitch, 0, 350);
                      break;
                    }

                   case 5:

                    {
                     pwm.setPWM(pitch , 0, 500);
                      delay(400);
                      pwm.setPWM(pitch, 0, 350);
                      break;
                    }
                }  
            }



  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
