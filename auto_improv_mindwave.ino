#include <Mindwave.h>

Mindwave mindwave;

void onMindwaveData(){
  /*Serial.print("\tquality: ");
  Serial.print(mindwave.quality());
  Serial.print("\tattention: ");
  Serial.print(mindwave.attention());
  Serial.print("\tmeditation: ");
  Serial.print(mindwave.meditation());
  Serial.print("\tlast update: ");
  Serial.print(mindwave.lastUpdate());
  Serial.print("ms ago");
  Serial.println();*/
}

void setup() {
    Serial.begin(MINDWAVE_BAUDRATE);
}

void loop() {
        
mindwave.update(Serial,onMindwaveData);
   
// My code here 

         
        byte meditation_value = mindwave.meditation();
  //sa
          switch (meditation_value / 20)
          {
            case 1:
         
            {
              byte attention_value = mindwave.attention();
                switch(attention_value/20)
                {
                  case 1: 
                    {
                    playMidiNote(1,60,127);
                    delay(8000);
                    playMidiNote(1,60,0);
                    break;
                    }

                   case 2:
                    {
                    playMidiNote(1,60,127);
                    delay(4000);
                    playMidiNote(1,60,0);
                    break;
                    }

                   case 3:
                    {
                    playMidiNote(1,60,127);
                    delay(2000);
                    playMidiNote(1,60,0);
                    break;
                     
                    }

                   case 4:
                    {
                    playMidiNote(1,60,127);
                    delay(1000);
                    playMidiNote(1,60,0);
                    break;
                    }

                   case 5:

                    {
                    playMidiNote(1,60,127);
                    delay(500);
                    playMidiNote(1,60,0);
                    break;
                    }
                }  
                break;   
            }

  // re

           case 2:
            {
              byte attention_value = mindwave.attention();
                switch(attention_value/20)
                {
                  case 1: 
                    {
                      playMidiNote(1,62,127);
                      delay(8000);
                      playMidiNote(1,62,0);
                      break;
                    }

                   case 2:
                    {
                      playMidiNote(1,62,127);
                      delay(4000);
                      playMidiNote(1,62,0);
                      break;
                    }

                   case 3:
                    {
                      playMidiNote(1,62,127);
                      delay(2000);
                      playMidiNote(1,62,0);
                      break;
                     
                    }

                   case 4:
                    {
                      playMidiNote(1,62,127);
                      delay(1000);
                      playMidiNote(1,62,0);
                      break;
                    }

                   case 5:

                    {
                      playMidiNote(1,62,127);
                      delay(500);
                      playMidiNote(1,62,0);
                      break;
                    }
                }     
                break;
            }
            


    //ga

           case 3:
            {
              byte attention_value = mindwave.attention();
                switch(attention_value/20)
                {
                  case 1: 
                    {
                      playMidiNote(1,64,127);
                      delay(8000);
                      playMidiNote(1,64,0);
                      break;
                    }

                   case 2:
                    {
                      playMidiNote(1,64,127);
                      delay(4000);
                      playMidiNote(1,64,0);
                      break;
                    }

                   case 3:
                    {
                      playMidiNote(1,64,127);
                      delay(2000);
                      playMidiNote(1,64,0);
                      break;
                     
                    }

                   case 4:
                    {
                      playMidiNote(1,64,127);
                      delay(1000);
                      playMidiNote(1,64,0);
                      break;
                    }

                   case 5:

                    {
                      playMidiNote(1,64,127);
                      delay(500);
                      playMidiNote(1,64,0);
                      break;
                    }
                }   
                break;  
            }

          // pa

         case 4:
            {
              byte attention_value = mindwave.attention();
                switch(attention_value/20)
                {
                  case 1: 
                    {
                      playMidiNote(1,67,127);
                      delay(8000);
                      playMidiNote(1,67,0);
                      break;
                    }

                   case 2:
                    {
                      playMidiNote(1,67,127);
                      delay(4000);
                      playMidiNote(1,67,0);
                      break;
                    }

                   case 3:
                    {
                      playMidiNote(1,67,127);
                      delay(2000);
                      playMidiNote(1,67,0);
                      break;
                     
                    }

                   case 4:
                    {
                      playMidiNote(1,67,127);
                      delay(1000);
                      playMidiNote(1,67,0);
                      break;
                    }

                   case 5:

                    {
                      playMidiNote(1,67,127);
                      delay(500);
                      playMidiNote(1,67,0);
                      break;
                    }
                }   
                break;  
            }


           //Dha

           case 5:
            {
              byte attention_value = mindwave.attention();
                switch(attention_value/20)
                {
                  case 1: 
                    {
                      playMidiNote(1,69,127);
                      delay(8000);
                      playMidiNote(1,69,0);
                      break;
                    }

                   case 2:
                    {
                      playMidiNote(1,69,127);
                      delay(4000);
                      playMidiNote(1,69,0);
                      break;
                    }

                   case 3:
                    {
                      playMidiNote(1,69,127);
                      delay(2000);
                      playMidiNote(1,69,0);
                      break;
                     
                    }

                   case 4:
                    {
                      playMidiNote(1,69,127);
                      delay(1000);
                      playMidiNote(1,69,0);
                      break;
                    }

                   case 5:

                    {
                      playMidiNote(1,69,127);
                      delay(500);
                      playMidiNote(1,69,0);
                      break;
                    }
                }  
                break;  
            }


            //Sa

             case 0: 
            {
              byte attention_value = mindwave.attention();
                switch(attention_value/20)
                {
                  case 1: 
                    {
                      playMidiNote(1,72,127);
                      delay(8000);
                      playMidiNote(1,72,0);
                      break;
                    }

                   case 2:
                    {
                      playMidiNote(1,72,127);
                      delay(4000);
                      playMidiNote(1,72,0);
                      break;
                    }

                   case 3:
                    {
                      playMidiNote(1,72,127);
                      delay(2000);
                      playMidiNote(1,72,0);
                      break;
                     
                    }

                   case 4:
                    {
                      playMidiNote(1,72,127);
                      delay(1000);
                      playMidiNote(1,72,0);
                      break;
                    }

                   case 5:

                    {
                     playMidiNote(1,72,127);
                      delay(500);
                      playMidiNote(1,72,0);
                      break;
                    }
                }
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
  
  
