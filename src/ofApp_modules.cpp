//
//  ofApp_modules.cpp
//  003_sound_splash
//
//  Created by nicola bertelloni on 11/01/2020.
//

#include "ofApp.h"
void ofApp::background_1(){
  shader_back_1.begin();
  shader_back_1.setUniform1f("u_time", ofGetElapsedTimef());
  shader_back_1.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
  shader_back_1.setUniform1f("u_sound", sound->centroid);
  ofFill();
  ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
  shader_back_1.end();
}

void ofApp::background_2(){
  shader_back_2.begin();
  shader_back_2.setUniform1f("u_time", ofGetElapsedTimef());
  shader_back_2.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
  shader_back_2.setUniform1f("u_sound", sound->centroid);
  ofFill();
  ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
  shader_back_2.end();
}

void ofApp::background_3(){
  shader_back_3.begin();
  shader_back_3.setUniform1f("u_time", ofGetElapsedTimef());
  shader_back_3.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
  shader_back_3.setUniform1f("u_sound", sound->centroid);
  ofFill();
  ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
  shader_back_3.end();
}

void ofApp::background_4(){
  shader_back_4.begin();
  shader_back_4.setUniform1f("u_time", ofGetElapsedTimef());
  shader_back_4.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
  shader_back_4.setUniform1f("u_sound", sound->centroid);
  ofFill();
  ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
  shader_back_4.end();
}

void ofApp::boxes(){
  int side = 200;
  int maxZ = 600;
  ofNoFill(); ofSetColor(255);
  ofDrawRectangle(
                  ofGetWidth() * .5 - side + side * .1 + 1,
                  ofGetHeight() * .5 - side + side * .1 + 1,
                  side * 2 - side * .2 - 2,
                  side * 2 - side * .2 - 2);
  
  
  shader_black.begin();
  ofFill();
  ofDrawBox(ofGetWidth() * .5 - side  * .5 - side * .1, ofGetHeight() * .5 - side * .5 - side * .1, ofMap(sound->bands[1], 0, 1, -maxZ, maxZ) * .5, side, side, side * 2 + ofMap(sound->bands[1], 0, 1, -maxZ, maxZ));
  ofDrawBox(ofGetWidth() * .5 + side  * .5 + side * .1, ofGetHeight() * .5 - side * .5 - side * .1, ofMap(sound->bands[2], 0, 1, -maxZ, maxZ) * .5, side, side, side * 2 + ofMap(sound->bands[2], 0, 1, -maxZ, maxZ));
  ofDrawBox(ofGetWidth() * .5 - side  * .5 - side * .1, ofGetHeight() * .5 + side * .5 + side * .1, ofMap(sound->bands[4], 0, 1, -maxZ, maxZ) * .5, side, side, side * 2 + ofMap(sound->bands[4], 0, 1, -maxZ, maxZ));
  ofDrawBox(ofGetWidth() * .5 + side  * .5 + side * .1, ofGetHeight() * .5 + side * .5 + side * .1, ofMap(sound->bands[6], 0, 1, -maxZ, maxZ) * .5, side, side, side * 2 + ofMap(sound->bands[6], 0, 1, -maxZ, maxZ));
  shader_black.end();
  
  shader_grad.begin();
  ofNoFill(); ofSetColor(255);
  ofDrawBox(ofGetWidth() * .5 - side  * .5 - side * .1, ofGetHeight() * .5 - side * .5 - side * .1, ofMap(sound->bands[1], 0, 1, -maxZ, maxZ) * .5, side, side, side * 2 + ofMap(sound->bands[1], 0, 1, -maxZ, maxZ));
  ofDrawBox(ofGetWidth() * .5 + side  * .5 + side * .1, ofGetHeight() * .5 - side * .5 - side * .1, ofMap(sound->bands[2], 0, 1, -maxZ, maxZ) * .5, side, side, side * 2 + ofMap(sound->bands[2], 0, 1, -maxZ, maxZ));
  ofDrawBox(ofGetWidth() * .5 - side  * .5 - side * .1, ofGetHeight() * .5 + side * .5 + side * .1, ofMap(sound->bands[4], 0, 1, -maxZ, maxZ) * .5, side, side, side * 2 + ofMap(sound->bands[4], 0, 1, -maxZ, maxZ));
  ofDrawBox(ofGetWidth() * .5 + side  * .5 + side * .1, ofGetHeight() * .5 + side * .5 + side * .1, ofMap(sound->bands[6], 0, 1, -maxZ, maxZ) * .5, side, side, side * 2 + ofMap(sound->bands[6], 0, 1, -maxZ, maxZ));
  shader_grad.end();
}

void ofApp::stars(){}
