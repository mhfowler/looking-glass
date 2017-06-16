#include "zSun.h"


//--------------------------------------------------------------
void zSun::init(appData* aData, float x, float y) {
    a = aData;
    startX = x;
    startY = y;
    tStart = ofGetElapsedTimef();
    
    float triSize = 20;
    tri1 = ofVec2f(ofRandom(-triSize, triSize), ofRandom(-triSize, triSize));
    tri2 = ofVec2f(ofRandom(-triSize, triSize), ofRandom(-triSize, triSize));
    tri3 = ofVec2f(ofRandom(-triSize, triSize), ofRandom(-triSize, triSize));
    
    whichMirror = ofRandom(0, a->mirrorCenters.size());
    mirrorCenter = a->mirrorCenters[whichMirror];
    
    col = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
    
}

//--------------------------------------------------------------
void zSun::draw() {
    
    float t = ofGetElapsedTimef() - tStart;
    
    ofPolyline line;
    ofSetColor(255);
    ofSetLineWidth(1);
    
    ofSetColor(255, 0, 0);
    //    ofDrawCircle(startX, startY, 5);
    
    float pathPercent = ofMap(t, 0, 10, 0, 1);
    
    ofPoint origin = ofPoint(startX, startY);
    ofVec2f pathToCenter = mirrorCenter - a->centerPoint;
    ofVec2f scaledVec = pathToCenter * (1 + pathPercent);
    
    ofPoint loc = a->centerPoint + scaledVec;
    ofSetColor(255, 255, 255, 200);
    
    float tScale = ofMap(t, 0, 20, 1, 20);
    float alpha = ofMap(t, 0, 10, 255, 0);
    
    ofPoint tr1 = ofPoint(loc + tri1*tScale);
    ofPoint tr2 = ofPoint(loc + tri2*tScale);
    ofPoint tr3 = ofPoint(loc + tri3*tScale);
    
    
    ofSetColor(111, 28, 178, alpha);
//    if (t < 5) {
//        ofSetColor(255, 255, 255, 155);
//    }
//    else {
//        ofSetColor(col);
//    }
    ofPolyline l1 = ofPolyline({tr1, tr2, tr3, tr1});
    l1.draw();
}
