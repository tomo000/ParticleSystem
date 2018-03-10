#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
     ofSetFrameRate(60);
     ofBackground(60);
     ofSetCircleResolution(32);
}

//--------------------------------------------------------------
void ofApp::update(){
     for (int i = 0; i < NUM; i++) {
          particle[i].resetForce();
          particle[i].addForce(ofVec2f(ofRandom(-1,1), ofRandom(-1,1)));
          particle[i].updateForce();
          particle[i].updatePos();
          particle[i].checkScreen(0, 0, ofGetWidth(), ofGetHeight());
     }

}

//--------------------------------------------------------------
void ofApp::draw(){
     for (int i = 0; i < NUM; i++) {
          particle[i].draw();
     }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
     if (key == 'f') {
          ofToggleFullscreen();
     }
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
          particle[i].radius = ofRandom(10);
          particle[i].friction = 0.01;
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
