#include <Arduino.h>
#include <rm67162.h>
#include <TFT_eSPI.h>
#include "true_color.h"

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);

#define HEIGHT LCD_V_RES
#define WIDTH LCD_H_RES

void setup()
{
  Serial.begin(115200);
  while (!Serial)
    ;

  rm67162_init();
  lcd_setRotation(1);

  sprite.createSprite(WIDTH, HEIGHT);
  sprite.setSwapBytes(1);
}

void loop()
{
  Serial.println("Hello World T-Display");

  sprite.pushImage(0, 0, WIDTH, HEIGHT, (uint16_t *)gImage_true_color);
  lcd_PushColors(0, 0, WIDTH, HEIGHT, (uint16_t *)sprite.getPointer());
  delay(2000);
}