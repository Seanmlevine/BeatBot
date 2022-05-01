//Display a premade LED image on the matrix
//void displayLedImage(uint8_t image[][3]) {
//  for(int j=0; j<HEIGHT; j++) {
//    for(int i=0; i<WIDTH; i++) {
//      matrix.drawPixel(i, j, matrix.Color(image[j * HEIGHT + i][0], image[j * HEIGHT + i][1], image[j * HEIGHT + i][2]));
//    }
//  }
//  matrix.show();
//}

void displayLedImage(uint8_t image[][3]) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, strip.Color(image[i][0], image[i][1], image[i][2])); //  Set pixel's color (in RAM)
  }
  strip.show();                          //  Update strip to match
  //delay(20);                           //  Pause for a moment
}

//Move an image up or down X units
void moveUpDownImage(uint8_t image[][3], int shift_by) {
//  uint8_t top_row[WIDTH][3] = &image[0];
//  uint8_t btm_row[WIDTH][3] = &image[HEIGHT];

  if(shift_by >= 0) {
    for(int j=0; j<shift_by; j++) {
      for(int i=0; i<WIDTH; i++) {
        matrix.drawPixel(i, j, matrix.Color(image[i][0], image[i][1], image[i][2]));
      }
    }
    for(int j=0; j<HEIGHT-shift_by; j++) {
      for(int i=0; i<WIDTH; i++) {
        matrix.drawPixel(i, j+shift_by, matrix.Color(image[j * HEIGHT + i][0], image[j * HEIGHT + i][1], image[j * HEIGHT + i][2]));
      }
    }
  }
  else {
    for(int j=0; j<HEIGHT+shift_by; j++) {
      for(int i=0; i<WIDTH; i++) {
        matrix.drawPixel(i, j, matrix.Color(image[(j-shift_by) * HEIGHT + i][0], image[(j-shift_by) * HEIGHT + i][1], image[(j-shift_by) * HEIGHT + i][2]));
      }
    }
    for(int j=HEIGHT+shift_by; j<HEIGHT; j++) {
      for(int i=0; i<WIDTH; i++) {
        matrix.drawPixel(i, j, matrix.Color(image[(HEIGHT-1) * HEIGHT + i][0], image[(HEIGHT-1) * HEIGHT + i][1], image[(HEIGHT-1) * HEIGHT + i][2]));
      }
    }
  }
  matrix.show();
}

void changeLEDColor(uint8_t image[][3], const uint8_t color[3]) {
  for(int i = 0; i < LED_COUNT; i++) {
    if(image[i][0] != 0 || image[i][1] != 0 || image[i][2] != 0) {
      image[i][0] = color[0];
      image[i][1] = color[1];
      image[i][2] = color[2];
    }
  }
}

// ----------------- Some functions creating animated effects -----------------

// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

// Theater-marquee-style chasing lights. Pass in a color (32-bit value,
// a la strip.Color(r,g,b) as mentioned above), and a delay time (in ms)
// between frames.
void theaterChase(uint32_t color, int wait) {
  for(int a=0; a<10; a++) {  // Repeat 10 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in steps of 3...
      for(int c=b; c<strip.numPixels(); c += 3) {
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show(); // Update strip with new contents
      delay(wait);  // Pause for a moment
    }
  }
}

// Rainbow cycle along whole strip. Pass delay time (in ms) between frames.
void rainbow(int wait) {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this loop:
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    // strip.rainbow() can take a single argument (first pixel hue) or
    // optionally a few extras: number of rainbow repetitions (default 1),
    // saturation and value (brightness) (both 0-255, similar to the
    // ColorHSV() function, default 255), and a true/false flag for whether
    // to apply gamma correction to provide 'truer' colors (default true).
    strip.rainbow(firstPixelHue);
    // Above line is equivalent to:
    // strip.rainbow(firstPixelHue, 1, 255, 255, true);
    strip.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
  }
}

// Rainbow-enhanced theater marquee. Pass delay time (in ms) between frames.
void theaterChaseRainbow(int wait) {
  int firstPixelHue = 0;     // First pixel starts at red (hue 0)
  for(int a=0; a<30; a++) {  // Repeat 30 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in increments of 3...
      for(int c=b; c<strip.numPixels(); c += 3) {
        // hue of pixel 'c' is offset by an amount to make one full
        // revolution of the color wheel (range 65536) along the length
        // of the strip (strip.numPixels() steps):
        int      hue   = firstPixelHue + c * 65536L / strip.numPixels();
        uint32_t color = strip.gamma32(strip.ColorHSV(hue)); // hue -> RGB
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show();                // Update strip with new contents
      delay(wait);                 // Pause for a moment
      firstPixelHue += 65536 / 90; // One cycle of color wheel over 90 frames
    }
  }
}
