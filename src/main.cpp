#include "ofMain.h"
#include "ofApp.h"
#include "ofMidiModule.h"
#include "ofSoundModule.h"
#include "ofColorModule.h"
#include "ofPublicScreen.hpp"

#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
  //	ofSetupOpenGL(920, 940, OF_WINDOW);			// <-------- setup the GL context
  //  ofRunApp(new ofMidiModule());
  
  ofGLFWWindowSettings settings;
  
  settings.setSize(700, 500);
  settings.setPosition(glm::vec2(960,480));
  settings.setGLVersion(3,2);
  shared_ptr<ofAppBaseWindow> ofAppWindow = ofCreateWindow(settings);
  shared_ptr<ofApp> MainApp(new ofApp);

  settings.setSize(920, 740);
  settings.setPosition(glm::vec2(20,20));
  settings.shareContextWith = ofAppWindow;
//  settings.setGLVersion(1,0);
  settings.resizable = false;
  shared_ptr<ofAppBaseWindow> ofMidiWindow = ofCreateWindow(settings);
  shared_ptr<ofMidiModule> MidiModule(new ofMidiModule);
  
  settings.setSize(700, 400);
  settings.setPosition(glm::vec2(960,20));
//  settings.setGLVersion(1,0);
  settings.shareContextWith = ofAppWindow;
  settings.resizable = false;
  shared_ptr<ofAppBaseWindow> ofSoundWindow = ofCreateWindow(settings);
  shared_ptr<ofSoundModule> SoundModule(new ofSoundModule);

  
  settings.setSize(920, 220);
  settings.setPosition(glm::vec2(20,820));
  settings.resizable = false;
  settings.shareContextWith = ofAppWindow;
//  settings.setGLVersion(1,0);
  shared_ptr<ofAppBaseWindow> ofColorWindow = ofCreateWindow(settings);
  shared_ptr<ofColorModule> ColorModule(new ofColorModule);

  ofRunApp(ofColorWindow, ColorModule);
  ofRunApp(ofSoundWindow, SoundModule);
  ofRunApp(ofMidiWindow, MidiModule);
  MainApp->midi = MidiModule;
  MainApp->sound = SoundModule;
  MainApp->color = ColorModule;
  ofRunApp(ofAppWindow, MainApp);
  
#ifdef NDEBUG
  settings.setSize(700, 500);
  //  settings.setGLVersion(3,2);
  settings.shareContextWith = ofAppWindow;
  shared_ptr<ofAppBaseWindow> ofPublicWindow = ofCreateWindow(settings);
  shared_ptr<ofPublicScreen> PublicWindow(new ofPublicScreen);
  PublicWindow->app = MainApp;
  ofRunApp(ofPublicWindow, PublicWindow);
#endif
  
  ofRunMainLoop();
}
