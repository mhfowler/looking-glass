#include "dSun.h"


//--------------------------------------------------------------
void dSun::init(appData* aData, float x, float y, int wMirror) {
    a = aData;
    startX = x;
    startY = y;
    tStart = ofGetElapsedTimef();
    
    float triSize = 20;
    tri1 = ofVec2f(ofRandom(-triSize, triSize), ofRandom(-triSize, triSize));
    tri2 = ofVec2f(ofRandom(-triSize, triSize), ofRandom(-triSize, triSize));
    tri3 = ofVec2f(ofRandom(-triSize, triSize), ofRandom(-triSize, triSize));
    
    whichMirror = wMirror;
    mirrorCenter = a->mirrorCenters[whichMirror];
    mirrorLine = a->mirrorLines[whichMirror];
    
    col = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
    
}

//--------------------------------------------------------------
void dSun::draw() {
    
    float t = ofGetElapsedTimef() - tStart;
    
    ofPolyline line;
    ofSetColor(255);
    ofSetLineWidth(1);
    
    ofSetColor(255, 0, 0);
    //    ofDrawCircle(startX, startY, 5);
    
    float pathPercent = ofMap(t, 0, 5, 0, 1);
    
    ofPoint origin = ofPoint(startX, startY);
    //    ofVec2f path = ofPoint(((a->centerPoint.x + mirrorCenter.x) / 2.0), ofGetHeight()) - mirrorCenter;
    ofVec2f path = ofPoint(mirrorCenter.x, ofGetHeight()) - mirrorCenter;
    ofVec2f scaledVec = path * pathPercent;
    
    ofPoint loc = mirrorCenter + scaledVec;
    ofSetColor(255, 255, 255, 200);
    
    //    float tScale = ofMap(t, 0, 20, 1, 20);
    float tScale = 1;
    float alpha = ofMap(t, 0, 5, 255, 0);
    
    vector<ofPoint> mPoints = mirrorLine.getVertices();
    ofPolyline mLine;
    ofPoint mPoint;
    ofVec2f relVec;
    for (int i = 0; i < mPoints.size(); i++) {
        relVec = (mPoints[i] - mirrorCenter) * tScale;
        mPoint = loc + relVec;
        mLine.addVertex(mPoint);
    }
    //    ofSetColor(111, 28, 178, alpha);
    ofSetColor(255, 255, 255, alpha);
    mLine.draw();
}
