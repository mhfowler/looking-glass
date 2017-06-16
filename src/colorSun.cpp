#include "colorSun.h"

//--------------------------------------------------------------
void colorSun::init(appData* aData, float x, float y, int wMirror, ofColor xCol) {
    a = aData;
    //    startX = ofRandom(0, ofGetWidth());
    //    startY = ofRandom(0, ofGetHeight());
    //    float u = 10;
    
    startX = x;
    startY = y;
    
    tStart = ofGetElapsedTimef();
    
    //    whichMirror = ofRandom(0, a->mirrorLines.size());
    whichMirror = wMirror;
    mirrorCenter = a->mirrorCenters[whichMirror];
    mirrorLine = a->mirrorLines[whichMirror];
    
    float triSize = 20;
    tri1 = ofVec2f(ofRandom(-triSize, triSize), ofRandom(-triSize, triSize));
    tri2 = ofVec2f(ofRandom(-triSize, triSize), ofRandom(-triSize, triSize));
    tri3 = ofVec2f(ofRandom(-triSize, triSize), ofRandom(-triSize, triSize));
    
    //    col = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
    col = xCol;
    
}

//--------------------------------------------------------------
void colorSun::draw() {
    
    float t = a->time - tStart;
    
    ofPolyline line;
    ofSetColor(255);
    ofSetLineWidth(1);
    
    ofSetColor(255, 0, 0);
    //    ofDrawCircle(startX, startY, 5);
    
    float pathPercent = 0;
    if (t < 4) {
        pathPercent = ofMap(t, 0, 4, 0, 1);
    } else {
        pathPercent = 1;
    }
    
    origin = ofPoint(startX, startY);
    //    ofVec2f path = mirrorCenter - origin;
    path = mirrorCenter - origin;
    scaledVec = path * pathPercent;
    
    loc = origin + scaledVec;
    
    float alpha = ofMap(t, 0, 20, 255, 0);
    //    ofSetColor(255, 255, 255, alpha);
    sCol = ofColor(col.r, col.g, col.b, alpha);
    ofSetColor(sCol);
    
    float tScale = 1;
    //    float alpha = ofMap(t, 0, 5, 255, 0);
    
    //ofPolyline mLine = ofPolyline({origin, loc});
    mLine.addVertex(origin);
    mLine.addVertex(loc);
    mLine.draw();
    //    ofPolyline xLine = ofPolyline(xPoints);
    
    //    xLine.draw();
}
