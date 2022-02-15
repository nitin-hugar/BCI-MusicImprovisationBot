#define LED 13
#define BAUDRATE 57600
#define DEBUGOUTPUT 0

#define powercontrol 10

// checksum variables
byte generatedChecksum = 0;
byte checksum = 0; 
int payloadLength = 0;
byte payloadData[64] = {0};
byte poorQuality = 0;
byte attention = 0;
byte meditation = 0;
int period = 3900;
int period2 = 2900;
int period3 = 900;
unsigned long time_now = 0;

// system variables
long lastReceivedPacket = 0;
boolean bigPacket = false;

//////////////////////////
// Microprocessor Setup //
//////////////////////////
void setup() 

{
  pinMode(LED, OUTPUT);
  Serial.begin(BAUDRATE);           // USB
}

////////////////////////////////
// Read data from Serial UART //
////////////////////////////////
byte ReadOneByte() 

{
  int ByteRead;
  while(!Serial.available());
  ByteRead = Serial.read();

#if DEBUGOUTPUT  
  Serial.print((char)ByteRead);   // echo the same byte out the USB serial (for debug purposes)
#endif

  return ByteRead;
}


/////////////
//MAIN LOOP//
/////////////
void loop() 

{
  // Look for sync bytes
  if(ReadOneByte() == 170) 
  {
    if(ReadOneByte() == 170) 
    {
        payloadLength = ReadOneByte();
      
        if(payloadLength > 169)                      //Payload length can not be greater than 169
        return;
        generatedChecksum = 0;        
        for(int i = 0; i < payloadLength; i++) 
        {  
        payloadData[i] = ReadOneByte();            //Read payload into memory
        generatedChecksum += payloadData[i];
        }   

        checksum = ReadOneByte();                      //Read checksum byte from stream      
        generatedChecksum = 255 - generatedChecksum;   //Take one's compliment of generated checksum

        if(checksum == generatedChecksum) 
        {    
          poorQuality = 200;
          attention = 0;
          meditation = 0;

          for(int i = 0; i < payloadLength; i++) 
          {                                          // Parse the payload
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

        // *** Add your code here ***

        if(bigPacket) 
        {
          if(poorQuality == 0)
             digitalWrite(LED, HIGH);
          else
            digitalWrite(LED, LOW);


// My code here 
        
  //sa
          switch(meditation/20)
          {
       
            case 1:
         
            {
                switch(attention/20)
                {
                  case 1: 
                    {
                       time_now = millis();
                      playMidiNote(1,60,127);
                          
                        while(millis() < time_now + period){}
                      playMidiNote(1,60,0);
                      break;
                    }

                   case 2:
                    { 
                      time_now = millis();
                      playMidiNote(1,60,127);
                      while(millis() < time_now + period2){}
                      playMidiNote(1,60,0);
                      break;
                    }

                   case 3:
                    {
                      time_now = millis();
                      playMidiNote(1,60,127);
                      
                          while(millis() < time_now + period3){}
                      playMidiNote(1,60,0);
                      break;
                     
                    }

                   case 4:
                    {
                      time_now = millis();
                      playMidiNote(1,60,127);
                      
                        while(millis() < time_now + period2){}
                      playMidiNote(1,60,0);
                      break;
                    }

                   case 5:

                    {
                      time_now = millis();
                      playMidiNote(1,60,127);
                       
                          while(millis() < time_now + period3){}
                      playMidiNote(1,60,0);
                      break;
                    }
                }  
                break;   
            }

  // re

           case 2:
            {
             
                switch(attention/20)
                {
                  case 1: 
                    {
                      time_now = millis();
                      playMidiNote(1,62,127);
                          
                          while(millis() < time_now + period){}
                      playMidiNote(1,62,0);
                      break;
                    }

                   case 2:
                    {
                      time_now = millis();
                      playMidiNote(1,62,127);
                        
                        while(millis() < time_now + period2){}
                      playMidiNote(1,62,0);
                      break;
                    }

                   case 3:
                    {
                      time_now = millis();
                      playMidiNote(1,62,127);
                       
                          while(millis() < time_now + period3){}
                      playMidiNote(1,62,0);
                      break;
                     
                    }

                   case 4:
                    {
                      time_now = millis();
                      playMidiNote(1,62,127);
                      
                        while(millis() < time_now + period2){}
                      playMidiNote(1,62,0);
                      break;
                    }

                   case 5:

                    {
                      time_now = millis();
                      playMidiNote(1,62,127);
                       
                          while(millis() < time_now + period3){}
                      playMidiNote(1,62,0);
                      break;
                    }
                }     
                break;
            }
            


    //ga

           case 3:
            {
             
                switch(attention/20)
                {
                  case 1: 
                    {
                      time_now = millis();
                      playMidiNote(1,64,127);
                          
                          while(millis() < time_now + period){}
                      playMidiNote(1,64,0);
                      break;
                    }

                   case 2:
                    {
                      time_now = millis();
                      playMidiNote(1,64,127);
                       
                        while(millis() < time_now + period2){}
                      playMidiNote(1,64,0);
                      break;
                    }

                   case 3:
                    {
                      time_now = millis();
                      playMidiNote(1,64,127);
                       
                          while(millis() < time_now + period3){}
                      playMidiNote(1,64,0);
                      break;
                     
                    }

                   case 4:
                    {
                      time_now = millis();
                      playMidiNote(1,64,127);
                      while(millis() < time_now + period3){}
                      playMidiNote(1,64,0);
                      break;
                    }

                   case 5:

                    {
                      time_now = millis();
                      playMidiNote(1,64,127);
                       
                          while(millis() < time_now + period3){}
                      playMidiNote(1,64,0);
                      break;
                    }
                }   
                break;  
            }

          // pa

         case 4:
            {
             
                switch(attention/20)
                {
                  case 1: 
                    {
                      time_now = millis();
                      playMidiNote(1,67,127);
                          
                          while(millis() < time_now + period){}
                      playMidiNote(1,67,0);
                      break;
                    }

                   case 2:
                    {
                      time_now = millis();
                      playMidiNote(1,67,127);
                       
                        while(millis() < time_now + period2){}
                      playMidiNote(1,67,0);
                      break;
                    }

                   case 3:
                    {
                      time_now = millis();
                      playMidiNote(1,67,127);
                       
                          while(millis() < time_now + period3){}
                      playMidiNote(1,67,0);
                      break;
                     
                    }

                   case 4:
                    {
                      time_now = millis();
                      playMidiNote(1,67,127);
                      
                        while(millis() < time_now + period2){}
                      playMidiNote(1,67,0);
                      break;
                    }

                   case 5:

                    {
                      time_now = millis();
                      playMidiNote(1,67,127);
                       
                          while(millis() < time_now + period3){}
                      playMidiNote(1,67,0);
                      break;
                    }
                }   
                break;  
            }


           //Dha

           case 5:
            {
             
                switch(attention/20)
                {
                  case 1: 
                    {
                      time_now = millis();
                      playMidiNote(1,69,127);
                          
                          while(millis() < time_now + period){}
                      playMidiNote(1,69,0);
                      break;
                    }

                   case 2:
                    {
                      time_now = millis();
                      playMidiNote(1,69,127);
                       
                        while(millis() < time_now + period2){}
                      playMidiNote(1,69,0);
                      break;
                    }

                   case 3:
                    {
                      time_now = millis();
                      playMidiNote(1,69,127);
                       
                          while(millis() < time_now + period3){}
                      playMidiNote(1,69,0);
                      break;
                     
                    }

                   case 4:
                    {
                      time_now = millis();
                      playMidiNote(1,69,127);
                     
                        while(millis() < time_now + period2){}
                      playMidiNote(1,69,0);
                      break;
                    }

                   case 5:

                    {
                      time_now = millis();
                      playMidiNote(1,69,127);
                       
                          while(millis() < time_now + period3){}
                      playMidiNote(1,69,0);
                      break;
                    }
                }  
                break;  
            }


            //Sa

             case 0: 
            {
             
                switch(attention/20)
                {
                  case 1: 
                    {
                      time_now = millis();
                      playMidiNote(1,72,127);
                          
                          while(millis() < time_now + period){}
                      playMidiNote(1,72,0);
                      break;
                    }

                   case 2:
                    {
                      time_now = millis();
                      playMidiNote(1,72,127);
                       
                        while(millis() < time_now + period2){}
                      playMidiNote(1,72,0);
                      break;
                    }

                   case 3:
                    {
                      time_now = millis();
                      playMidiNote(1,72,127);
                       
                          while(millis() < time_now + period3){}
                      playMidiNote(1,72,0);
                      break;
                     
                    }

                   case 4:
                    {
                      time_now = millis();
                      playMidiNote(1,72,127);
                     
                        while(millis() < time_now + period2){}
                      playMidiNote(1,72,0);
                      break;
                    }

                   case 5:

                    {
                      time_now = millis();
                     playMidiNote(1,72,127);
                       
                          while(millis() < time_now + period3){}
                      playMidiNote(1,72,0);
                      break;
                    }
                }
                break;          
            }                  
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

void playMidiNote(byte channel, byte note, byte velocity)
{
  byte midiMessage= 0x90;
  Serial.write(midiMessage);
  Serial.write(note);
  Serial.write(velocity);
}
