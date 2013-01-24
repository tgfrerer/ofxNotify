# ofxNotify

Growl-style onscreen logging for openFrameworks. Because sometime, you just want to log to your screen.

## Description

ofxNotify will render strings to the top left of your screen, and forget all about them after a set time. 

## Motivation

This is useful if you want to have some visual feedback after you've applied an action by pressing a keyboard shortcut, for example.

## Usage

Use ofxNotify just as you would use modern ofLog(), by using the stream "<<" operator.

## Use Example

	ofxNotify() << "Hello world";

Remember, you can also pass in numbers, without extra fuss (even if you want to express British dilemmas):

	ofxNotify() << "We wanted to have " << 2 << " more pints, but it was past " << 11 << " o'clock, ";

Don't forget to include a call to ofxNotify::draw(); in your draw loop!

## Dependencies

Nil. 

♥ openFrameworks > 7.0