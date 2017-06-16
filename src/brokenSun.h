#include "ofMain.h"
#include "colorSun.h"

class  brokenSun {
public:
    void draw();
    
    void init(appData* aData, float x, float y, int wMirror, ofColor xCol);
    
    appData* a;
    float startX = 100;
    float startY = 100;
    float tStart;
    int whichMirror;
    ofPoint mirrorCenter;
    ofPolyline mirrorLine;
    
    ofVec2f tri1;
    ofVec2f tri2;
    ofVec2f tri3;
    
    ofColor col;
    
    vector<ofPoint> xPoints;
    int numFrames = 0;
    
    ofPoint origin;
    ofVec2f path;
    ofVec2f scaledVec;
    ofPoint loc;
    ofPolyline mLine;
};


