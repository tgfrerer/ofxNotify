//
//     _____    ___     
//    /    /   /  /     ofxNotify
//   /  __/ * /  /__    (c) ponies & light, 2013. All rights reserved.
//  /__/     /_____/    poniesandlight.co.uk
//
//  ofxNotify.h
//  Created by tim on 23/01/2013.
//  
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef GUARD__ghost_client__ofxNotify__
#define GUARD__ghost_client__ofxNotify__

#include "ofMain.h"

// Use ofxNotify just as you would use modern ofLog(), by using the stream "<<" operator.
//
// Example:
//
// ofxNotify() << "Hello world";
//
// Remember, you can also pass in numbers, without extra fuss (even if you want to express British dilemmas):
//
// ofxNotify() << "We wanted to have " << 2 << " more pints, but it was past " << 11 << " o'clock, ";
//
// Don't forget to include a call to ofxNotify::draw(); in your draw loop!

class ofxNotify {
	static ofMutex							msgMutex;
	static map<unsigned long long, string>	messages;
	static int								messageLifeTimeInMilliseconds;		// defaults to 2000ms
	std::ostringstream						message;
	bool									bPrinted;
public:

	ofxNotify()
	: bPrinted(false) {
	};
	
	virtual ~ofxNotify();

	// draw the notifier by calling ofxNotify::draw(); from within your app.
	static void draw(bool shouldDraw_ = true);
	static void setMessagesLifeTime(int messageLifeTimeInMilliseconds_);
	
	// catch the << ostream with a template class to read any type of data
	template <class T>
	ofxNotify& operator<<(const T& value){
		message << value;
		return *this;
	};
		
	// catch the << ostream function pointers such as std::endl and std::hex
	ofxNotify& operator<<(std::ostream& (*func)(std::ostream&)){
		func(message);
		return *this;
	};
	
};


#endif /* defined(__ghost_client__ofxNotify__) */
