
#include <Arduino.h>
#include <U8g2lib.h>
#include <RTClib.h>
#include <TimeLib.h>
#include <DS1302RTC.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

/*
  U8glib Example Overview:
    Frame Buffer Examples: clearBuffer/sendBuffer. Fast, but may not work with all Arduino boards because of RAM consumption
    Page Buffer Examples: firstPage/nextPage. Less RAM usage, should work with all Arduino boards.
    U8x8 Text Only Example: No RAM usage, direct communication with display controller. No graphics, 8x8 Text only.
    
  This is a page buffer example.    
*/

LiquidCrystal_I2C lcd(0x3F,20,4);  // set the LCD address to 0x27 for a 20 chars and 4 line display
// initialize the RTC library and setup calendar
//defines for count down clock

#define YEAR  2042 // Date and time of some future event
#define MONTH    8 // (like retirement @ 67)
#define DAY      9 // But here it was set for Halley's comet
#define HOUR    16 // Example time here is set for 4PM,
#define MINUTE   1 // DON'T use leading zero or value is octal!

// Please UNCOMMENT one of the contructor lines below
// U8g2 Contructor List (Picture Loop Page Buffer)
// The complete list is available here: https://github.com/olikraus/u8g2/wiki/u8g2setupcpp
// Please update the pin numbers according to your setup. Use U8X8_PIN_NONE if the reset pin is not connected

U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // All Boards without Reset of the Display

// End of constructor list

//
// DS1302:  CE/RST pin-> Arduino 2
//          I/O pin   -> Arduino 3
//          SCLK pin  -> Arduino 4
// Init the DS1302
// Set pins:  CE, IO,CLK
DS1302RTC RTC(2, 3, 4);

int years = 0;
int months = 0;
int days = 0;
int hours = 0; // start hours
int minutes = 0; //start min
int seconds = 90; //start seconds
int ThisMonth = 0;
int DaysThisMonth = 0;  //used to calculate # of days this month

// Number of days since 2000/01/01, valid for 2000-2099.  Essentially a
// copy of the date2days() function in RTClib, but it's been declared static
// I am too lazy to set it as global
uint16_t date2days(uint16_t y, uint8_t m, uint8_t d) 
{
  static const uint8_t daysInMonth[] PROGMEM =
    { 31,28,31,30,31,30,31,31,30,31,30,31 };
  if(y >= 2000) y -= 2000;
  uint16_t days = d;
  for(uint8_t i=1; i<m; ++i) days += pgm_read_byte(daysInMonth + i - 1);
  if((m > 2) && (!(y & 3))) days++;        // Leap day for current year
  return days + 365 * y + (y + 3) / 4 - 1; // Add leap days for prior years
}//end uint16_t date2days(uint16_t y, uint8_t m, uint8_t d) 
 

void setup(void) 
{
  Wire.begin();         //setup I2C
  SetupSSD1306();
  SetupLCD();
  SetupDS1302();
    
}//end void setup(void) 

void loop(void) 
{
  UpdateSSD1306();
  GetEndTime();
}//end void loop(void)

