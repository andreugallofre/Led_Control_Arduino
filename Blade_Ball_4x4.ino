#include <Adafruit_NeoPixel.h>         // Including Adafruit NeoPixel library
#define PIN            8                // LED on digital pin 6
#define NUMLEDS        16                 // Use total of 1 LED

Adafruit_NeoPixel leds = Adafruit_NeoPixel(NUMLEDS, PIN, NEO_GRB + NEO_KHZ800);

//VECTOR DECLARATION

int blade[16] = {1,0,1,0,0,0,0,1,1,0,1,1,1,1,0,0}; //Matrix with blade shape

//SETUP OF ARDUINO, OBJECTS...

void setup() {

  leds.begin();     // Initialize 'leds' object
  off();            // Turn off all leds
  leds.show();      // Comit changes to leds
  delay(500);
}

//LOOP CODE

void loop() {

run_blade();
run_ball();

}

//FUCNTIONS

void off(){ //Function to turn off all leds
  for (int i=0; i<NUMLEDS;i++)leds.setPixelColor(i, leds.Color(0, 0, 0));
  leds.show();
}

void run_blade(){ //Function to turn of "blade" leds
for(int i=0; i<NUMLEDS ;i++){
  if (blade[i] == 1) leds.setPixelColor(i, leds.Color(0, 10, 0));
  }
  leds.show();
  for(int i=0; i<NUMLEDS ;i++){
  if (blade[i] == 1) leds.setPixelColor(i, leds.Color(0, 0, 0));
  }
  delay(300);
}

void run_ball(){ //Function to turn on "ball" leds
for(int i=0; i<NUMLEDS ;i++){
  if (blade[i] == 0) leds.setPixelColor(i, leds.Color(0, 10, 0));
  }
  leds.show();
  for(int i=0; i<NUMLEDS ;i++){
  if (blade[i] == 0) leds.setPixelColor(i, leds.Color(0, 0, 0));
  }
  delay(300);
}
