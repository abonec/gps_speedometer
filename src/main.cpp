#include <Arduino.h>
#include <gps.h>
#include <screen.h>

#define BUTTON 7
#define DISPLAY_MODES 2

// This custom version of delay() ensures that the tinyGPS object
// is being "fed". From the TinyGPS++ examples.

/* u8x8.begin() is required and will sent the setup/init sequence to the display */
int displayMode = 0;
void setup(void)
{
  initGPS();
  initScreen();
  Serial.begin(9600);
  pinMode(BUTTON, INPUT);
  while (!Serial)
    ;
  ;
  Serial.println(displayMode);
}

void loop(void)
{
  loopGPS();
  clearBuffer();
  setFont();
  if (displayMode == 0)
  {
    printGPSInfo();
  }
  else
  {
    printSpeed();
  }
  sendBuffer();
  if (!digitalRead(BUTTON))
  {
    if (displayMode >= DISPLAY_MODES - 1)
    {
      displayMode = 0;
    }
    else
    {
      displayMode++;
    }
    while (!digitalRead(BUTTON))
    {
      ;
    }
    clearDisplay();
  }
  // u8x8.drawString(0, 0, "Hello World!");
  // printGPSInfo();

  // // "Smart delay" looks for GPS data while the Arduino's not doing anything else
  // smartDelay(1000);
}