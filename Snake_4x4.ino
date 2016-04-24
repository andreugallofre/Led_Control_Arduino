#include <Adafruit_NeoPixel.h>         // Include Adafruit NeoPixel library
#define PIN            8                // LED on digital pin 6
#define NUMLEDS        16                 // Use total of 1 LED
 
Adafruit_NeoPixel leds = Adafruit_NeoPixel(NUMLEDS, PIN, NEO_GRB + NEO_KHZ800);

int Snake4_4[16] = {0,1,2,3,7,6,5,4,8,9,10,11,15,14,13,12};
int i = 0;

void setup() {

  leds.begin(); // Initialize 'leds' object
  off();        // Turn off all leds
  leds.show();  // Comit changes to leds
  delay(500); 
}

void loop() {

  int previous = i-1;
  int previous2 = i-2;

  if (previous < 0) previous+=16;
  if (previous2 < 0) previous2+=16;
  
  leds.setPixelColor(Snake4_4[i], leds.Color(255, 0, 0));
  leds.setPixelColor(Snake4_4[previous], leds.Color(255, 0, 0));
  leds.setPixelColor(Snake4_4[previous2], leds.Color(255, 0, 0));
  leds.show();
  leds.setPixelColor(Snake4_4[i], leds.Color(0, 0, 0));
  leds.setPixelColor(Snake4_4[previous], leds.Color(0, 0, 0));
  leds.setPixelColor(Snake4_4[previous2], leds.Color(0, 0, 0));
  delay(500);
  i = (i+1)%16;
  }
  
//Function to turn down all leds
void off(){
  for (int i=0; i<NUMLEDS;i++)leds.setPixelColor(i, leds.Color(0, 0, 0));
  leds.show(); 
}
