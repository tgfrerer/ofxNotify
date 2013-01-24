ofxNotify
=========

Growl-style onscreen logging for openFrameworks

Usage
=====

Use ofxNotify just as you would use modern ofLog(), by using the stream "<<" operator.

Example
====

	ofxNotify() << "Hello world";

Remember, you can also pass in numbers, without extra fuss (even if you want to express British dilemmas):

	ofxNotify() << "We wanted to have " << 2 << " more pints, but it was past " << 11 << " o'clock, ";

Don't forget to include a call to ofxNotify::draw(); in your draw loop!
