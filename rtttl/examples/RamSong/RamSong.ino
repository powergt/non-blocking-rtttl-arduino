#include <rtttl.h>

//note this is not declared in PROGMEM
const char song[] = "AxelF:d=4,o=5,b=125:32p,8g,8p,16a#.,8p,16g,16p,16g,8c6,8g,8f,8g,8p,16d.6,8p,16g,16p,16g,8d#6,8d6,8a#,8g,8d6,8g6,16g,16f,16p,16f,8d,8a#,2g,p,SS,16f6,8d6,8c6,8a#,g,8a#.,16g,16p,16g,8c6,8g,8f,g,8d.6,16g,16p,16g,8d#6,8d6,8a#,8g,8d6,8g6,16g,16f,16p,16f,8d,8a#,2g";

unsigned long printedTime = -1;
unsigned long printedPeriod = 500;

RamSong player(13);

void setup(void)
{
  Serial.begin(115200);
  player.setSong(song);
}

void loop(void)
{
  
  //play the tune
  while(player.tick()){
    tryPrint("First Play");
  }

  Serial.println("Song auto-rewound");

  //play the tune again
  while(player.tick()){
    tryPrint("Second Play");
  }

  Serial.println("Play has ended");    
  while(true){
    //do nothing
  }
  
}

void tryPrint(String msg){
  if(millis() - printedTime > printedPeriod){
    Serial.println(msg);
    printedTime = millis();
  }
}
