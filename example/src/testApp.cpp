#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(60);
	
	ofxNotify::setMessagesLifeTime(3500);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofxNotify::draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

	string textAtribute[5] = {
		"Brilliant",
		"Curious",
		"Amazing",
		"Sublime",
		"Ironic",
	};

	string textObject[4] = {
		" disco inferno",
		" camp fire entanglement",
		" wedding promise",
		" man"
	};

	string textVerb[6] = {
		" bites",
		" strikes",
		" lost on",
		" snatches",
		" teases",
		" invites"
	};
	
	string textSubject[5] = {
		" pope",
		" government",
		" irate schoolmaster",
		" late enthusiast",
		" dog"
	};
	
	// try one of these if you are feeling curious:
	//
	// ofxNotify() << "We wanted to have " << 2 << " more pints, but it was past " << 11 << " o'clock.";
	// ofxNotify() << textAtribute[rand() % 5 ] << ", you just pressed key: " << key;
	
	ofxNotify() << textAtribute[rand() % 5 ] << textObject[rand() % 4 ] << textVerb[rand() % 6 ] << textSubject[rand() % 5];
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}