//
//     _____    ___     
//    /    /   /  /     ofxNotify
//   /  __/ * /  /__    (c) ponies & light, 2013. All rights reserved.
//  /__/     /_____/    poniesandlight.co.uk
//
//  ofxNotify.cpp
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

#include "ofxNotify.h"

// ----------------------------------------------------------------------
// Static class variables
// ----------------------------------------------------------------------

map<unsigned long long, string>				ofxNotify::messages;

ofMutex										ofxNotify::msgMutex;
int											ofxNotify::messageLifeTimeInMilliseconds = 2000;

// ----------------------------------------------------------------------
// Class Methods
// ----------------------------------------------------------------------

void ofxNotify::setMessagesLifeTime(int messageLifeTimeInMilliseconds_){
	messageLifeTimeInMilliseconds = messageLifeTimeInMilliseconds_;
}

// ----------------------------------------------------------------------

void ofxNotify::draw(){
	
	if (messages.empty()) return;
	
	// -------- Invariant: there are messages to display.
	
	unsigned long long elapsedTimeNow = ofGetElapsedTimeMicros();
	
	int i = 0;
	
	map<unsigned long long, string>::iterator it = messages.begin();
	while (it != messages.end()){
		ofDrawBitmapStringHighlight(it->second, ofGetWidth() - (it->second.size()*8 + 16), 50 + i*20,
									(i == messages.size()-1) ? (ofColor::red) : (ofColor::black));
		it++;
		i++;
	}
	
	it = messages.begin();
	bool hasFoundDeadMessage = false;
	
	while (it != messages.end()){
		if (elapsedTimeNow - it->first > messageLifeTimeInMilliseconds*1000){
			it++;
			hasFoundDeadMessage = true;
		} else {
			break;
		}
	}
	
	if (hasFoundDeadMessage && msgMutex.tryLock()){
		messages.erase(messages.begin(), it);
		msgMutex.unlock();
	}
	
}

// ----------------------------------------------------------------------
// Instance Methods
// ----------------------------------------------------------------------

ofxNotify::~ofxNotify() {
	if (msgMutex.tryLock()){
		if(!bPrinted){
			if(message.str().empty()){
				message;
			}
			messages[ofGetElapsedTimeMicros()] = message.str();
		}
		msgMutex.unlock();
	}
}

// ----------------------------------------------------------------------

