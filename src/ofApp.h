#pragma once

#include "ofMain.h"
#include "ofUtils.h"
#include "ofxSyphon.h"
#include "ofxOsc.h"

#include "mUtils.h"
#include "xSun.h"

#define HOST "localhost"
#define PORT 8000

class ofApp : public ofBaseApp{
    
    typedef struct {
        ofPoint a;
        ofPoint b;
    } simpleLine;
    
public:
    
    // system functions
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
    
    
    // different drawings
    void drawTestNames();   // vaporwave
    void drawTest1();
    void drawTestQ();
    void drawTest2();
    void drawTest3();
    void drawTest4();
    void drawTest5(); // converging worlds
    void drawTest6();
    void drawTest7();
    void drawTest8(); // growing lines (flower)
    void drawTest9();
    void drawTest0();
    void drawTestW();
    void drawTestE();
    void drawTestR();
    void drawTestT();
    void drawTestY();
    void drawTestZ();
    void drawTestX();
    void drawTestM();
    void drawTestP();
    void drawTestI(); // slow growth, single images
    void drawTestH(); // gentle growth, more uniform
    void drawTestB(); // gentle uniform growth in and out
    
    // drawing Y
    vector<sun> suns;
    vector<zSun> zSuns;
    vector<xSun> xSuns;
    vector<colorSun> colorSuns;
    
    // time constants
    float tStart = 0;
    float t;
    
    // helpers
    void loadLines(string inputPath, vector<ofPolyline>* lineVector);
    void loadPoints(string inputPath, vector<ofPoint>* pointVector);
    void switchRLine();
    
    // buffers for images
    ofImage img1;
    ofImage img2;
    ofImage img3;
    
    // syphon
    ofxSyphonServer mainOutputSyphonServer;
    ofxOscSender sender;
    
    // constantss
    int width;
    int height;
    float w;
    float h;
    float time;
    float xFactor;
    float yFactor;
    int frameNum = 0;
    
    // loop
    float iSpacing = 0.01;
    int toReplace = 0;
    int maxSuns = 5000;
    
    // drawTestB
    vector<bSun> bSuns;
    ofColor cCol;
    int prevMirror = 100;
    int wMirror = 0;
    vector<int> mirrorMap = {16, 4, 17, 5, 1, 14, 8, 12, 13, 2, 10, 18, 11, 6, 9, 7, 0, 3, 15, 19};
    
    // change animations
    char currentAnimation = 'x';
    char nextAnimation = '5';
    bool animationChanged = false;
    
    // for manually drawing lines
    ofPoint cursor;
    ofPolyline currentLine;
    
    // for storing and loading lines/data
    appData a;
    
    // video
    ofVideoPlayer mPlayer;
    
};
