#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    mainOutputSyphonServer.setName("Screen Output");
    sender.setup(HOST, PORT);
    
    width = ofGetWidth();
    height = ofGetHeight();
    
    ofxOscMessage m;
    string oscAddress = "presets/asymmetrical" + std::to_string(currentAnimation);
    m.setAddress(oscAddress);
    m.addBoolArg(true);
    sender.sendMessage(m, false);
    
    cursor = ofPoint(20, 20);
    
    // load images
//    img1.load("/Users/maxfowler/Desktop/unbroken/img/directCircle.png");
    img1.load("/Users/maxfowler/computer/projects/looking-glass/courtyard.jpg");
    img2.load("/Users/maxfowler/computer/projects/looking-glass/trees.jpg");
    img3.load("/Users/maxfowler/computer/projects/looking-glass/img/mapping.jpg");
    
    mPlayer.load("/Users/maxfowler/computer/projects/looking-glass/img/sky.mov");
//    mPlayer.play();
    
//    loadLines("/Users/maxfowler/Desktop/unbroken/lines/mLines-jun12.txt", &a.mirrorLines);
//    loadLines("/Users/maxfowler/Desktop/unbroken/lines/mLines-jun14-evening.txt", &a.mirrorLines);
    loadLines("/Users/maxfowler/computer/projects/looking-glass/lines/mLines-jun15-night.txt", &a.mirrorLines);
     loadLines("/Users/maxfowler/computer/projects/looking-glass/lines/rLines.txt", &a.rLines);
//    loadLines("/Users/maxfowler/Desktop/unbroken/lines/straightLines-jun14.txt", &a.mirrorLines);
    loadPoints("/Users/maxfowler/computer/projects/looking-glass/lines/centers-jun15.txt", &a.mirrorCenters);
//    loadPoints("/Users/maxfowler/Desktop/unbroken/lines/straightCenters-jun14.txt", &a.mirrorCenters);
    
//    ofHideCursor();
    
    ofSetFrameRate(60);
    
    for(int i = 0; i < maxSuns; i++){
        colorSun s;
        colorSuns.push_back(s);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    if (currentAnimation == '1') {
        drawTest1();
    } else if (currentAnimation == '2') {
        drawTest2();
    } else if (currentAnimation == '3') {
        drawTest3();
    } else if (currentAnimation == '4') {
        drawTest4();
    } else if (currentAnimation == '5') {
        drawTest5();
    } else if (currentAnimation == '6') {
        drawTest6();
    } else if (currentAnimation == '7') {
        drawTest7();
    } else if (currentAnimation == '8') {
        drawTest8();
    } else if (currentAnimation == '0') {
        drawTest0();
    } else if (currentAnimation == 'w') {
        drawTestW();
    } else if (currentAnimation == 'n') {
        drawTestNames();
    } else if (currentAnimation == 'r') {
        drawTestR();
    } else if (currentAnimation == 't') {
        drawTestT();
    } else if (currentAnimation == 'y') {
        drawTestY();
    } else if (currentAnimation == 'z') {
        drawTestZ();
    } else if (currentAnimation == 'x') {
        drawTestX();
    } else if (currentAnimation == 'p') {
        drawTestP();
    } else if (currentAnimation == 'i') {
        drawTestI();
    } else if (currentAnimation == 'h') {
        drawTestH();
    } else if (currentAnimation == 'b') {
        drawTestB();
    }
    
    mainOutputSyphonServer.publishScreen();
}


//--------------------------------------------------------------
void ofApp::loadLines(string inputPath, vector<ofPolyline>* lineVector) {
    std::ifstream t(inputPath);
    std::stringstream buffer;
    buffer << t.rdbuf();
    string dataString = buffer.str();
    vector<string> inputLines = ofSplitString(dataString, "/");
    
    for(int i = 0; i < inputLines.size(); i++){
        string lineString = inputLines[i];
        vector<string> inputPoints = ofSplitString(lineString, "\n");
        ofPolyline tLine;
        for(int j = 0; j < inputPoints.size(); j++){
            string pointString = inputPoints[j];
            if (pointString != "") {
                vector<string> linePoints = ofSplitString(pointString, ",");
                float x = ofToFloat(linePoints[0]);
                float y = ofToFloat(linePoints[1]);
                ofPoint tPoint = ofPoint(x, y);
                tLine.addVertex(tPoint);
            }
        }
        vector<ofPoint> tPoints = tLine.getVertices();
        if (tPoints.size() > 0) {
            ofPoint firstPoint = tPoints[0];
            tLine.addVertex(firstPoint);
            lineVector->push_back(tLine);
        }
    }
}


//--------------------------------------------------------------
void ofApp::loadPoints(string inputPath, vector<ofPoint>* pointVector) {
    std::ifstream t(inputPath);
    std::stringstream buffer;
    buffer << t.rdbuf();
    string dataString = buffer.str();
    vector<string> inputPoints = ofSplitString(dataString, "\n");
    ofPolyline tLine;
    for(int j = 0; j < inputPoints.size(); j++){
        string pointString = inputPoints[j];
        if (pointString != "") {
            vector<string> linePoints = ofSplitString(pointString, ",");
            float x = ofToFloat(linePoints[0]);
            float y = ofToFloat(linePoints[1]);
            ofPoint tPoint = ofPoint(x, y);
            pointVector->push_back(tPoint);
        }
    }
}


//--------------------------------------------------------------
void ofApp::update(){
    time = ofGetElapsedTimef();
    frameNum = ofGetFrameNum();
    
    xFactor = ofGetMouseX();
    yFactor = ofGetMouseY();
    
    w = ofGetWidth();
    h = ofGetHeight();
    a.w = w;
    a.h = h;
    a.time = time;
    
    if (animationChanged == true) {
        animationChanged = false;
        ofxOscMessage m;
        string oscAddress = "presets/asymmetrical" + std::to_string(currentAnimation);
        m.setAddress(oscAddress);
        m.addBoolArg(true);
        sender.sendMessage(m, false);
    }
}

//--------------------------------------------------------------
void ofApp::drawTest1(){
    
    float t1 = time - tStart;
    
    ofSetColor(255);
    ofSetLineWidth(1);
    
    int yPos = ofMap(fmod(time, 30), 0, 30, h, 0);
    int spacing = 20;
    int numLines = h / spacing + 1;
    for (int i = 0; i < numLines; i++) {
        int y = (yPos - i * spacing);
        if (y < 0) {
            y = h + y;
        } else if (y >= h && t1 > 5) {
            y = y % int(h);
        }
        ofDrawLine(0, y, w, y);
    }
}

//--------------------------------------------------------------
void ofApp::drawTestQ(){
    ofBackground(0, 0, 0);
    
    w = ofGetWidth();
    h = ofGetHeight();
    ofSetColor(0, 0, 255);
    //    ofBackground(255, 255, 255);
    //    ofSetColor(`0, 0, 0);
    ofNoFill();
    ofSeedRandom(10);
    float t = ofGetElapsedTimef();
    float max_rad = 900;
    //    float num_circles = 50;
    float circle_density = 7;
    float num_seconds = 7.0;
    float max_num_circles = num_seconds * circle_density;
    float rest_seconds = 4.0;
    float num_circles_mod = max_num_circles + (max_num_circles/num_seconds)*rest_seconds;
    float t_factor = max_num_circles / num_seconds;
    float blur_max = ofMap(sin(t/4.0), -1, 1, 0, 100);
    
    int numItems = max_num_circles;
    for (int j=1; j<numItems; j++) {
        //        float blur_max = ofMap(j, 0, numItems, 0, 100);
        //        float blur_max = ofMap(sin(t), -1, 1, 0, 100);
        //        float rad = ofMap(j, 1, t_factor, 0, 900) * 1/4;
        //       drawCircle(w/2.0, h/2.0, 30 + ofRandom(max_rad));
        //        drawCircle(w/2.0, h/2.0, 30 + rad);
        //            float rad = ofMap(j, 1, max_num_circles, 30, 0);
        
        float rad = ofMap(j, 1, max_num_circles, 30, 0);
        
        float newR = ofMap(j, 1, max_num_circles, 0, 255);
        float newG = ofMap(j, 1, max_num_circles, 255, 0);
        float newB = ofMap(j, 1, max_num_circles, 0, 255);
        
        ofSetColor(newR, newG, newB);
        
//        drawCircle(w/2.0, h/2.0, 0 + rad*rad, blur_max);
    }
}

//--------------------------------------------------------------
void ofApp::drawTest2(){
    ofBackground(0, 0, 0);
    ofSetColor(255);
    ofSetLineWidth(2);
    
    float x1 = w/3;
    float x2 = 2*w/3;
    float y1 = h/3;
    float y2 = 2*h/3;
    
    ofDrawLine(x1, y1, x1, y2);
    ofDrawLine(x1, y2, x2, y2);
    ofDrawLine(x2, y2, x2, y1);
    ofDrawLine(x2, y1, x1, y1);
}

//--------------------------------------------------------------
void ofApp::drawTest3(){
    ofBackground(0, 0, 0);
    ofSetColor(255);
    ofSetLineWidth(2);
    
    int numLines = 30;
    float tDelta = ofMap(fmod(time, 30), 0, 30, 235, 0);
    for (int i = 0; i < numLines; i++) {
        float k = i*10 + tDelta;
        float x1 = a.centerPoint.x - k;
        float x2 = a.centerPoint.x + k;
        float y1 = a.centerPoint.y - k;
        float y2 = a.centerPoint.y + k;
        ofDrawLine(x1, y1, x1, y2);
        ofDrawLine(x1, y2, x2, y2);
        ofDrawLine(x2, y2, x2, y1);
        ofDrawLine(x2, y1, x1, y1);
    }
}

//--------------------------------------------------------------
void ofApp::drawTest4(){
    ofBackground(0, 0, 0);
    
    ofBackground(0, 0, 0);
    ofSetColor(255);
    ofSetLineWidth(1);
    
    float x1 = w/3;
    float x2 = 2*w/3;
    float y1 = h/3;
    float y2 = 2*h/3;
    
    ofDrawLine(x1, y1, x1, y2);
    ofDrawLine(x1, y2, x2, y2);
    ofDrawLine(x2, y2, x2, y1);
    ofDrawLine(x2, y1, x1, y1);
    
    ofDrawCircle(cursor.x, cursor.y, 10);
    
    
    /******************* drawing lines with open frameworks */
    ofSetColor(255, 255, 255);
    ofPolyline mLine;
    for(int i = 0; i < a.mirrorLines.size(); i++){
        mLine = a.mirrorLines[i];
        mLine.draw();
    }
    ofPoint mPoint;
    for(int i = 0; i < a.mirrorPoints.size(); i++){
        mPoint = a.mirrorPoints[i];
        ofDrawCircle(mPoint.x, mPoint.y, 10);
    }
}

//--------------------------------------------------------------
void ofApp::drawTest5(){
    
    float t5 = time - tStart;
    
    ofBackground(0, 0, 0);
    ofSetColor(255);
//    ofSetLineWidth(1);
    ofSetLineWidth(2);
    
    /******************* drawing lines with open frameworks */
    ofSetColor(255, 255, 255);
    ofPolyline mLine;
    ofPoint transformedPoint;
    vector<ofPoint> mPoints;
    ofPoint xPoint;
//    int numLines = 1;
    int numLines = 30;
    int numDirections = 30;
    for (int r = 0; r < numDirections; r++) {
        float degs = 2*PI / r;
        for(int i = 0; i < a.mirrorLines.size(); i++){
            mLine = a.mirrorLines[i];
            mLine.draw();
            
            /* sin spacing */
//            float spacing = ofMap(sin(time/2.0), -1, 1, 0, 20, 0);
            
            // *****************/
            // in and out timing
//            float spacing;
//            float alpha = 255;
//            if (t5 < 50) {
//                spacing = ofMap(t5, 0, 50, 40, -20);
//            }
//            else if (t5 < 80) {
//                spacing = ofMap(t5, 50, 80, -20, -40);
//            }
//            else if (t5 < 100) {
//                alpha = ofMap(t5, 80, 100, 255, 0);
//            }
//            else {
//                tStart = time;
//                currentAnimation = '8';
//                cout << "++ transitioning to animation 8" << endl;
//            }
            
            // *****************/
            // converge to center timing
            float spacing;
//            float alpha = ofMap(xFactor, 0, w, 255, 0);
            float baseAlpha = 150;
            float alpha = baseAlpha;
//            cout << "alpha: " << alpha << endl;
//            spacing = ofMap(xFactor, 0, w, 0, 40);
//            cout << "spacing: " << spacing << endl;
            if (t5 < 30) {
                spacing = ofMap(t5, 0, 30, 30, 0.001);
            }
            else if (t5 < 50) {
                spacing = ofMap(t5, 30, 50, 0.001, 0.05);
            }
            else if (t5 < 60) {
                spacing = ofMap(t5, 50, 60, 0.05, 0.2);
            }
            else if (t5 < 80) {
                spacing = ofMap(t5, 60, 80, 0.2, 5);
            }
            else if (t5 < 100) {
                spacing = ofMap(t5, 80, 100, 5, 6);
                alpha = ofMap(t5, 80, 100, baseAlpha, 0);
            }
            else if (t5 < 110) {
                alpha = 0;
            }
            else {
                tStart = time;
                currentAnimation = '8';
                cout << "++ transitioning to animation 8" << endl;
            }
            
            ofSetColor(255, 255, 255, alpha);
            
            mPoints = mLine.getVertices();
            for(int j = 0; j < numLines; j++){
                ofPolyline transformedLine;
                float xDelta = j*numLines*spacing * cos(degs);
                float yDelta = j*numLines*spacing * sin(degs);
                for(int k = 0; k < mPoints.size(); k++) {
                    xPoint = mPoints[k];
                    transformedPoint = ofPoint(xPoint.x + xDelta, xPoint.y - yDelta);
                    transformedLine.addVertex(transformedPoint);
                }
                transformedLine.draw();
            }
        }
    }
    
    ofSetColor(255, 255, 255, 255);
    ofPolyline dLine;
    for (int i = 0; i < a.mirrorLines.size(); i++) {
        dLine = a.mirrorLines[i];
        dLine.draw();
    }
}

//--------------------------------------------------------------
void ofApp::drawTest6(){
    ofBackground(0, 0, 0);
    ofSetColor(255);
    ofSetLineWidth(1);
    
    float x1 = w/3;
    float x2 = 2*w/3;
    float y1 = h/3;
    float y2 = 2*h/3;
    
    ofDrawLine(x1, y1, x1, y2);
    ofDrawLine(x1, y2, x2, y2);
    ofDrawLine(x2, y2, x2, y1);
    ofDrawLine(x2, y1, x1, y1);
    
    /******************* drawing lines with open frameworks */
    ofSetColor(255, 255, 255);
    ofPolyline mLine;
    ofPoint transformedPoint;
    vector<ofPoint> mPoints;
    ofPoint xPoint;
    int numLines = 1;
    int numDirections = 30;
    for (int r = 0; r < numDirections; r++) {
        float degs = 2*PI / r;
        for(int i = 0; i < a.mirrorLines.size(); i++){
            mLine = a.mirrorLines[i];
            mLine.draw();
            float spacing = ofMap(sin(time/2.0), -1, 1, 0, 20, 0);
            mPoints = mLine.getVertices();
            for(int j = 0; j < numLines; j++){
                ofPolyline transformedLine;
                float xDelta = j*numLines*spacing * cos(degs);
                float yDelta = j*numLines*spacing * sin(degs);
                for(int k = 0; k < mPoints.size(); k++) {
                    xPoint = mPoints[k];
                    transformedPoint = ofPoint(xPoint.x + xDelta, xPoint.y - yDelta);
                    transformedLine.addVertex(transformedPoint);
                }
                transformedLine.draw();
            }
        }
    }
    
    ofPoint mPoint;
    for(int i = 0; i < a.mirrorPoints.size(); i++){
        mPoint = a.mirrorPoints[i];
        ofDrawCircle(mPoint.x, mPoint.y, 10);
    }
}

//--------------------------------------------------------------
void ofApp::drawTest7(){
    ofBackground(0, 0, 0);
    ofSetColor(255);
    ofSetLineWidth(1);
    
    float x1 = w/3;
    float x2 = 2*w/3;
    float y1 = h/3;
    float y2 = 2*h/3;
    
    ofDrawLine(x1, y1, x1, y2);
    ofDrawLine(x1, y2, x2, y2);
    ofDrawLine(x2, y2, x2, y1);
    ofDrawLine(x2, y1, x1, y1);
    
    /******************* drawing lines with open frameworks */
    ofSetColor(255, 255, 255);
    ofPolyline mLine;
    ofPoint transformedPoint;
    vector<ofPoint> mPoints;
    ofPoint xPoint;
//    int numLines = 10;
    ofSeedRandom(12121);
    int numLines = ofMap(sin(time/10.0), -1, 1, 0, 20, 0);
    int numMirrors = a.mirrorLines.size();
        for(int i = 0; i < numLines; i++){
            int startIndex = ofRandom(0, numMirrors);
            int endIndex = ofRandom(0, numMirrors);
            ofPolyline startMirror = a.mirrorLines[startIndex];
            ofPolyline endMirror = a.mirrorLines[endIndex];
            int startPointIndex = ofRandom(0, startMirror.size());
            int endPointIndex = ofRandom(0, endMirror.size());
            ofPoint startPoint = startMirror.getVertices()[startPointIndex];
            ofPoint endPoint = endMirror.getVertices()[endPointIndex];
            ofPolyline l;
            l.addVertex(startPoint);
            l.addVertex(endPoint);
            l.draw();
        }
}

//--------------------------------------------------------------
void ofApp::drawTest8(){
    
    float t8 = time - tStart;
    
    ofBackground(0, 0, 0);
    ofSetColor(255);
    ofSetLineWidth(1);
    
    /******************* drawing lines with open frameworks */
    ofPolyline mLine;
    ofPoint transformedPoint;
    vector<ofPoint> mPoints;
    ofPoint xPoint;
    //    int numLines = 10;
//    ofSeedRandom(12121);
    int timeWave = fmod(time, 2);
    ofSeedRandom(133314);
//    int numLines = ofMap(sin(time/5.0), -1, 1, 0, 10000, 0);
    
    bool addSuns = false;
    float linePercent = 0;
    float alphaPercent = 0.2;
    if (t8 < 10) {
        linePercent = ofMap(t8, 0, 10, 0, 1);
        alphaPercent = ofMap(t8, 0, 10, 0.2, 0.8);
    }
    else if (t8 < 20) {
        linePercent = 1;
        alphaPercent = 0.8;
    }
//    else if (t8 < 30) {
//        linePercent = ofMap(t8, 20, 30, 1, 0);
//        alphaPercent = 0.8;
//    }
    else if (t8 < 30) {
        linePercent = 1;
        alphaPercent = ofMap(t8, 20, 25, 0.8, 0);
        addSuns = true;
    }
    else if (t8 < 50) {
        linePercent = 1;
        alphaPercent = 0;
    }
    else {
        tStart = time;
        currentAnimation = '5';
        cout << "++ transitioning to animation 5" << endl;
        switchRLine();
    }
    float alpha = 200 * alphaPercent;
    
    int numLines = 1000;
    int numMirrors = a.mirrorLines.size();
    ofSetColor(255, 255, 255, alpha);
    for(int i = 0; i < numLines; i++){
        int startIndex = ofRandom(0, numMirrors);
        int endIndex = ofRandom(0, numMirrors);
        ofPolyline startMirror = a.mirrorLines[startIndex];
        int startPointIndex = ofRandom(0, startMirror.size());
        ofPoint startPoint = startMirror.getVertices()[startPointIndex];
        ofVec2f lVec = ofVec2f(startPoint - a.centerPoint);
        float fullLength = lVec.length();
        float tLength = ofMap(linePercent, 0, 1, 0, fullLength);
        ofVec2f tVec = lVec.scale(tLength);
        ofPoint tPoint = ofPoint(a.centerPoint + tVec);
        ofPolyline l;
        l.addVertex(a.centerPoint);
        l.addVertex(tPoint);
        l.draw();
    }
    
    
    // xsuns dropping off
    ofSetColor(255, 255, 255, 255);
    ofPolyline dLine;
    for (int i = 0; i < a.mirrorLines.size(); i++) {
        dLine = a.mirrorLines[i];
        dLine.draw();
    }
    
    if (addSuns) {
        for (int i = 0; i < a.mirrorLines.size(); i++) {
            xSun s;
            s.init(&a, 0, 0, i, ofColor(255, 255, 255));
            xSuns.push_back(s);
        }
        
        while (xSuns.size() > 5000) {
            xSuns.erase(xSuns.begin());
        }
    }
    
    xSun s;
    for(int j = 0; j < xSuns.size(); j++) {
        s = xSuns[j];
        s.draw();
    }
}

//--------------------------------------------------------------
void ofApp::drawTestY(){
    ofBackground(0, 0, 0);
    ofSetColor(255);
    ofSetLineWidth(1);
    
    
//    // code for growing lines
//    float t8 = time - tStart;
//    float linePercent = 0;
//    float alphaPercent = 0.2;
//    if (t8 < 10) {
//        linePercent = ofMap(t8, 0, 10, 0, 1);
//        alphaPercent = ofMap(t8, 0, 10, 0.2, 0.8);
//    }
//    else if (t8 < 20) {
//        linePercent = 1;
//        alphaPercent = 0.8;
//    }
//    else {
//        linePercent = 1;
//    }
//    float alpha = 200 * alphaPercent;
//    int numLines = 1000;
//    int numMirrors = a.mirrorLines.size();
//    ofSetColor(255, 255, 255, alpha);
//    for(int i = 0; i < numLines; i++){
//        int startIndex = ofRandom(0, numMirrors);
//        int endIndex = ofRandom(0, numMirrors);
//        ofPolyline startMirror = a.mirrorLines[startIndex];
//        int startPointIndex = ofRandom(0, startMirror.size());
//        ofPoint startPoint = startMirror.getVertices()[startPointIndex];
//        ofVec2f lVec = ofVec2f(startPoint - a.centerPoint);
//        float fullLength = lVec.length();
//        float tLength = ofMap(linePercent, 0, 1, 0, fullLength);
//        ofVec2f tVec = lVec.scale(tLength);
//        ofPoint tPoint = ofPoint(a.centerPoint + tVec);
//        ofPolyline l;
//        l.addVertex(a.centerPoint);
//        l.addVertex(tPoint);
//        l.draw();
//    }
    
    // code for suns
    float k = ofRandom(0, 100);
//    if (k > 20 && suns.size() < 2000) {
//        sun s;
//        float x = ofRandom(0, w);
//        float y = ofRandom(0, h);
//        s.init(&a, x, y);
//        suns.push_back(s);
//    }
//    
//    sun s;
//    for(int j = 0; j < suns.size(); j++) {
//        s = suns[j];
//        s.draw();
//    }
    
    ofSetColor(0, 0, 255);
//    ofDrawCircle(a.centerPoint.x, a.centerPoint.y, 10);
    
    ofSetColor(255, 255, 255, 255);
    ofPolyline dLine;
    for (int i = 0; i < a.mirrorLines.size(); i++) {
        dLine = a.mirrorLines[i];
        dLine.draw();
    }
    
}


//--------------------------------------------------------------
void ofApp::drawTestZ(){
    ofBackground(0, 0, 0);
    ofSetColor(255);
    ofSetLineWidth(1);
    
    // code for suns
    float k = ofRandom(0, 100);
    if (k > 80 && zSuns.size() < 1000) {
        zSun s;
        float x = ofRandom(0, w);
        float y = ofRandom(0, h);
        s.init(&a, x, y);
        zSuns.push_back(s);
    }
    
    zSun s;
    for(int j = 0; j < zSuns.size(); j++) {
        s = zSuns[j];
        s.draw();
    }
    
    ofSetColor(0, 0, 255);
    //    ofDrawCircle(a.centerPoint.x, a.centerPoint.y, 10);
    
    ofSetColor(111, 28, 178, 255);
    ofPolyline dLine;
    for (int i = 0; i < a.mirrorLines.size(); i++) {
        dLine = a.mirrorLines[i];
        dLine.draw();
    }
    
}


//--------------------------------------------------------------
void ofApp::drawTestX(){
    
    cout << "fps: " << ofGetFrameRate() << endl;
    
    ofBackground(0, 0, 0);
    ofSetColor(255);
    ofSetLineWidth(1);
    
//    float x1 = w/3;
//    float x2 = 2*w/3;
//    float y1 = h/3;
//    float y2 = 2*h/3;
//    
//    ofDrawLine(x1, y1, x1, y2);
//    ofDrawLine(x1, y2, x2, y2);
//    ofDrawLine(x2, y2, x2, y1);
//    ofDrawLine(x2, y1, x1, y1);
    
    // code for suns
    float k = ofRandom(0, 100);
    float modFrame = frameNum % 2;
//    if (k > 99) {
    float r = 1000;
    float cScale = 0.2;
    
    if (frameNum % 100 == 0) {
        cCol = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
//        int i = ofRandom(0, a.mirrorLines.size());
        if (wMirror == a.mirrorLines.size()) {
            wMirror = 0;
        }
        else {
            wMirror = wMirror + 1;
        }
    }
    
//    int i = ofMap(sin(time/4.0), -1, 1, 0, a.mirrorLines.size());
    int i = wMirror;
    for (int i = 0; i < a.mirrorLines.size(); i++) {
        if (modFrame == 0) {
            colorSun s;
            float x = a.centerPoint.x + ofMap(cos(time*cScale), -1, 1, -r, r);
            float y = a.centerPoint.y + ofMap(sin(time*cScale), -1, 1, -r, r);
            //        float x = a.centerPoint.x + ofMap(cos(time*cScale), -1, 1, -r, r);
            //        float y = -400;
            s.init(&a, x, y, i, cCol);
            colorSuns[toReplace] = s;
            if (toReplace == maxSuns) {
                toReplace = 0;
            }
            else {
                toReplace = toReplace + 1;
            }
            
            float x2 = a.centerPoint.x - ofMap(cos(time*cScale), -1, 1, -r, r);
            float y2 = a.centerPoint.y - ofMap(sin(time*cScale), -1, 1, -r, r);
            //        y = h + 400;
            s.init(&a, x2, y2, i, cCol);
            colorSuns[toReplace] = s;
            if (toReplace == maxSuns) {
                toReplace = 0;
            }
            else {
                toReplace = toReplace + 1;
            }
        }
    }
    
    colorSun s;
    for(int j = 0; j < colorSuns.size(); j++) {
        s = colorSuns[j];
        s.draw();
    }
    
//    ofSetColor(0, 0, 255);
//        ofDrawCircle(a.centerPoint.x, a.centerPoint.y, 10);
    
    ofSetColor(255, 255, 255, 255);
    ofPolyline dLine;
    for (int i = 0; i < a.mirrorLines.size(); i++) {
        dLine = a.mirrorLines[i];
        dLine.draw();
    }
    
}

//--------------------------------------------------------------
void ofApp::drawTestM(){
    ofBackground(0, 0, 0);
    ofSetColor(255);
    ofSetLineWidth(1);
    
    //    float x1 = w/3;
    //    float x2 = 2*w/3;
    //    float y1 = h/3;
    //    float y2 = 2*h/3;
    //
    //    ofDrawLine(x1, y1, x1, y2);
    //    ofDrawLine(x1, y2, x2, y2);
    //    ofDrawLine(x2, y2, x2, y1);
    //    ofDrawLine(x2, y1, x1, y1);
    
    // code for suns
    float k = ofRandom(0, 100);
    float modFrame = ofGetFrameNum() % 2;
    //    if (k > 99) {
    float r = 1000;
    float cScale = 0.4;
    
    if (ofGetFrameNum() % 20 == 0) {
        cCol = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
        int i = ofRandom(0, a.mirrorLines.size());
        if (modFrame == 0) {
            xSun s;
            float x = a.centerPoint.x + ofMap(cos(time*cScale), -1, 1, -r, r);
            float y = a.centerPoint.y + ofMap(sin(time*cScale), -1, 1, -r, r);
            //        float x = a.centerPoint.x + ofMap(cos(time*cScale), -1, 1, -r, r);
            //        float y = -400;
            s.init(&a, x, y, i, cCol);
            xSuns.push_back(s);
            
            float x2 = a.centerPoint.x - ofMap(cos(time*cScale), -1, 1, -r, r);
            float y2 = a.centerPoint.y - ofMap(sin(time*cScale), -1, 1, -r, r);
            //        y = h + 400;
            s.init(&a, x2, y2, i, cCol);
            xSuns.push_back(s);
        }
    }
    
    while (xSuns.size() > 1000) {
        xSuns.erase(xSuns.begin());
    }
    
    xSun s;
    for(int j = 0; j < xSuns.size(); j++) {
        s = xSuns[j];
        s.draw();
    }
    
    //    ofSetColor(0, 0, 255);
    //        ofDrawCircle(a.centerPoint.x, a.centerPoint.y, 10);
    
    ofSetColor(255, 255, 255, 255);
    ofPolyline dLine;
    for (int i = 0; i < a.mirrorLines.size(); i++) {
        dLine = a.mirrorLines[i];
        dLine.draw();
    }
    
}


//--------------------------------------------------------------
void ofApp::drawTest0(){
    ofBackground(0, 0, 0);
    ofSetColor(255);
    ofSetLineWidth(1);
    
    
    /******************* drawing lines with open frameworks */
    ofSetColor(255, 255, 255);
    ofPolyline mLine;
    ofPoint transformedPoint;
    vector<ofPoint> mPoints;
    ofPoint xPoint;
    //    int numLines = 10;
    //    ofSeedRandom(12121);
    int timeWave = fmod(time, 2);
    ofSeedRandom(133314);
    //    int numLines = ofMap(sin(time/5.0), -1, 1, 0, 10000, 0);
//    int numLines = 1000;
    int numLines = ofMap(52, 0, w, 0, 1000);
    int radius = ofMap(859, 0, h, 0, 800);
    int numMirrors = a.mirrorLines.size();
    float deltaX = ofMap(cos(time/2.0), -1, 1, -radius, radius, 0);
    float deltaY = ofMap(sin(time/2.0), -1, 1, -radius, radius, 0);
    int numFocii = 3;
    for(int j = 0; j < numFocii; j++){
        ofPoint focii = ofPoint(a.centerPoint.x + ofRandom(-500, 500), a.centerPoint.y + ofRandom(-500, 500));
        ofPoint transformedCenterPoint = ofPoint(focii.x + deltaX, focii.y + deltaY);
        for(int i = 0; i < numLines; i++){
            int startIndex = ofRandom(0, numMirrors);
            int endIndex = ofRandom(0, numMirrors);
            ofPolyline startMirror = a.mirrorLines[startIndex];
            int startPointIndex = ofRandom(0, startMirror.size());
            ofPoint startPoint = startMirror.getVertices()[startPointIndex];
            ofPolyline l;
            l.addVertex(transformedCenterPoint);
            l.addVertex(startPoint);
            l.draw();
        }
    }
}

//--------------------------------------------------------------
void ofApp::drawTestW(){
    ofBackground(0, 0, 0);
    ofSetColor(255);
    ofSetLineWidth(1);
    
    
    /******************* drawing lines with open frameworks */
    ofSetColor(255, 255, 255);
    ofPolyline mLine;
    ofPoint transformedPoint;
    vector<ofPoint> mPoints;
    ofPoint xPoint;
    //    int numLines = 10;
    //    ofSeedRandom(12121);
    int timeWave = fmod(time, 2);
    ofSeedRandom(133314);
    //    int numLines = ofMap(sin(time/5.0), -1, 1, 0, 10000, 0);
    int numLines = 1000;
    int numMirrors = a.mirrorLines.size();
//    for(int i = 0; i < numLines; i++){
//        int startIndex = ofRandom(0, numMirrors);
//        int endIndex = ofRandom(0, numMirrors);
//        ofPolyline startMirror = a.mirrorLines[startIndex];
//        int startPointIndex = ofRandom(0, startMirror.size());
//        ofPoint startPoint = startMirror.getVertices()[startPointIndex];
//        ofPolyline l;
//        l.addVertex(a.centerPoint);
//        l.addVertex(startPoint);
//        l.draw();
//    }
    
    for(int i = 0; i < numMirrors; i++) {
        ofPolyline cMirror = a.mirrorLines[i];
        ofPoint mirrorCenter = a.mirrorCenters[i];
        ofPolyline l;
        l.addVertex(a.centerPoint);
        l.addVertex(mirrorCenter);
        l.draw();
    }
    
    numLines = 80;
    for(int k = 0; k < numLines; k++) {
        float spacing = ofMap(sin(time/1.5), -1, 1, 0, 0.35, 0);
        float scale = 1 + k * spacing;
        for(int i = 0; i < numMirrors; i++) {
            ofPolyline cMirror = a.mirrorLines[i];
            vector<ofPoint> mPoints = cMirror.getVertices();
            ofPoint mirrorCenter = a.mirrorCenters[i];
//            ofPoint startPoint = mPoints[0];
            ofVec2f radius = mirrorCenter - a.centerPoint;
            ofVec2f eRadius = radius * scale;
            ofVec2f eDelta = eRadius - radius;
            ofPolyline nLine;
            for(int j = 0; j < mPoints.size(); j++) {
                ofPoint mPoint = mPoints[j];
                ofPoint nPoint = mPoint + eDelta;
                nLine.addVertex(nPoint);
            }
            nLine.draw();
        }
    }
}

//--------------------------------------------------------------
void ofApp::drawTestE(){
    ofBackground(0, 0, 0);
    ofSetColor(255);
    ofSetLineWidth(1);
    
    
    /******************* drawing lines with open frameworks */
    ofSetColor(255, 255, 255);
    ofPolyline mLine;
    ofPoint transformedPoint;
    vector<ofPoint> mPoints;
    ofPoint xPoint;
    //    int numLines = 10;
    //    ofSeedRandom(12121);
    int timeWave = fmod(time, 2);
    ofSeedRandom(133314);
    //    int numLines = ofMap(sin(time/5.0), -1, 1, 0, 10000, 0);
    int numLines = 1000;
    int numMirrors = a.mirrorLines.size();
    //    for(int i = 0; i < numLines; i++){
    //        int startIndex = ofRandom(0, numMirrors);
    //        int endIndex = ofRandom(0, numMirrors);
    //        ofPolyline startMirror = a.mirrorLines[startIndex];
    //        int startPointIndex = ofRandom(0, startMirror.size());
    //        ofPoint startPoint = startMirror.getVertices()[startPointIndex];
    //        ofPolyline l;
    //        l.addVertex(a.centerPoint);
    //        l.addVertex(startPoint);
    //        l.draw();
    //    }
    
    for(int i = 0; i < numMirrors; i++) {
        ofPolyline cMirror = a.mirrorLines[i];
        ofPoint mirrorCenter = a.mirrorCenters[i];
        ofPolyline l;
        l.addVertex(a.centerPoint);
        l.addVertex(mirrorCenter);
        l.draw();
    }
    
    numLines = 80;
    for(int k = 0; k < numLines; k++) {
        float spacing = ofMap(sin(time/1.5), -1, 1, 0, 0.35, 0);
        float scale = 1 + k * spacing;
        for(int i = 0; i < numMirrors; i++) {
            ofPolyline cMirror = a.mirrorLines[i];
            vector<ofPoint> mPoints = cMirror.getVertices();
            ofPoint mirrorCenter = a.mirrorCenters[i];
            //            ofPoint startPoint = mPoints[0];
            ofVec2f radius = mirrorCenter - a.centerPoint;
            ofVec2f eRadius = radius * scale;
            ofVec2f eDelta = eRadius - radius;
            ofPolyline nLine;
            for(int j = 0; j < mPoints.size(); j++) {
                ofPoint mPoint = mPoints[j];
                ofPoint nPoint = mPoint + eDelta;
                nLine.addVertex(nPoint);
            }
            nLine.draw();
        }
    }
}

//--------------------------------------------------------------
void ofApp::drawTestNames(){
    ofBackground(0, 0, 0);
    ofSetColor(255);
    ofSetLineWidth(1);
    
    float x1 = w/3;
    float x2 = 2*w/3;
    float y1 = h/3;
    float y2 = 2*h/3;
    
    ofDrawLine(x1, y1, x1, y2);
    ofDrawLine(x1, y2, x2, y2);
    ofDrawLine(x2, y2, x2, y1);
    ofDrawLine(x2, y1, x1, y1);
    
    ofDrawCircle(cursor.x, cursor.y, 10);
    
    
    /******************* drawing lines with open frameworks */
    ofSetColor(255, 255, 255);
    ofPolyline mLine;
    for(int i = 0; i < a.mirrorLines.size(); i++){
        mLine = a.mirrorLines[i];
        mLine.draw();
    }
    ofPoint mPoint;
    for(int i = 0; i < a.mirrorPoints.size(); i++){
        mPoint = a.mirrorPoints[i];
        ofDrawCircle(mPoint.x, mPoint.y, 10);
    }
    
    int numMirrors = a.mirrorLines.size();
    for(int i = 0; i < numMirrors; i++) {
        ofPolyline cMirror = a.mirrorLines[i];
        ofPoint cPoint = cMirror.getVertices()[0];
        ofSetColor(255, 0, 0);
        ofDrawCircle(cPoint.x, cPoint.y, 10);
        ofSetColor(255, 255, 255);
        ofDrawBitmapString(std::to_string(i), cPoint.x + 5, cPoint.y + 5);
    }
    
    for(int i = 0; i < a.mirrorCenters.size(); i++){
        mPoint = a.mirrorCenters[i];
        ofDrawCircle(mPoint.x, mPoint.y, 10);
    }
}


//--------------------------------------------------------------
void ofApp::drawTestP(){
    ofBackground(0, 0, 0);
    ofSetColor(255);
    ofSetLineWidth(1);
    
    float x1 = w/3;
    float x2 = 2*w/3;
    float y1 = h/3;
    float y2 = 2*h/3;
    
    ofDrawLine(x1, y1, x1, y2);
    ofDrawLine(x1, y2, x2, y2);
    ofDrawLine(x2, y2, x2, y1);
    ofDrawLine(x2, y1, x1, y1);
    
    ofDrawCircle(cursor.x, cursor.y, 10);
    
    /******************* drawing lines with open frameworks */
    ofSetColor(255, 255, 255);
    ofPolyline mLine;
    for(int i = 0; i < a.mirrorLines.size(); i++){
        mLine = a.mirrorLines[i];
        mLine.draw();
    }
    ofPoint mPoint;
    for(int i = 0; i < a.mirrorPoints.size(); i++){
        mPoint = a.mirrorPoints[i];
        ofDrawCircle(mPoint.x, mPoint.y, 10);
    }
    
    int numMirrors = a.mirrorLines.size();
    for(int i = 0; i < numMirrors; i++) {
        ofPolyline cMirror = a.mirrorLines[i];
        ofPoint cPoint = cMirror.getVertices()[0];
        ofSetColor(255, 0, 0);
        ofDrawCircle(cPoint.x, cPoint.y, 10);
        ofSetColor(255, 255, 255);
        ofDrawBitmapString(std::to_string(i), cPoint.x + 5, cPoint.y + 5);
    }
    
    for(int i = 0; i < a.mirrorCenters.size(); i++){
        mPoint = a.mirrorCenters[i];
        ofDrawCircle(mPoint.x, mPoint.y, 10);
    }
    
    mPlayer.draw(200, 200, 300, 400);
}

//--------------------------------------------------------------
void ofApp::drawTestR(){
    ofBackground(0, 0, 0);
    
    float alpha1 = ofMap(sin(time/2.0), -1, 1, 0, 200);
    ofSetColor(255, 255, 255, alpha1);
    img1.draw(0, 0);
    
    float alpha2 = ofMap(sin(time/2.0), -1, 1, 200, 0);
    ofSetColor(255, 255, 255, alpha2);
    img2.draw(0, 0);
    
    float alpha3 = ofMap(sin(time/3.0), -1, 1, 200, 0);
    ofSetColor(255, 255, 255, alpha3);
    img3.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::switchRLine() {
    //    int rChoice = ofRandom(0, a.rLines.size());
    //    ofPolyline rLine = a.rLines[rChoice];
    
//    if (a.whichRLine == (a.rLines.size()-1)) {
//        a.whichRLine = 0;
//    }
//    else {
//        a.whichRLine = a.whichRLine + 1;
//    }
//    if (a.mirrorLines.size() > 19) {
//        a.mirrorLines.pop_back();
//    }
//    ofPolyline rLine = a.rLines[a.whichRLine];
//    a.mirrorLines.push_back(rLine);
}

//--------------------------------------------------------------
void ofApp::drawTestT(){
    ofBackground(0, 0, 0);
    ofSetLineWidth(1);
    
    float tR = time - tStart;
    
    float alpha = 0;
    if (tR < 5) {
        alpha = ofMap(tR, 0, 5, 0, 255);
    }
    else if (tR < 10) {
        alpha = 255;
    }
    else {
        switchRLine();
        tStart = time;
        cout << "++ transitioning to animation " << nextAnimation << endl;
        currentAnimation = nextAnimation;
    }
    
    ofSetColor(255, 255, 255, alpha);
    ofPolyline mLine;
    for(int i = 0; i < a.mirrorLines.size(); i++){
        mLine = a.mirrorLines[i];
        mLine.draw();
    }
}

//--------------------------------------------------------------
void ofApp::drawTestI(){
    
    float t5 = time - tStart;
    
    ofBackground(0, 0, 0);
    ofSetColor(255);
    ofSetLineWidth(1);
    
    /******************* drawing lines with open frameworks */
    ofSetColor(255, 255, 255);
    ofPolyline mLine;
    ofPoint transformedPoint;
    vector<ofPoint> mPoints;
    ofPoint xPoint;
    //    int numLines = 1;
    int numLines = 30;
    int numDirections = 30;
    for (int r = 0; r < numDirections; r++) {
        float degs = 2*PI / r;
        for(int i = 0; i < a.mirrorLines.size(); i++){
            mLine = a.mirrorLines[i];
            mLine.draw();
            
            /* sin spacing */
            //            float spacing = ofMap(sin(time/2.0), -1, 1, 0, 20, 0);
            
            // *****************/
            // in and out timing
            float spacing;
            float baseAlpha = 160;
            float alpha = baseAlpha;
            if (t5 < 60) {
                iSpacing += 0.0000013;
                spacing = iSpacing;
                if (t5 > 30) {
                    alpha = ofMap(t5, 30, 60, baseAlpha, 0);
                }
            }
            else if (t5 < 80) {
                alpha = 0;
            }
            else {
                iSpacing = 0.01;
                tStart = time;
                currentAnimation = 'i';
                cout << "++ transitioning to animation i" << endl;
            }
            cout << "spacing: " << spacing << endl;
            
//            ofSetColor(255, 255, 255, alpha);
            ofSetColor(0, 0, 255, alpha);
            
            mPoints = mLine.getVertices();
            for(int j = 0; j < numLines; j++){
                ofPolyline transformedLine;
                float xDelta = j*numLines*spacing * cos(degs);
                float yDelta = j*numLines*spacing * sin(degs);
                for(int k = 0; k < mPoints.size(); k++) {
                    xPoint = mPoints[k];
                    transformedPoint = ofPoint(xPoint.x + xDelta, xPoint.y - yDelta);
                    transformedLine.addVertex(transformedPoint);
                }
                transformedLine.draw();
            }
        }
    }
    
    ofSetColor(0, 0, 255, 255);
    ofPolyline dLine;
    for (int i = 0; i < a.mirrorLines.size(); i++) {
        dLine = a.mirrorLines[i];
        dLine.draw();
    }
}

//--------------------------------------------------------------
void ofApp::drawTestH(){
    
    float t5 = time - tStart;
    
    ofBackground(255, 255, 255);
    ofBackground(0,0,0);
    ofSetLineWidth(1);
    
    /******************* drawing lines with open frameworks */
//    ofSetColor(0, 0, 0);
       ofSetColor(255, 255, 255);
    ofPolyline dLine;
    for (int i = 0; i < a.mirrorLines.size(); i++) {
        dLine = a.mirrorLines[i];
        dLine.draw();
    }
    
    int numLines = 80;
    for(int k = 0; k < numLines; k++) {
        float spacing = ofMap(sin(time/3.0), -1, 1, 0, 0.35, 0);
        float scale = 1 + k * spacing;
        for(int i = 0; i < a.mirrorLines.size(); i++) {
            ofPolyline cMirror = a.mirrorLines[i];
            vector<ofPoint> mPoints = cMirror.getVertices();
            ofPoint mirrorCenter = a.mirrorCenters[i];
            //            ofPoint startPoint = mPoints[0];
            ofVec2f radius = mirrorCenter - a.centerPoint;
            ofVec2f eRadius = radius * scale;
            ofVec2f eDelta = eRadius - radius;
            ofPolyline nLine;
            for(int j = 0; j < mPoints.size(); j++) {
                ofPoint mPoint = mPoints[j];
                ofPoint nPoint = mPoint + eDelta;
                nLine.addVertex(nPoint);
            }
            float alpha = ofMap(eDelta.length(), 0, 400, 255, 0);
            ofSetColor(255, 255, 255, alpha);
            nLine.draw();
        }
    }
}


//--------------------------------------------------------------
void ofApp::drawTestB(){
    
    int numDirections = 5;
    if (bSuns.size() != a.mirrorLines.size()) {
        for (int i = 0; i < a.mirrorLines.size(); i++) {
            ofPoint mirrorCenter = a.mirrorCenters[i];
            bSun b;
            b.init(mirrorCenter, numDirections);
            bSuns.push_back(b);
        }
    }
    
    float t5 = time - tStart;
    
    ofBackground(255, 255, 255);
    ofBackground(0,0,0);
    ofSetLineWidth(1);
    
    /******************* drawing lines with open frameworks */
    //    ofSetColor(0, 0, 0);
    ofSetColor(255, 255, 255);
    ofPolyline dLine;
    for (int i = 0; i < a.mirrorLines.size(); i++) {
        dLine = a.mirrorLines[i];
        dLine.draw();
    }
    
    int numLines = 80;
    bSun b;
    for(int j = 0; j < numDirections; j++) {
        for(int k = 0; k < numLines; k++) {
            float spacing = ofMap(sin(time/3.0), -1, 1, 0, 0.35, 0);
            float scale = 1 + k * spacing;
            for(int i = 0; i < a.mirrorLines.size(); i++) {
                b = bSuns[i];
                ofVec2f dir = b.dirs[j];
                ofPolyline cMirror = a.mirrorLines[i];
                vector<ofPoint> mPoints = cMirror.getVertices();
//                ofPoint mirrorCenter = a.mirrorCenters[i];
                //            ofPoint startPoint = mPoints[0];
                ofVec2f radius = dir - a.centerPoint;
                ofVec2f eRadius = radius * scale;
                ofVec2f eDelta = eRadius - radius;
                ofPolyline nLine;
                for(int j = 0; j < mPoints.size(); j++) {
                    ofPoint mPoint = mPoints[j];
                    ofPoint nPoint = mPoint + eDelta;
                    nLine.addVertex(nPoint);
                }
//                float alpha = ofMap(eDelta.length(), 0, 130, 255, 0);
                float alpha = ofMap(eDelta.length(), 0, 400, 255, 0);
                ofSetColor(255, 255, 255, alpha);
                nLine.draw();
            }
        }
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'k') {
         cout << "xFactor: " << xFactor << endl;
         cout << "yFactor: " << yFactor << endl;
    }
    else if (key == 'j') {
        cout << "/" << endl;
        ofPoint firstPoint = currentLine.getVertices()[0];
        currentLine.addVertex(firstPoint);
        a.mirrorLines.push_back(currentLine);
        ofPolyline newline;
        currentLine = newline;
    }
    else if (key == 'v') {
        switchRLine();
    }
    else if (key == '5' || key == '8' || key == 'n' || key == 'b') {
        tStart = time;
        currentAnimation = key;
        animationChanged = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    cursor = ofPoint(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    cout << ofGetMouseX() << "," << ofGetMouseY() << endl;
    currentLine.addVertex(ofPoint(x, y));
    ofSetColor(255);
    a.mirrorPoints.push_back(ofPoint(x, y));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
