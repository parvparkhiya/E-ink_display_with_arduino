// GxEPD2_HelloWorld.ino by Jean-Marc Zingg

// see GxEPD2_wiring_examples.h for wiring suggestions and examples
// if you use a different wiring, you need to adapt the constructor parameters!

// uncomment next line to use class GFX of library GFX_Root instead of Adafruit_GFX
//#include <GFX.h>

#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <Fonts/FreeMonoBold9pt7b.h>

// select the display class and display driver class in the following file (new style):
#include "GxEPD2_display_selection_new_style.h"

// or select the display constructor line in one of the following files (old style):
#include "GxEPD2_display_selection.h"
#include "GxEPD2_display_selection_added.h"

// alternately you can copy the constructor from GxEPD2_display_selection.h or GxEPD2_display_selection_added.h to here
// e.g. for Wemos D1 mini:
//GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> display(GxEPD2_154_D67(/*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4)); // GDEH0154D67
// GxEPD2_BW<GxEPD2_420, GxEPD2_420::HEIGHT> *display;
GxEPD2_BW<GxEPD2_420, MAX_HEIGHT(GxEPD2_420)> *display;

#include "puru_bee.h"

void setup()
{
  display = new GxEPD2_BW<GxEPD2_420, MAX_HEIGHT(GxEPD2_420)>(GxEPD2_420(/*CS=10*/ SS, /*DC=*/ 9, /*RST=*/ 8, /*BUSY=*/ 7));
  display->init();
  // display->hibernate();
}

const char HelloWorld[] = "Puru and Bee";

void helloWorld()
{
  display->setRotation(0);
  display->setFont(&FreeMonoBold9pt7b);
  display->setTextColor(GxEPD_BLACK);
  int16_t tbx, tby; uint16_t tbw, tbh;
  display->getTextBounds(HelloWorld, 0, 0, &tbx, &tby, &tbw, &tbh);
  // center the bounding box by transposition of the origin:
  uint16_t x = ((display->width() - tbw) / 2) - tbx;
  uint16_t y = ((display->height() - tbh) / 2) - tby;
  display->setFullWindow();
  display->firstPage();
  do
  {
    display->fillScreen(GxEPD_WHITE);
    display->setCursor(x, y);
    display->print(HelloWorld);
  }
  while (display->nextPage());

  delay(2000);

  display->firstPage();
  do
  {
    display->fillScreen(GxEPD_WHITE);
    display->drawImage(puru_bee, 0, 0, 400, 300, false, false, true);
    delay(100);
  }
  while (display->nextPage());

  delay(2000);
}

void loop() {
  helloWorld();
};
