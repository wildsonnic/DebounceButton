/*
  Example of DebounceButton library used as LATCHING SWITCH button.

  * The button will change its state when the button is pressed and keep it
    that way until it is pressed again.
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
DebounceButton boton(9, 50);

void setup(){
  Serial.begin(9600);
  pinMode(13, OUTPUT);  //use the built-in LED to test.
}

void loop(){
  //store the state of the button and show it in monitor:
  bool buttonState = boton.Latch(ON); //here you can specify the default state for the button.
  Serial.println(buttonState);
  //Turn the LED ON or OFF:
  digitalWrite(13, buttonState);
}
