#include "ofMain.h"
#include "appData.h"

class  sun {
public:
    void draw();
    
    void init(appData* aData, float x, float y);
    
    appData* a;
    float startX = 100;
    float startY = 100;
    float tStart;
    
    ofVec2f tri1;
    ofVec2f tri2;
    ofVec2f tri3;
};


