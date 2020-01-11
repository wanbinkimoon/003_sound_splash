#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetDataPathRoot("../Resources/data/");

  shader_back.load("shader/background/shader");
  shader_black.load("shader/black/shader");
  shader_grad.load("shader/grad/shader");
  
  ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
  
}

//--------------------------------------------------------------
void ofApp::draw(){
  
  shader_back.begin();
  shader_back.setUniform1f("u_time", ofGetElapsedTimef());
  shader_back.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
  shader_back.setUniform1f("u_sound", sound->centroid);
  ofFill();
  ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
  shader_back.end();
  
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

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  std::cout << "Letter pressed: " << key << "\n";
  
//  F = 102
  if(key == 102) FULLSCREEN = !FULLSCREEN;
    
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

