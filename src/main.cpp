#include <Arduino.h>
#include <gps.h>
#include <screen.h>

#define BUTTON 7
#define DISPLAY_MODES 3



// This custom version of delay() ensures that the tinyGPS object
// is being "fed". From the TinyGPS++ examples.

/* u8x8.begin() is required and will sent the setup/init sequence to the display */
void setup(void)
{
  initGPS();
  initScreen();
  Serial.begin(9600);
  pinMode(BUTTON, INPUT);
  while (!Serial) ;;
}

int displayMode = 0;
void loop(void)
{
  loopGPS();
  printGPSInfo();
  // if (!digitalRead(BUTTON))
  // {
  //   if (displayMode >= DISPLAY_MODES)
  //   {
  //     displayMode = 0;
  //   }
  //   else
  //   {
  //     displayMode++;
  //   }
  //   char ch[2];
    
  //   drawLine("");
  // }
  // u8x8.drawString(0, 0, "Hello World!");
  // printGPSInfo();

  // // "Smart delay" looks for GPS data while the Arduino's not doing anything else
  // smartDelay(1000);
}