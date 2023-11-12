#include <Firmata.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
int lastLine = 1;
int numRows = 2;
int numCols = 16;

void stringDataCallback(char *stringData){
   if ( lastLine ) {
     lastLine = 0;
     lcd.clear();
   } else {
     lastLine = 1;
     lcd.noCursor();
     delay(500);
     lcd.cursor();
     delay(500);
   }
   lcd.print(stringData);
}

void setup() {
  lcd.begin(numCols,numRows);
  Firmata.setFirmwareVersion( FIRMATA_MAJOR_VERSION, FIRMATA_MINOR_VERSION );
  Firmata.attach( STRING_DATA, stringDataCallback);
  Firmata.begin();  
}

void loop() {
  while ( Firmata.available() ) {
    Firmata.processInput();
  }
}
