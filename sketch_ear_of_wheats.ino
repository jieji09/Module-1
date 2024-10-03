#include <TFT_eSPI.h> 
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI(); 

void setup() {
  tft.init();
  tft.setRotation(1);   // 1 = landscape
}

void loop() {
  animateWheats();
}

// This function will draw an ear of wheat at the given x, y coordinates
void drawWheat(int16_t x, int16_t y) {
  tft.drawLine(x, y, x, y - 75, TFT_GREEN);  // draw a stem

  // Draw some kernels on the wheat using ellipses
  for (int i = 0; i < 6; i++) {
    int offset = 10 * i;
    tft.drawEllipse(x - 5, y - offset - 20, 3, 6, TFT_YELLOW); // left kernels
    tft.drawEllipse(x + 5, y - offset - 20, 3, 6, TFT_YELLOW); // right kernels
  }
}

// Animate three ears of wheat (one in the center, one on the left, one on the right)
void animateWheats() {
  int centerX = tft.width() / 2;   // center ear of wheat
  int leftX = centerX - 40;        // left ear of wheat
  int rightX = centerX + 40;       // right ear of wheat
  int baseY = tft.height() - 10;   // same Y position for all ears of wheat

  // animate them moving together
  for (int angle = -10; angle <= 10; angle += 2) {
    // set moving distance for each movement
    tft.fillScreen(TFT_BLACK);

    // move to left
    drawWheat(centerX + angle, baseY);  
    drawWheat(leftX + angle, baseY); 
    drawWheat(rightX + angle, baseY);

    delay(100);
  }

  for (int angle = 10; angle >= -10; angle -= 2) {
    tft.fillScreen(TFT_BLACK);

    // move to right
    drawWheat(centerX + angle, baseY); 
    drawWheat(leftX + angle, baseY);
    drawWheat(rightX + angle, baseY); 

    delay(100);
  }
}
