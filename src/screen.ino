#include <U8x8lib.h>
#include <U8g2lib.h>
#include <SPI.h>
// U8X8_SH1106_128X64_NONAME_HW_I2C u8x8(U8X8_PIN_NONE);
U8G2_SH1106_128X64_NONAME_F_2ND_HW_I2C u8g2(U8G2_R0);
void initScreen()
{
    // u8x8.begin();
    // u8x8.setFont(u8x8_font_artossans8_r);
    u8g2.begin();
}
int line = 8;
void resetLine()
{
    line = 8;
}
void firstPage()
{
    u8g2.firstPage();
    u8g2.setFont(u8g_font_courB08);
}
uint8_t nextPage()
{
    return u8g2.nextPage();
}
int font_size = 8;
void addLine(char *val)
{
    // if (line >= 8)
    // {
    //     resetLine();
    // }
    char result[16];
    // sprintf(result, "%-16s", val);
    sprintf(result, "%s", val);
    line += font_size;
    u8g2.drawStr(0, line, result);
}

void drawLine(char *val)
{
    resetLine();
    printLine(val);
}
void printLine(char *val)
{
    u8g2.drawStr(0, 3, val);
}

void clearDisplay()
{
    u8g2.clearDisplay();
}

void clearBuffer()
{
    u8g2.clearBuffer();
}
void sendBuffer()
{
    u8g2.sendBuffer();
}

void setFont()
{
    u8g2.setFont(u8g_font_courB08);
}