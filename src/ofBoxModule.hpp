//
//  ofBoxModule.hpp
//  003_sound_splash
//
//  Created by nicola bertelloni on 11/01/2020.
//

#ifndef ofBoxModule_hpp
#define ofBoxModule_hpp

#include "ofMain.h"
#include "ofColorModule.h"
#include "ofMidiModule.h"


class Box : public ofBaseApp{
  
public:
  void draw(float sound, float startTime, shared_ptr<ofColorModule> color, int side, int maxZ, float x, float y);
  int z = 0;
};

#endif /* ofBoxModule_hpp */
