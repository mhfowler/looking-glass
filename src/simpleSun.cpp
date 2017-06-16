#include "simpleSun.h"

//--------------------------------------------------------------
void simpleSun::init(appData* aData, float x, float y, int wMirror) {
    a = aData;
    startX = ofRandom(0, ofGetWidth());
    startY = ofRandom(0, ofGetHeight());
    tStart = ofGetElapsedTimef();
    
    whichMirror = ofRandom(0, a->mirrorLines.size());
    mirrorCenter = a->mirrorCenters[whichMirror];
    mirrorLine = a->mirrorLines[whichMirror];
    
    float triSize = 20;
    tri1 = ofVec2f(ofRandom(-triSize, triSize), ofRandom(-triSize, triSize));
    tri2 = ofVec2f(ofRandom(-triSize, triSize), ofRandom(-triSize, triSize));
    tri3 = ofVec2f(ofRandom(-triSize, triSize), ofRandom(-triSize, triSize));
    
    col = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
    
}

//--------------------------------------------------------------
void simpleSun::draw() {
    
    float t = ofGetElapsedTimef() - tStart;
    
    ofPolyline line;
    ofSetColor(255);
    ofSetLineWidth(1);
    
    ofSetColor(255, 0, 0);
    //    ofDrawCircle(startX, startY, 5);
    
    float pathPercent = 0;
    if (t < 5) {
        pathPercent = ofMap(t, 0, 5, 0, 1);
    } else {
        pathPercent = 1;
    }
    
    ofPoint origin = ofPoint(startX, startY);
    ofVec2f path = mirrorCenter - origin;
    ofVec2f scaledVec = path * pathPercent;
    
    ofPoint loc = origin + scaledVec;
    float alpha = ofMap(t, 0, 10, 255, 0);
    ofSetColor(255, 255, 255, alpha);
    
    float tScale = 1;
    //    float alpha = ofMap(t, 0, 5, 255, 0);
    
    //ofPolyline mLine = ofPolyline({origin, loc});
    ofPolyline mLine;
    mLine.addVertex(origin);
    mLine.addVertex(loc);
    mLine.draw();
}
