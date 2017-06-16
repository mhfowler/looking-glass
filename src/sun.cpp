#include "sun.h"


//--------------------------------------------------------------
void sun::init(appData* aData, float x, float y) {
    a = aData;
    startX = x;
    startY = y;
    tStart = ofGetElapsedTimef();
    
    float triSize = 20;
    tri1 = ofVec2f(ofRandom(-triSize, triSize), ofRandom(-triSize, triSize));
    tri2 = ofVec2f(ofRandom(-triSize, triSize), ofRandom(-triSize, triSize));
    tri3 = ofVec2f(ofRandom(-triSize, triSize), ofRandom(-triSize, triSize));
    
}

//--------------------------------------------------------------
void sun::draw() {
    
    float t = ofGetElapsedTimef() - tStart;
    
    ofPolyline line;
    ofSetColor(255);
    ofSetLineWidth(1);
    
    ofSetColor(255, 0, 0);
//    ofDrawCircle(startX, startY, 5);
    
    float pathPercent = ofMap(t, 0, 10, 0, 1);
    
    ofPoint origin = ofPoint(startX, startY);
    ofVec2f pathToCenter = a->centerPoint - origin;
    ofVec2f scaledVec = pathToCenter * pathPercent;
    
    ofPoint loc = origin + scaledVec;
    ofSetColor(255, 255, 255, 200);
//    ofDrawCircle(loc.x, loc.y, 5);
    
    ofPoint tr1 = ofPoint(loc + tri1);
    ofPoint tr2 = ofPoint(loc + tri2);
    ofPoint tr3 = ofPoint(loc + tri3);
    
    ofSetColor(255, 255, 255, 155);
    ofPolyline l1 = ofPolyline({tr1, tr2, tr3, tr1});
    l1.draw();
}
