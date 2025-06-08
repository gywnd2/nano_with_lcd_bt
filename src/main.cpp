#include <Arduino.h>

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

// SCL must be pin 13 on the ATmega328P
// SDA must be pin 11 on the ATmega328P
#define TFT_RST 4
#define TFT_DC 5
#define TFT_CS 6
#define LED_PIN 13

#define TFT_WIDTH 240
#define TFT_HEIGHT 320

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("Hello, World!");

  tft.init(TFT_WIDTH, TFT_HEIGHT);
  tft.setRotation(3);
  tft.fillScreen(ST77XX_WHITE);

  tft.setTextSize(3);
  tft.setTextColor(ST77XX_BLACK);
  tft.setCursor(10, 10);
  tft.println("Hello, World!");
}

void loop() {
  digitalWrite(LED_PIN, HIGH);   // Turn the LED on
  delay(100);                    // Wait for a second
  digitalWrite(LED_PIN, LOW);    // Turn the LED off
  delay(100);                    // Wait for a second
  Serial.println("Blinking LED");
}