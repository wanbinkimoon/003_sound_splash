//
//  ofApp.hpp
//  001_midi_module
//
//  Created by nicola bertelloni on 25/12/2019.
//

#pragma once

#include "ofMain.h"
#include "ofMidiModule.h"
#include "ofSoundModule.h"
#include "ofColorModule.h"
#include "ofxAudioAnalyzer.h"

class ofApp : public ofBaseApp{
  
public:
  void setup();
  void update();
  void draw();
  
  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y );
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void mouseEntered(int x, int y);
  void mouseExited(int x, int y);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);
  
  void background_1();
  void background_2();
  void background_3();
  void background_4();
  
  void boxes();
  void stars();
  
  ofShader shader_back_1;
  ofShader shader_back_2;
  ofShader shader_back_3;
  ofShader shader_back_4;
  
  
  ofShader shader_black;
  ofShader shader_grad;
  
  shared_ptr<ofMidiModule> midi;
  shared_ptr<ofSoundModule> sound;
  shared_ptr<ofColorModule> color;
  bool FULLSCREEN;
};
