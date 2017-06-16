#include "ofMain.h"
#include "sun.h"

class  zSun {
public:
    void draw();
    
    void init(appData* aData, float x, float y);
    
    appData* a;
    float startX = 100;
    float startY = 100;
    float tStart;
    int whichMirror;
    ofPoint mirrorCenter;
    
    ofVec2f tri1;
    ofVec2f tri2;
    ofVec2f tri3;
    
    ofColor col;
};


