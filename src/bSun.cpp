#include "bSun.h"


//--------------------------------------------------------------
void bSun::init(ofPoint mirrorCenter, int numDirections) {
    
    float k = 100;
    for (int i=0; i<numDirections; i++) {
//        ofVec2f dir = mirrorCenter + ofVec2f(ofRandom(-k, k), ofRandom(-k, k));
        float deltaVal = ofMap(i, 0, numDirections, -k, k);
        ofVec2f dir = mirrorCenter + ofVec2f(deltaVal, deltaVal);
        dirs.push_back(dir);
    }
    
}
