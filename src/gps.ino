#include <SoftwareSerial.h>
#include <Wire.h>
#include <TinyGPS++.h> // Include the TinyGPS++ library
#include <helpers.h>
TinyGPSPlus gps;
static const int RXPin = 4, TXPin = 3;
SoftwareSerial ss(RXPin, TXPin);
static const uint32_t GPSBaud = 38400;

void initGPS()
{

    ss.begin(GPSBaud);
}
void loopGPS()
{
    while (ss.available() > 0)
    {
        int read = ss.read();
        // Serial.write(read);
        gps.encode(read);
    }
    if (millis() > 5000 && gps.charsProcessed() < 10)
    {
        drawLine(">> GPS error <<");
        while (true)
            ;
    }
}

void printGPSInfo()
{
    char buffer[16];
    resetLine();
    sprintf(buffer, "%02d:%02d:%02d", gps.time.hour(), gps.time.minute(), gps.time.second());
    addLine(buffer);
    sprintf(buffer, "Lat: %s", doubleToChar(gps.location.lat(), 4, 5));
    addLine(buffer);
    sprintf(buffer, "Lon: %s", doubleToChar(gps.location.lng(), 4, 5));
    addLine(buffer);
    sprintf(buffer, "Speed: %s", doubleToChar(gps.speed.kmph(), 4, 2));
    addLine(buffer);
    sprintf(buffer, "Course: %s", doubleToChar(gps.course.deg(), 4, 2));
    addLine(buffer);
    sprintf(buffer, "Satellites: %d", gps.satellites.value());
    addLine(buffer);
}
static void smartDelay(unsigned long ms)
{
    unsigned long start = millis();
    do
    {
        // If data has come in from the GPS module
        while (ss.available())
            Serial.println("available");
        gps.encode(ss.read()); // Send it to the encode function
                               // tinyGPS.encode(char) continues to "load" the tinGPS object with new
                               // data coming in from the GPS module. As full NMEA strings begin to come in
                               // the tinyGPS library will be able to start parsing them for pertinent info
    } while (millis() - start < ms);
}