/*
  This library was created by: SAMUEL BETANCES on August 16, 2015.
----------------------------------------------------------------------------

  Using the default example for debouncing from Arduino library
  made by David A. Mellis and Mike Walters:
  http://www.arduino.cc/en/Tutorial/Debounce
-----------------------------------------------------------------------------
  */


#ifndef _DEBOUNCEBUTTON_H_
#define _DEBOUNCEBUTTON_H_
#include <Arduino.h>

//buttons states:
#define ON	1
#define OFF	0

class DebounceButton{
public:
	DebounceButton(uint8_t _buttonPin, uint16_t _debounceTime);

	bool Latch();	//button will maintain state after being pressed.
	bool Latch(bool _initialState);	//initial state can be specified.
	bool Switch();	//button will maintain state while being pressed.
	bool Switch(bool _initialState);	//initial state can be specified.

private:
	uint8_t buttonPin;
	bool latchLastButtonState, switchLastButtonState;
	bool latchButtonState, switchButtonState;
	bool latchState, switchState;
	uint16_t debounceTime;
	uint32_t latchLastDebounceTime, switchLastDebounceTime;
};

#endif
