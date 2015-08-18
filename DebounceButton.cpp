
#include "DebounceButton.h"

DebounceButton::DebounceButton(uint8_t _buttonPin, uint16_t _debounceTime){
	//if using MEGA:
#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
	if(_buttonPin < 0 || buttonPin > 69)
		buttonPin = 2;
	else
		buttonPin = _buttonPin;
#else	//if using other board:
	if(_buttonPin < 0 || buttonPin > 19)
		buttonPin = 2;
	else
		buttonPin = _buttonPin;

#endif
	debounceTime = _debounceTime;
	pinMode(buttonPin, INPUT);
}



bool DebounceButton::Latch(){
	// read the state of the switch into a local variable:
	bool reading = digitalRead(buttonPin);
	if(reading != latchLastButtonState)
		if(reading)	//to avoid the waiting for second push.
			latchLastDebounceTime = millis();	
	if( (millis() - latchLastDebounceTime) > debounceTime){
		if(reading != latchButtonState){
			latchButtonState = reading;
			if(latchButtonState == HIGH){
				latchState = !latchState;		
			}
		}
	}
	latchLastButtonState = reading;
	return latchState;
}


bool DebounceButton::Latch(const bool _initialState){
	bool reading = digitalRead(buttonPin);
	// If the button has changed:
	if(reading != latchLastButtonState)
		if(reading)	//to avoid the waiting for second push.
			latchLastDebounceTime = millis();	
	if( (millis() - latchLastDebounceTime) > debounceTime){
		if(reading != latchButtonState){
			latchButtonState = reading;
			if(latchButtonState == HIGH){
				latchState = !latchState;	
				latchLastDebounceTime = 0;
			}
		}
	}
	//stores the last know button state:
	latchLastButtonState = reading;
	//return the changed button state:
	if(_initialState)	//start HIGH
		return !latchState;
	else
		return latchState;
}


bool DebounceButton::Switch(){
	// read the state of the switch into a local variable:
	bool reading = digitalRead(buttonPin);

	if(reading != switchLastButtonState){
		switchLastDebounceTime = millis();
		if( (millis() - switchLastDebounceTime) > debounceTime){
			if(reading != switchButtonState){
				switchButtonState = reading;		
			}
		}
		switchLastButtonState = reading;
		return switchButtonState;
	}
}


bool DebounceButton::Switch(bool _initialState){
	bool reading;
	// read the state of the button:
	if(_initialState)	//start HIGH
		reading = !digitalRead(buttonPin);
	else	//start LOW
		reading = digitalRead(buttonPin);

	if(reading != switchLastButtonState){
		switchLastDebounceTime = millis();
		if( (millis() - switchLastDebounceTime) > debounceTime)
			if(reading != switchButtonState)
				switchButtonState = reading;				
		switchLastButtonState = reading;
		return switchButtonState;
	}
}
