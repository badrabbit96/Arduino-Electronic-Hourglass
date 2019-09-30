
// Created by Tomasz Niemczyk (https://github.com/badrabbit96) 
// Version 1.0
// 30.09.2019 

#include "LedControl.h"

LedControl lc = LedControl(12, 11, 10, 2);

// pin 12 is connected to the MAX7219 pin DIN
// pin D11 is connected to the CLK 
// pin 10 is connected to CS
// (2) we are using 2 MAX7219

int delay_time = 415; 
int drop_time = 50;


void setup()
{

  lc.shutdown(0, false); // enable display
  lc.setIntensity(0, 1); // sets brightness (0~15 )

  lc.shutdown(1, false); // enable display
  lc.setIntensity(1, 1); // sets brightness (0~15  )

}

void drop_led_bottom(int n) {
  for (int row = 7; row > -1; row--)
  {
    lc.setLed(0, row, row, true);
    delay(drop_time);
    if (row != n && row > n) {
      lc.setLed(0, row, row, false);
      delay(drop_time);
    }
  }
}

void drop_led_top(int n) {
  for (int row = 0; row < 7; row++)
  {
    lc.setLed(1, row, row, true);
    delay(drop_time);
    //lc.setLed(1,row,row,false);

    if (row != n && row < n) {
      lc.setLed(1, row, row, false);
      // lc.setLed(1,n,n,false);
      delay(drop_time);
    }
  }
}

void turn_on_top() {
  for (int row = 0; row < 8; row++)
  {
    for (int col = 0; col < 8; col++)
    {
      lc.setLed(1, col, row, true);
    }
  }
  lc.setLed(1, 7, 7, false);
  lc.setLed(1, 6, 7, false);
  lc.setLed(1, 7, 6, false);
  lc.setLed(1, 6, 6, false); // we have 64 leds, four of them are not needed (1min = 60 sec)

}

void turn_on_bottom() {
  for (int row = 0; row < 8; row++)
  {
    for (int col = 0; col < 8; col++)
    {
      lc.setLed(0, col, row, true);
    }
  }
  lc.setLed(0, 0, 0, false);
  lc.setLed(0, 0, 1, false);
  lc.setLed(0, 1, 0, false);
  lc.setLed(0, 1, 1, false);

}


void up_down() {

  lc.clearDisplay(0);
  lc.clearDisplay(1);
  turn_on_top();

  lc.setLed(1, 5, 7, false);
  drop_led_bottom(0);
  lc.setLed(0, 0, 0, true);
  delay(delay_time);

  lc.setLed(1, 7, 5, false);
  drop_led_bottom(0);
  lc.setLed(0, 0, 1, true);
  delay(delay_time);

  lc.setLed(1, 4, 7, false);
  drop_led_bottom(0);
  lc.setLed(0, 1, 0, true);
  delay(delay_time);

  lc.setLed(1, 7, 4, false);
  drop_led_bottom(1);
  lc.setLed(0, 1, 1, true);
  delay(delay_time);

  lc.setLed(1, 5, 6, false);
  drop_led_bottom(1);
  lc.setLed(0, 0, 2, true);
  delay(delay_time);

  lc.setLed(1, 6, 5, false);
  drop_led_bottom(1);
  lc.setLed(0, 2, 0, true);
  delay(delay_time);

  lc.setLed(1, 3, 7, false);
  drop_led_bottom(1);
  lc.setLed(0, 1, 2, true);
  delay(delay_time);

  lc.setLed(1, 7, 3, false);
  drop_led_bottom(1);
  lc.setLed(0, 2, 1, true);
  delay(delay_time);

  lc.setLed(1, 4, 6, false);
  drop_led_bottom(1);
  lc.setLed(0, 0, 3, true);
  delay(delay_time);

  lc.setLed(1, 6, 4, false);
  drop_led_bottom(1);
  lc.setLed(0, 3, 0, true);
  delay(delay_time);


  lc.setLed(1, 5, 5, false);
  drop_led_bottom(2);
  lc.setLed(0, 2, 2, true);
  delay(delay_time);


  lc.setLed(1, 2, 7, false);
  drop_led_bottom(2);
  lc.setLed(0, 1, 3, true);
  delay(delay_time);


  lc.setLed(1, 7, 2, false);
  drop_led_bottom(2);
  lc.setLed(0, 3, 1, true);
  delay(delay_time);


  lc.setLed(1, 3, 6, false);
  drop_led_bottom(2);
  lc.setLed(0, 0, 4, true);
  delay(delay_time);


  lc.setLed(1, 6, 3, false);
  drop_led_bottom(2);
  lc.setLed(0, 4, 0, true);
  delay(delay_time);


  lc.setLed(1, 4, 5, false);
  drop_led_bottom(2);
  lc.setLed(0, 2, 3, true);
  delay(delay_time);


  lc.setLed(1, 5, 4, false);
  drop_led_bottom(2);
  lc.setLed(0, 3, 2, true);
  delay(delay_time);


  lc.setLed(1, 1, 7, false);
  drop_led_bottom(2);
  lc.setLed(0, 1, 4, true);
  delay(delay_time);


  lc.setLed(1, 7, 1, false);
  drop_led_bottom(2);
  lc.setLed(0, 4, 1, true);
  delay(delay_time);


  lc.setLed(1, 2, 6, false);
  drop_led_bottom(2);
  lc.setLed(0, 0, 5, true);
  delay(delay_time);


  lc.setLed(1, 6, 2, false);
  drop_led_bottom(2);
  lc.setLed(0, 5, 0, true);
  delay(delay_time);


  lc.setLed(1, 3, 5, false);
  drop_led_bottom(3);
  lc.setLed(0, 3, 3, true);
  delay(delay_time);


  lc.setLed(1, 5, 3, false);
  drop_led_bottom(3);
  lc.setLed(0, 2, 4, true);
  delay(delay_time);


  lc.setLed(1, 4, 4, false);
  drop_led_bottom(3);
  lc.setLed(0, 4, 2, true);
  delay(delay_time);


  lc.setLed(1, 0, 7, false);
  drop_led_bottom(3);
  lc.setLed(0, 1, 5, true);
  delay(delay_time);


  lc.setLed(1, 7, 0, false);
  drop_led_bottom(3);
  lc.setLed(0, 5, 1, true);
  delay(delay_time);


  lc.setLed(1, 1, 6, false);
  drop_led_bottom(3);
  lc.setLed(0, 0, 6, true);
  delay(delay_time);


  lc.setLed(1, 6, 1, false);
  drop_led_bottom(3);
  lc.setLed(0, 6, 0, true);
  delay(delay_time);


  lc.setLed(1, 2, 5, false);
  drop_led_bottom(3);
  lc.setLed(0, 3, 4, true);
  delay(delay_time);


  lc.setLed(1, 5, 2, false);
  drop_led_bottom(3);
  lc.setLed(0, 4, 3, true);
  delay(delay_time);


  lc.setLed(1, 3, 4, false);
  drop_led_bottom(3);
  lc.setLed(0, 2, 5, true);
  delay(delay_time);


  lc.setLed(1, 4, 3, false);
  drop_led_bottom(3);
  lc.setLed(0, 5, 2, true);
  delay(delay_time);


  lc.setLed(1, 0, 6, false);
  drop_led_bottom(3);
  lc.setLed(0, 1, 6, true);
  delay(delay_time);


  lc.setLed(1, 6, 0, false);
  drop_led_bottom(3);
  lc.setLed(0, 6, 1, true);
  delay(delay_time);


  lc.setLed(1, 1, 5, false);
  drop_led_bottom(3);
  lc.setLed(0, 0, 7, true);
  delay(delay_time);


  lc.setLed(1, 5, 1, false);
  drop_led_bottom(3);
  lc.setLed(0, 7, 0, true);
  delay(delay_time);


  lc.setLed(1, 2, 4, false);
  drop_led_bottom(4);
  lc.setLed(0, 4, 4, true);
  delay(delay_time);


  lc.setLed(1, 4, 2, false);
  drop_led_bottom(4);
  lc.setLed(0, 3, 5, true);
  delay(delay_time);


  lc.setLed(1, 3, 3, false);
  drop_led_bottom(4);
  lc.setLed(0, 5, 3, true);
  delay(delay_time);


  lc.setLed(1, 0, 5, false);
  drop_led_bottom(4);
  lc.setLed(0, 2, 6, true);
  delay(delay_time);


  lc.setLed(1, 5, 0, false);
  drop_led_bottom(4);
  lc.setLed(0, 6, 2, true);
  delay(delay_time);


  lc.setLed(1, 1, 4, false);
  drop_led_bottom(4);
  lc.setLed(0, 1, 7, true);
  delay(delay_time);


  lc.setLed(1, 4, 1, false);
  drop_led_bottom(4);
  lc.setLed(0, 7, 1, true);
  delay(delay_time);


  lc.setLed(1, 2, 3, false);
  drop_led_bottom(4);
  lc.setLed(0, 4, 5, true);
  delay(delay_time);


  lc.setLed(1, 3, 2, false);
  drop_led_bottom(4);
  lc.setLed(0, 5, 4, true);
  delay(delay_time);


  lc.setLed(1, 0, 4, false);
  drop_led_bottom(4);
  lc.setLed(0, 3, 6, true);
  delay(delay_time);


  lc.setLed(1, 4, 0, false);
  drop_led_bottom(4);
  lc.setLed(0, 6, 3, true);
  delay(delay_time);


  lc.setLed(1, 1, 3, false);
  drop_led_bottom(4);
  lc.setLed(0, 2, 7, true);
  delay(delay_time);


  lc.setLed(1, 3, 1, false);
  drop_led_bottom(4);
  lc.setLed(0, 7, 2, true);
  delay(delay_time);


  lc.setLed(1, 2, 2, false);
  drop_led_bottom(5);
  lc.setLed(0, 5, 5, true);
  delay(delay_time);


  lc.setLed(1, 0, 3, false);
  drop_led_bottom(5);
  lc.setLed(0, 4, 6, true);
  delay(delay_time);


  lc.setLed(1, 3, 0, false);
  drop_led_bottom(5);
  lc.setLed(0, 6, 4, true);
  delay(delay_time);


  lc.setLed(1, 1, 2, false);
  drop_led_bottom(5);
  lc.setLed(0, 3, 7, true);
  delay(delay_time);


  lc.setLed(1, 2, 1, false);
  drop_led_bottom(5);
  lc.setLed(0, 7, 3, true);
  delay(delay_time);


  lc.setLed(1, 0, 2, false);
  drop_led_bottom(5);
  lc.setLed(0, 5, 6, true);
  delay(delay_time);


  lc.setLed(1, 2, 0, false);
  drop_led_bottom(5);
  lc.setLed(0, 6, 5, true);
  delay(delay_time);


  lc.setLed(1, 1, 1, false);
  drop_led_bottom(5);
  lc.setLed(0, 4, 7, true);
  delay(delay_time);


  lc.setLed(1, 0, 1, false);
  drop_led_bottom(5);
  lc.setLed(0, 7, 4, true);
  delay(delay_time);


  lc.setLed(1, 1, 0, false);
  drop_led_bottom(6);
  lc.setLed(0, 6, 6, true);
  delay(delay_time);


  lc.setLed(1, 0, 0, false);
  drop_led_bottom(6);
  lc.setLed(0, 5, 7, true);
  delay(delay_time);
}

void down_up() {

  lc.clearDisplay(0);
  lc.clearDisplay(1);
  turn_on_bottom();


  lc.setLed(0, 2, 0, false);
  drop_led_top(7);
  lc.setLed(1, 7, 7, true);
  delay(delay_time);


  lc.setLed(0, 0, 2, false);
  drop_led_top(7);
  lc.setLed(1, 7, 6, true);
  delay(delay_time);


  lc.setLed(0, 3, 0, false);
  drop_led_top(7);
  lc.setLed(1, 6, 7, true);
  delay(delay_time);


  lc.setLed(0, 0, 3, false);
  drop_led_top(6);
  lc.setLed(1, 6, 6, true);
  delay(delay_time);


  lc.setLed(0, 2, 1, false);
  drop_led_top(6);
  lc.setLed(1, 7, 5, true);
  delay(delay_time);


  lc.setLed(0, 1, 2, false);
  drop_led_top(6);
  lc.setLed(1, 5, 7, true);
  delay(delay_time);


  lc.setLed(0, 4, 0, false);
  drop_led_top(6);
  lc.setLed(1, 6, 5, true);
  delay(delay_time);


  lc.setLed(0, 0, 4, false);
  drop_led_top(6);
  lc.setLed(1, 5, 6, true);
  delay(delay_time);


  lc.setLed(0, 3, 1, false);
  drop_led_top(6);
  lc.setLed(1, 7, 4, true);
  delay(delay_time);


  lc.setLed(0, 1, 3, false);
  drop_led_top(6);
  lc.setLed(1, 4, 7, true);
  delay(delay_time);


  lc.setLed(0, 2, 2, false);
  drop_led_top(5);
  lc.setLed(1, 5, 5, true);
  delay(delay_time);


  lc.setLed(0, 5, 0, false);
  drop_led_top(5);
  lc.setLed(1, 6, 4, true);
  delay(delay_time);


  lc.setLed(0, 0, 5, false);
  drop_led_top(5);
  lc.setLed(1, 4, 6, true);
  delay(delay_time);


  lc.setLed(0, 4, 1, false);
  drop_led_top(5);
  lc.setLed(1, 7, 3, true);
  delay(delay_time);


  lc.setLed(0, 1, 4, false);
  drop_led_top(5);
  lc.setLed(1, 3, 7, true);
  delay(delay_time);


  lc.setLed(0, 3, 2, false);
  drop_led_top(5);
  lc.setLed(1, 5, 4, true);
  delay(delay_time);


  lc.setLed(0, 2, 3, false);
  drop_led_top(5);
  lc.setLed(1, 4, 5, true);
  delay(delay_time);


  lc.setLed(0, 6, 0, false);
  drop_led_top(5);
  lc.setLed(1, 6, 3, true);
  delay(delay_time);


  lc.setLed(0, 0, 6, false);
  drop_led_top(5);
  lc.setLed(1, 3, 6, true);
  delay(delay_time);


  lc.setLed(0, 5, 1, false);
  drop_led_top(5);
  lc.setLed(1, 7, 2, true);
  delay(delay_time);


  lc.setLed(0, 1, 5, false);
  drop_led_top(5);
  lc.setLed(1, 2, 7, true);
  delay(delay_time);


  lc.setLed(0, 4, 2, false);
  drop_led_top(4);
  lc.setLed(1, 4, 4, true);
  delay(delay_time);


  lc.setLed(0, 2, 4, false);
  drop_led_top(4);
  lc.setLed(1, 5, 3, true);
  delay(delay_time);


  lc.setLed(0, 3, 3, false);
  drop_led_top(4);
  lc.setLed(1, 3, 5, true);
  delay(delay_time);


  lc.setLed(0, 7, 0, false);
  drop_led_top(4);
  lc.setLed(1, 6, 2, true);
  delay(delay_time);


  lc.setLed(0, 0, 7, false);
  drop_led_top(4);
  lc.setLed(1, 2, 6, true);
  delay(delay_time);


  lc.setLed(0, 6, 1, false);
  drop_led_top(4);
  lc.setLed(1, 7, 1, true);
  delay(delay_time);


  lc.setLed(0, 1, 6, false);
  drop_led_top(4);
  lc.setLed(1, 1, 7, true);
  delay(delay_time);


  lc.setLed(0, 5, 2, false);
  drop_led_top(4);
  lc.setLed(1, 4, 3, true);
  delay(delay_time);


  lc.setLed(0, 2, 5, false);
  drop_led_top(4);
  lc.setLed(1, 3, 4, true);
  delay(delay_time);
}

void loop()
{
  up_down();
  down_up();

}
