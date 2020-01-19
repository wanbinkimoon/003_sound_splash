//
//  ofBoxModule.cpp
//  003_sound_splash
//
//  Created by nicola bertelloni on 11/01/2020.
//

#include "ofBoxModule.hpp"

void Box::draw(float sound, float startTime, shared_ptr<ofColorModule> color, int side, int maxZ, float x, float y){
  
  z = (ofGetFrameNum() - startTime);
  
  ofSetColor(
             color->palette[2]->r,
             color->palette[2]->g,
             color->palette[2]->b,
             ofMap(z, 0, -maxZ, 255, 0)
             );
  
  ofNoFill();
  ofSetLineWidth(4);
  
  if(z > -maxZ){
    ofPushMatrix();
    ofTranslate(x, y, z);
    ofDrawBox(0, 0, 0, side, side, side * sound);
    ofPopMatrix();
  }
}
