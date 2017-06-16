#include "ofMain.h"
#include "simpleSun.h"

class  colorSun {
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
    
    ofPolyline mLine;
    ofColor  sCol;
    ofPoint tLoc;
    ofPoint origin;
    ofVec2f path;
    ofVec2f scaledVec;
    ofPoint loc;
};


