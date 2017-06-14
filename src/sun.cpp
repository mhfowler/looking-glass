#include "sun.h"


//--------------------------------------------------------------
void sun::init(float x, float y) {
    startX = x;
    startY = y;
}

//--------------------------------------------------------------
void sun::draw() {
    ofPolyline line;
    ofSetColor(255);
    ofSetLineWidth(1);
    ofDrawCircle(startX, startY, 10);
}
