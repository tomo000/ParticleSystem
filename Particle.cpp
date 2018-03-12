#include "Particle.hpp"

//initial propaty
void Particle::setup(ofVec2f _pos, ofVec2f _vel){
     position = _pos;
     velocity = _vel;
     mass = ofRandom(20);
     radius = 2 * mass;
}

//reset Force
void Particle::resetForce(){
     force.set(0,0);
}

//add force
void Particle::addForce(ofVec2f _f){
     force += _f;
}

//add force
void Particle::addForce(ofVec2f _f1, ofVec2f _f2){
     force += _f1 + _f2;
}

//equation of motion
void Particle::EOM(){
     acceletration = force / mass;
     velocity += acceletration;
     position += velocity;
}

//bound circle
void Particle::Bound(){

     if (position.x < 0 || position.x > ofGetWidth()) {
          velocity.x *= -1;
     }
     if (position.y < 0 || position.y > ofGetHeight()) {
          velocity.y *= -1;
     }


     if (position.x < 0) {
          position.x = 0;
     }
     if (position.x > ofGetWidth()) {
          position.x = ofGetWidth();
     }
     if (position.y < 0) {
          position.y = 0;
     }
     if (position.y > ofGetHeight()) {
          position.y = ofGetHeight();
     }
}

void Particle::Screen(){
     if (position.x < 0) {
          position.x = ofGetWidth() + radius;
     }
     if (position.x > ofGetWidth()) {
          position.x = -radius;
     }


     if (position.y < 0) {
          position.y = ofGetHeight() + radius;
     }
     if (position.y > ofGetHeight()) {
          position.y = -radius;
     }
}

void Particle::speedLimit(int max){
     if(velocity.length() > max){
         velocity.normalize();
         velocity *= max;
     }
}

void Particle::draw(){
     //setup transparency
     ofEnableAlphaBlending();
     glBlendFunc(GL_ONE, GL_ONE);

     //decide color
     ofColor c;
     c.setHsb(ofRandom(255),255,255, 40);

     //set color
     ofSetColor(c);
     ofDrawCircle(position, radius);
}
