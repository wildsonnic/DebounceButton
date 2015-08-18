/*
  Example of DebounceButton library used as SWITCHING BUTTON.

  * The button will change its state while the button is being pressed,
    and change back to default when released.
  * You have the option to set the pin and the debounce delay in milliseconds.
  * You have the option to set the default state to either HIGH or LOW.

  This library was created by: SAMUEL BETANCES on August 16, 2015.
----------------------------------------------------------------------------

  Using the default example for debouncing from Arduino library
  made by David A. Mellis and Mike Walters:
  http://www.arduino.cc/en/Tutorial/Debounce
-----------------------------------------------------------------------------
  */

#include <DebounceButton.h>

//create an instance for the button with the pin and debounce delay in milliseconds.
DebounceButton boton(2, 50);

void setup(){
  Serial.begin(115200);
  pinMode(13, OUTPUT);  //set LED to use for test.
}

void loop(){
  //store the state of the button and show it in monitor:
  bool buttonState = boton.Switch(ON);  //here you can specify the default state for the button.
  Serial.println(buttonState);
  //show the results with the built-in LED:
  digitalWrite(13, buttonState);
}






