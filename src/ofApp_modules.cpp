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
  shader_back_3.setUniform3f("u_color_1",
                             ofMap(color->palette[0]->r, 0, 255, 0, 1),
                             ofMap(color->palette[0]->g, 0, 255, 0, 1),
                             ofMap(color->palette[0]->b, 0, 255, 0, 1)
                             );
  shader_back_3.setUniform3f("u_color_2",
                             ofMap(color->palette[1]->r, 0, 255, 0, 1),
                             ofMap(color->palette[1]->g, 0, 255, 0, 1),
                             ofMap(color->palette[1]->b, 0, 255, 0, 1));
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
  ofNoFill(); ofSetColor(255);
  
  
  ofDrawRectangle(
                  ofGetWidth() * .5 - side + side * .1 + 1,
                  ofGetHeight() * .5 - side + side * .1 + 1,
                  side * 2 - side * .2 - 2,
                  side * 2 - side * .2 - 2);
  
  rowsGrid = ofMap(midi->knobsTWO[1], 0, 100, 1, 21);
  colsGrid = ofMap(midi->knobsTWO[9], 0, 100, 1, 21);
  
  maxSquares = rowsGrid * colsGrid * 20;
  for(unsigned int x = 1; x < rowsGrid; x+=2){
    for(unsigned int y = 1; y < colsGrid; y+=2){
      
      float xB = ofGetWidth() * .5 + (side * .5 + side * .1) * x - (rowsGrid / 2 * (side * .5 + side * .1));
      float yB = ofGetHeight() * .5 +  (side * .5 + side * .1)  * y - (colsGrid / 2 * (side * .5 + side * .1));
      float zB = ofMap(sound->bands[x + y * colsGrid % sound->bands.size() -1 ], 0, 1, -maxZ, maxZ) * .5;
      
      if(midi->padsTWO[2]) ofApp::tunnel(xB, yB);
      
      if(midi->padsTWO[1]) {
        shader_black.begin();
        ofFill();
        ofDrawBox(xB, yB, zB, side, side, side * 2 + ofMap(sound->bands[x + y * rowsGrid % 24], 0, 1, 20, 200));
        shader_black.end();
      }
      
      shader_grad.begin();
      shader_grad.setUniform3f("u_color_1",
                                 ofMap(color->palette[2]->r, 0, 255, 0, 1),
                                 ofMap(color->palette[2]->g, 0, 255, 0, 1),
                                 ofMap(color->palette[2]->b, 0, 255, 0, 1)
                                 );
      ofNoFill(); ofSetColor(255);
      ofDrawBox(xB, yB, zB, side, side, side * 2 + ofMap(sound->bands[1], 0, 1, -maxZ, maxZ));
      shader_grad.end();
    }
  }
}

void ofApp::stars(){}

void ofApp::tunnel(float x, float y){
  
  if(ofGetFrameNum() % interval == 0 ){
    ofVec2f data = ofVec2f(ofMap(sound->centroid, 0, 1, 0, 100), ofGetFrameNum());
    squaresData.insert(squaresData.begin(), data);
  }
  
  for(unsigned int i = 0; i < squaresData.size(); i++){
    Box box = Box();
    box.draw(squaresData[i].x, squaresData[i].y, color, side, maxZ, x, y);
  }
  
  if(squaresData.size() > maxSquares){
    squaresData.erase(squaresData.end() - 1);
  }
}
