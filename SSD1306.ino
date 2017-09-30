void SetupSSD1306()
{
    u8g2.begin(); 
}

//     /* LiquidCrystal compatible functions */
//    void home(void) { tx = 0; ty = 0;  u8x8_utf8_init(u8g2_GetU8x8(&u8g2)); }
//    void clear(void) { home(); clearDisplay(); clearBuffer();  }
//    void noDisplay(void) { u8g2_SetPowerSave(&u8g2, 1); }
//    void display(void) { u8g2_SetPowerSave(&u8g2, 0); }
//    void setCursor(u8g2_uint_t x, u8g2_uint_t y) { tx = x; ty = y; }

void UpdateSSD1306()
{
  u8g2.firstPage();
  do 
  {
    u8g2.setFont(u8g2_font_ncenB10_tr);
    //Line 1
    u8g2.setCursor(0,15);
    if (year() <= 9)            //add a 0 if minute is less than or equal to 9
    {
      u8g2.print('0');
    }
    u8g2.print(String(year()-2000));
    u8g2.print(":");
    if (month() <= 9)            //add a 0 if minute is less than or equal to 9
    {
      u8g2.print('0');
    }
    u8g2.print(String(month()));
    u8g2.print(":");
    if (day() <= 9)            //add a 0 if minute is less than or equal to 9
    {
      u8g2.print('0');
    }
    u8g2.print(String(day()));  
    u8g2.print(":");
    if (hour() <= 9)            //add a 0 if minute is less than or equal to 9
    {
      u8g2.print('0');
    }
    u8g2.print(String(hour()));
    u8g2.print(":");
    if (minute() <= 9)            //add a 0 if minute is less than or equal to 9
    {
      u8g2.print('0');
    }
    u8g2.print(String(minute()));
    u8g2.print(":");
    if (second() <= 9)            //add a 0 if minute is less than or equal to 9
    {
      u8g2.print('0');
    }
    u8g2.print(String(second()));  
    //Line 2
    u8g2.setCursor(0,32);
    //Line 3
    u8g2.print("Only another;");
    u8g2.setCursor(0,49);
    u8g2.print(years);
    u8g2.print("Yr: ");
    u8g2.print(months);
    u8g2.print("Mn: ");
    u8g2.print(days);
    u8g2.print("Dy");  
    //line 4
    u8g2.setCursor(0,64);
    u8g2.print(hours);
    u8g2.print("hr:");
    u8g2.print(minutes);
    u8g2.print("min:");
    u8g2.print(seconds);
    u8g2.print("sec");  
  
  } while ( u8g2.nextPage() );
  //delay(1000);
}
