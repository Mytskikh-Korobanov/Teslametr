// Тесламетр на датчике Холла (версия для 5 В)
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

#define Hp 0
#define Hm 1

#define time_ind 1000 // время индикации в мс

void setup()
{
  display.begin();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  pinMode(Hp, INPUT);
  pinMode(Hm, INPUT);
}

void loop() 
{
  display.clearDisplay();
  display.setCursor(0, 0);
  int x1 = analogRead(Hp);
  int x2 = analogRead(Hm);
  // пересчёт ведётся по формуле res = a * (5000 / 1024) * (3 /280) / 2.6 * 1000
  int res = abs(x1 - x2) * 20; // результат в мТл
  display.print("  ");
  display.println(res, DEC);
  display.print("   mT");
  display.display();
  delay(time_ind);
}
