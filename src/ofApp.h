#pragma once

#include "ofMain.h"
#include "ofUtils.h"
#include "ofxSyphon.h"
#include "ofxOsc.h"

#include "mUtils.h"
#include "sun.h"

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
    void drawTestNames();
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
    
    // time constants
    float tStart = 0;
    float t;
    
    // helpers
    void loadLines(string inputPath, vector<ofPolyline>* lineVector);
    void loadPoints(string inputPath, vector<ofPoint>* pointVector);
    
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
    
    // change animations
    char currentAnimation = 'y';
    char nextAnimation = '5';
    bool animationChanged = false;
    
    // for manually drawing lines
    ofPoint cursor;
    ofPolyline currentLine;
    
    // for storing and loading lines
    ofPoint centerPoint = ofPoint(674,459);
    vector<ofPolyline> mirrorLines;
    vector<ofPoint> mirrorPoints;
    vector<ofPolyline> extraLines;
    vector<ofPoint> extraPoints;
    vector<ofPoint> mirrorCenters;
};
