void SetupLCD()
{
   // initialize the lcd 
    lcd.init();                      
    lcd.backlight();
    lcd.print("!! Retirement  Timer !!");
    lcd.print("RTC activated");
}
