#include <Arduino.h>

void setup()
{
  Serial.begin(115200);
  while (!Serial)
    ;
}

void loop()
{
  Serial.println("Hello World T-Display");
  delay(2000);
}