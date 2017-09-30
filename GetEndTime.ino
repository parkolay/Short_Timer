void GetEndTime()
{
  // Determine number of minutes until YEAR/MONTH/DAY/etc.
  uint32_t d1  = date2days(YEAR, MONTH, DAY),                   // End day
           d2  = date2days(year(), month(), day()); // Today
  int32_t  s1 = (HOUR * 60 + MINUTE) * 60L,
           s2 = (hour() * 60 + minute()) * 60L + second();   
  
  ThisMonth = (month());  //gtrab this now to be used in next call
  getDaysThisMonth(); //used in days calculation below
                     
  if(d2 > d1) 
  { // Date already passed
    minutes = 0;
  } //end   if(d2 > d1) 
  else 
  {
    if((d2 == d1) && (s2 >= s1)) // Same day, hour/min/sec has passed
    { 
      minutes = 0;
    } 
    else 
    {
      s1 -= s2; // Seconds time difference, may be negative, we will fix it
      seconds = (s1 % 60);
      if (seconds < 0 )//fixed!
      {
        seconds += 60;  
      }
        
      if (seconds >= 0)
      {
        minutes = (59-abs(MINUTE - minute()));
      }
      else
      {
        minutes = (60-abs(MINUTE - minute()));
      }

      if (minutes >= 0)
      {
        if (HOUR > hour())
        {
          hours = ((HOUR-hour())-1);  
        }
        else
        {
          hours = (23-abs(HOUR - hour()));
        }
      }
      else
      {
        hours = (24-abs(HOUR - hour()));
      }

      if (hours >= 0)
      {
        days = abs((DaysThisMonth-1)-abs((DAY) - day())); 
      }
      else
      {
        days = abs(DaysThisMonth-abs((DAY) - day()));
      }

      if (days >= 0)
      {
        months = (11-(abs(MONTH - month())));
      }
      else
      {
        months = (12-abs(MONTH - month()));
      }
     
      if (months >= 0)
      {
        years = (YEAR - year()-1);
      }
      else
      {
        years = (YEAR - year());
      }
    }//end else (of if((d2 == d1) && (s2 >= s1)) )


           lcd.setCursor(0,3);  // set the cursor (column, line)
           if (years <= 9)              //add a space if hour is less than or equal to 9
            {
              lcd.print('0');
            }
           lcd.print(years);
           lcd.print("Y:");
           lcd.print(months);
           if (months <= 9)              //add a space if hour is less than or equal to 9
            {
              lcd.print('0');
            }
           lcd.print("M:");
           if (days <= 9)              //add a space if hour is less than or equal to 9
            {
              lcd.print('0');
            }
           lcd.print(days);
           lcd.print("D:");
           if (hours <= 9)              //add a space if hour is less than or equal to 9
            {
              lcd.print('0');
            }
           lcd.print(hours);
           lcd.print(":");
           if (minutes <= 9)              //add a space if hour is less than or equal to 9
            {
              lcd.print('0');
            }
           lcd.print(minutes);
           lcd.print(":");
            if (seconds <= 9)              //add a space if hour is less than or equal to 9
            {
              lcd.print('0');
            }
           lcd.print(seconds);
  
  }//end else (of   if(d2 > d1) )
}//end void GetEndTime() 

void getDaysThisMonth()
{
  if ((ThisMonth == 4) || 
      (ThisMonth == 6) ||
      (ThisMonth == 9) ||
      (ThisMonth == 11)  )//I tried stacking the the numbers together but that didn't work...? 
  {
    DaysThisMonth = 30;
   }
   else if (ThisMonth == (2))  
   {
    DaysThisMonth = 28;
   }
   else
   {
    DaysThisMonth = 31; 
   } 
}//end void getDaysThisMonth()
