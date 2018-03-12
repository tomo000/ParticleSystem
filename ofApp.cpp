//refered to tado's code
//https://github.com/tado

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
     ofSetFrameRate(60);
     ofBackground(60);
     ofEnableSmoothing();
     glEnable(GL_BLEND);
     glBlendFunc(GL_SRC_ALPHA, GL_ONE);
     ofSetCircleResolution(64);
}

//--------------------------------------------------------------
void ofApp::update(){
     for (int i = 0; i < NUM; i++) {
          particle[i].resetForce();
          particle[i].addForce(ofVec2f(ofRandom(-1,1), ofRandom(-1,1)));
          particle[i].friction();
          particle[i].EOM();
          //particle[i].speedLimit(max);
          particle[i].Bound();
     }
     /*img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
     img.save("screen"+ofGetTimestampString()+".png");*/
}

//--------------------------------------------------------------
void ofApp::draw(){
     for (int i = 0; i < NUM; i++) {
          particle[i].draw();
     }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
     for (int i = 0; i < NUM; i++) {
          ofVec2f pos = ofVec2f(x, y);
          float length = ofRandom(60);
          float angle = ofRandom(PI * 2);
          ofVec2f vel = ofVec2f(cos(angle) * length, sin(angle) * length);

          particle[i].setup(pos, vel);
          particle[i].radius = ofRandom(15);
     }
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
