#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(255,255,255);
	ofSetVerticalSync(true);
	frameByframe = false;
    
	//angerman.setPixelFormat(OF_PIXELS_RGBA);
    
	angerman.loadMovie("movies/anger.mov");
	angerman.play();
}

//--------------------------------------------------------------
void testApp::update(){
    angerman.update();
}

//--------------------------------------------------------------
void testApp::draw(){
 angerman.draw(20,20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	switch(key){
        case 'f':
            frameByframe = !frameByframe;
            angerman.setPaused(frameByframe);
            break;
            
        case OF_KEY_LEFT:
            angerman.previousFrame();
            break;
            
        case OF_KEY_RIGHT:
            angerman.nextFrame();
            break;
            
        case '0':
            angerman.firstFrame();
            break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
	if(!frameByframe){
		int width = ofGetWidth();
		float pct = (float)x / (float)width;
		float speed = (2 * pct - 1) * 5.0f;
		angerman.setSpeed(speed);
	}
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	if(!frameByframe){
		int width = ofGetWidth();
		float pct = (float)x / (float)width;
		angerman.setPosition(pct);
	}
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	if(!frameByframe){
		angerman.setPaused(true);
	}
}


//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	if(!frameByframe){
		angerman.setPaused(false);
	}
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
