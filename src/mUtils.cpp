#include "mUtils.h"


//--------------------------------------------------------------
void mUtils::drawCircle(float x, float y, float rad, float blur_max) {
    //    ofDrawCircle(x, y, rad);
    ofPolyline line;
    
    for (int i=1; i<100; i++) {
        float x_pos = x + rad*cos(i);
        float y_pos = y + rad*sin(i);
        
        float ySkew = ofMap(x_pos, 0, ofGetWidth(), -100, ofGetHeight());
        y_pos += ySkew;
        
        float x_blur = ofMap(x_pos, 0, ofGetWidth(), 200, 0);
        float y_blur = ofMap(y_pos, 0, ofGetHeight(), 200, 0);
        float blur = ofMap(rad, 900, 0, 0, blur_max);
        
        line.addVertex(ofPoint(x_pos + ofRandom(-blur, blur), y_pos + ofRandom(-blur, blur)));
        //        line.addVertex(ofPoint(x_pos + ofRandom(0, x_blur), y_pos + ofRandom(0, y_blur)));
    }
    
    for (int i=1; i<100; i++) {
        line.getVertices();
        
    }
    
    line.draw();
}
