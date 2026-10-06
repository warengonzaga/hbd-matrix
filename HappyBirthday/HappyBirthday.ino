#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Four 8x8 matrices. FC16_HW is the common four-in-one board layout.
const uint8_t MAX_DEVICES = 4;
const uint8_t CS_PIN = 10;
const uint16_t SCROLL_SPEED = 65; // Milliseconds per step; higher is slower.

// Change YOUR NAME to the birthday person's name. Use plain English letters.
const char MESSAGE[] = "HAPPY BIRTHDAY, YOUR NAME!   ";

// Hardware SPI on Uno R3: DIN = D11, CLK = D13, CS = D10.
MD_Parola display(MD_MAX72XX::FC16_HW, CS_PIN, MAX_DEVICES);

void setup()
{
  display.begin();
  display.setIntensity(1); // Brightness: 0 (dimmest) to 15 (brightest).
  display.displayClear();
  display.displayScroll(MESSAGE, PA_LEFT, PA_SCROLL_LEFT, SCROLL_SPEED);
}

void loop()
{
  if (display.displayAnimate())
  {
    display.displayReset(); // Repeat after the message finishes.
  }
}
