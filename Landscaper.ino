#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>
#include "MainUnit.h"

MainUnit unit;
void setup()
{
  unit.Init();
  Serial.begin(115200);
}

void loop()
{
    unit.Exec(1);
    delay(1000);
    unit.Exec(2);
    delay(1000);
}
