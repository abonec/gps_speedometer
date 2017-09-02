#include <U8x8lib.h>
#include <U8g2lib.h>
#include <SPI.h>
U8X8_SH1106_128X64_NONAME_HW_I2C u8x8(U8X8_PIN_NONE);
U8G2_SH1106_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0);
void initScreen()
{
    u8x8.begin();
    u8x8.setFont(u8x8_font_artossans8_r);
}
int line = 0;
void resetLine()
{
    line = 0;
}
void addLine(char *val)
{
    if (line >= 8)
    {
        resetLine();
    }
    char result[16];
    // sprintf(result, "%-16s", val);
    sprintf(result, "%s", val);
    u8x8.drawString(0, line++, result);
}

void drawLine(char *val)
{
    resetLine();
    printLine(val);
}
void printLine(char *val)
{
    u8x8.drawString(0, 3, val);
}

void clearDisplay()
{
    u8x8.clearDisplay();
}