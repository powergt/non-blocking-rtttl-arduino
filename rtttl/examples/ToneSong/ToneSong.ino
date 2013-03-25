//Identical to ProgmemSong.pde 
//except the external Tone library is used
#include <Tone.h> 

#include <rtttl.h>

const char song_P[] PROGMEM = "PacMan:b=160:32b,32p,32b6,32p,32f#6,32p,32d#6,32p,32b6,32f#6,16p,16d#6,16p,32c6,32p,32c7,32p,32g6,32p,32e6,32p,32c7,32g6,16p,16e6,16p,32b,32p,32b6,32p,32f#6,32p,32d#6,32p,32b6,32f#6,16p,16d#6,16p,32d#6,32e6,32f6,32p,32f6,32f#6,32g6,32p,32g6,32g#6,32a6,32p,32b.6";

unsigned long printedTime = -1;
unsigned long printedPeriod = 500;

ProgmemSong player(13);

void setup(void)
{
  Serial.begin(115200);
  player.setSong(song_P);
}

void loop(void)
{
  
  //play the tune
  while(player.tick()){
    tryPrint("First Play");
  }

  Serial.println("Song rewound automatically");

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
