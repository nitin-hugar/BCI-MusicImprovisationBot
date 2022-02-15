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
        
 
          switch(meditation/5)
          {
              
                    case 1:{
                    play_note(60);
                    break;
                    }

                    case 2:{
                    play_note(62);
                    break;
                    }
                    case 3:{
                    play_note(64);
                    break;
                    }
                    case 4:{
                    play_note(66);
                    break;
                    }
                    case 5:{
                    play_note(67);
                    break;
                    }
                    case 6:{
                    play_note(69);
                    break;
                    }
                    case 7:{
                    play_note(71);
                    break;
                    }
                    case 8:{
                    play_note(72);
                    break;
                    }
                    case 9:{
                    play_note(60);
                    break;
                    }
                    case 10:{
                    play_note(62);
                    break;
                    }
                    case 11:{
                    play_note(64);
                    break;
                    }
                    case 12:{
                    play_note(66);
                    break;
                    }
                    case 13:{
                    play_note(67);
                    break;
                    }
                    case 14:{
                    play_note(68);
                    break;
                    }
                    case 15:{
                    play_note(71);
                    break;
                    }
                    case 16:{
                    play_note(72);
                    break;
                    }
                    case 17:{
                    play_note(64);
                    break;
                    }
                    case 18:{
                    play_note(66);
                    break;
                    }
                    case 19:{
                    play_note(67);
                    break;
                    }
                    case 20:{
                    play_note(72);
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

    
 void play_note(byte pitch){
   switch(attention/20)
                {
                  case 1: 
                    {
                       time_now = millis();
                       playMidiNote(1,pitch,127);                         
                       while(millis() < time_now + period){}
                       playMidiNote(1,pitch,0);
                      break;
                    }

                   case 2:
                    { 
                      time_now = millis();
                      playMidiNote(1,pitch,127);
                      while(millis() < time_now + period2){}
                      playMidiNote(1,pitch,0);
                      break;
                    }

                   case 3:
                    {
                      time_now = millis();
                      playMidiNote(1,pitch,127);
                      while(millis() < time_now + period3){}
                      playMidiNote(1,pitch,0);
                      break;
                     
                    }

                   case 4:
                    {
                      time_now = millis();
                      playMidiNote(1,pitch,127); 
                      while(millis() < time_now + period2){}
                      playMidiNote(1,pitch,0);
                      break;
                    }

                   case 5:

                    {
                      time_now = millis();
                      playMidiNote(1,pitch,127);
                      while(millis() < time_now + period3){}
                      playMidiNote(1,pitch,0);
                      break;
                    }
                }  
 }



void playMidiNote(byte channel, byte note, byte velocity)
{
  byte midiMessage= 0x90;
  Serial.write(midiMessage);
  Serial.write(note);
  Serial.write(velocity);
}
