
// --- LED Part ---
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pix = Adafruit_NeoPixel(numPix, gpioLed, NEO_GRB + NEO_KHZ800);

void initLed() {
  pix.begin();
  ledTest();
}

void colorToRgb(int number, String color) {
  if (color.equals("red")) {
    changeLedColor(number, 255, 0, 0);
  } else if (color.equals("green")) {
    changeLedColor(number, 0, 255, 0);
  } else if (color.equals("yellow")) {
    changeLedColor(number, 200, 180, 30);
  } else if (color.equals("blue")) {
    changeLedColor(number, 30, 30, 255);
  } else if (color.equals("white")) {
    changeLedColor(number, 200, 200, 200);
  } else if (color.equals("dark")) {
    changeLedColor(number, 0, 0, 0);
  }
}

void changeLedColor(int number, int r, int g, int b) {
  pix.setPixelColor(number, pix.Color(r, g, b));
  pix.show();
}

void ledTest() {
  farbWechsel(30, 80, 30, 100);
  farbWechsel(0, 0, 0, 100);
}

void farbWechsel(int r, int g, int b, int t) {
  for (int i = 0; i < numPix; i++) {
    pix.setPixelColor(i, pix.Color(r, g, b));
    pix.show();
    delay(t);
  }
}

void dimAll(int n) {
  for (int i = 0; i < numPix; i++) {
    pix.setBrightness(n);
    pix.show();
  }
}

void createLedStatus() {
  client.subscribe("/statusanzeige_bilderrahmen/powerAll");
  client.subscribe("/statusanzeige_bilderrahmen/dimAll");
  client.subscribe("/statusanzeige_bilderrahmen/led0");
  client.subscribe("/statusanzeige_bilderrahmen/led1");
  client.subscribe("/statusanzeige_bilderrahmen/led2");
  client.subscribe("/statusanzeige_bilderrahmen/led3");
  client.subscribe("/statusanzeige_bilderrahmen/led4");
  client.subscribe("/statusanzeige_bilderrahmen/led5");
  client.subscribe("/statusanzeige_bilderrahmen/led6");
  client.subscribe("/statusanzeige_bilderrahmen/led7");
  // client.publish("/statusanzeige_bilderrahmen/dimAll", "20");
}
