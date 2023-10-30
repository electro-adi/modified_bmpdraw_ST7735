
#include <Adafruit_GFX.h>         // Core graphics library
#include <Adafruit_ST7735.h>      // Hardware-specific library
#include <SdFat.h>                // SD card & FAT filesystem library
#include <Adafruit_ImageReader.h> // Image-reading functions

#define SD_CS    2   //Chip select for SD
#define TFT_CS   13  //Chip select for TFT
#define TFT_RST  12  //Reset for TFT
#define TFT_DC   14  //Data/Command for TFT

SdFat                SD;         // SD card filesystem
Adafruit_ImageReader reader(SD); // Image-reader object, pass in SD filesys
Adafruit_ST7735      tft    = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {

  Serial.begin(115200);

  ImageReturnCode stat; // Status from image-reading functions

  if (!SD.begin(SD_CS, SD_SCK_MHZ(10))) {
    Serial.println("SD card initialization failed!");
    for(;;); // Fatal error, do not continue
  }
  Serial.println("SD card initialized!");

  tft.initR(INITR_BLACKTAB); // Initialize screen

  stat = reader.drawBMP("/hehehe.bmp", tft, 0, 0);

  reader.printStatus(stat);
}


void loop() {
}
