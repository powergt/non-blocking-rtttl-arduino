#include <Tone.h> //the external Tone library is used 
#include <rtttl.h>

const int pinSpeaker = 13;
const int octave = 0;

const char song_P[] PROGMEM = "Ghostbusters:d=4,o=5,b=180:4c5,4c5,8e5,8f5,8g5,8p, 4a#5,4a#5,4f5,4f5,4c5,4c5,8e5,8f5,8g5,8p,4a#5,4a#5,4f5";


unsigned long printTimestamp = -1;
unsigned long printPeriod = 500;

Rtttl player;

void setup(void)
{
  Serial.begin(115200);
  player.begin(pinSpeaker);
  player.load(song_P, 0, true);
}

void loop(void)
{
  while(player.tick(0, true)){
    
    delay(1);
    
    //debugging
    if(millis() - printTimestamp > printPeriod){
      Serial.println("Song is continuing");  
      printTimestamp = millis();
    } 
    
  }
  
  //debugging
  while(true){
    if(millis() - printTimestamp > printPeriod){
      Serial.println("Song has finished");
      printTimestamp = millis();
    } 
  }
  
}
