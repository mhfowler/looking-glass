#include "ofMain.h"
#include "zSun.h"

class  dSun {
public:
    void draw();
    
    void init(appData* aData, float x, float y, int wMirror);
    
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
};


