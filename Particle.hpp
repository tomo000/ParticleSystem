//
//  Particle.hpp
//  openFrameworks
//
//  Created by Tomoya Atsumi on H30/03/08.
//
#pragma once
#include "ofMain.h"

class Particle{

public:
     //initial setup
     void setup(ofVec2f pos, ofVec2f vel);

     //reset force
     void resetForce();

     //add force
     void addForce(ofVec2f f);
     void addForce(ofVec2f f1, ofVec2f f2);
    
     //air resistance
     void friction();

     //equation of motion
     void EOM();

     //bound particle
     void Bound();
     void Screen();

     //speed limit
     void speedLimit(int max);

     //draw
     void draw();

     //vector of position
     ofVec2f position;

     //vector of velocity
     ofVec2f velocity;

     //vector of acceletration
     ofVec2f acceletration;

     //vector of force
     ofVec2f force;

     //set friction
     float fric = 0.01;

     //radius of particle
     float radius;

     //set mass
     float mass;
};
