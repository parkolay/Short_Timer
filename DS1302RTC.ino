void SetupDS1302()
{

  lcd.clear();
  if (RTC.haltRTC())
    lcd.print("Clock stopped!");
  else
    lcd.print("Clock working.");

  lcd.setCursor(0,1);
  if (RTC.writeEN())
    lcd.print("Write allowed.");
  else
    lcd.print("Write protected.");

  delay ( 250 );
  
  // Setup time library  
  lcd.clear();
  lcd.print("RTC Sync");
  setSyncProvider(RTC.get);          // the function to get the time from the RTC
  if(timeStatus() == timeSet)
    lcd.print(" Ok!");
  else
    lcd.print(" FAIL!");
  
  delay ( 250 );
  
  lcd.clear();  
}
