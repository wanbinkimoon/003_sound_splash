#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetDataPathRoot("../Resources/data/");
  
  ofBackground(0);
  
  shader_back_1.load("shader/background_1/shader");
  shader_back_2.load("shader/background_2/shader");
  shader_back_3.load("shader/background_3/shader");
  shader_back_4.load("shader/background_4/shader");
  shader_black.load("shader/black/shader");
  shader_grad.load("shader/grad/shader");
  
  color->palette[0] = ofColor(125, 10, 255);
  color->palette[1] = ofColor(255, 10, 125);
  color->palette[2] = ofColor(255, 255, 255);
  color->palette[3] = ofColor(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
  
}

//--------------------------------------------------------------
void ofApp::draw(){
  if(midi->padsONE[2]) {
    ofSetBackgroundAuto(false);
  } else {
    ofBackground(color->palette[3]);
  }
  
  
  if(sound->bands.size() < 1) return;
  
    
  side = ofMap(midi->knobsTWO[0], 0, 100, 50, 250);
  maxZ = ofMap(midi->knobsTWO[8], 0, 100, 50, 400);
  interval = ofMap(midi->knobsTWO[2], 0, 100, 50, 250);
  
  if(midi->padsONE[0]) ofApp::background_1();
  if(midi->padsONE[1]) ofApp::background_2();
//  if(midi->padsONE[2]) ofApp::background_3();
  if(midi->padsONE[3]) ofApp::background_4();
  
  if(midi->padsTWO[0]) ofApp::boxes();

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

