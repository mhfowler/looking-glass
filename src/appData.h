#include "ofMain.h"

class  appData {
public:
//    ofPoint centerPoint = ofPoint(674,459);
    ofPoint centerPoint = ofPoint(642,407);
    vector<ofPolyline> mirrorLines;
    vector<ofPoint> mirrorPoints;
    vector<ofPolyline> rLines;
    vector<ofPoint> mirrorCenters;
    int whichRLine = 0;
    float w;
    float h;
    float time;
};


