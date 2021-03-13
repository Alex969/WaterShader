#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableDepthTest(); // enable depth test (z value rather than draw order)
    cam.setGlobalPosition({ 100, -150, 20 });
    cam.tiltDeg(90);
    cam.panDeg(30);


    ofDisableArbTex();
    texture.loadImage("water2.jpg");
    texture.getTextureReference().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    texture.getTextureReference().setTextureWrap(GL_REPEAT, GL_REPEAT);
        
    numCols = numRows = 50;
    i = 0;
    int size = 10;
    int scale = 10;
    
    for (int x = -numCols / 2; x < numCols / 2; x++) {
        for (int y = -numRows / 2; y < numRows / 2; y++) {
            //cout << x * size << ", " << y * size << "\n";
            mesh.addVertex(ofPoint(x*size, y*size, 0)); // make a new vertex
        }
    }
    
    // Set up triangles' indices
    // only loop to -1 so they don't connect back to the beginning of the row
    for (int x = 0; x < numCols - 1; x++) {
        for (int y = 0; y < numRows - 1; y++) {
            int topLeft = x + numCols * y;
            int bottomLeft = x + 1 + numCols * y;
            int topRight = x + numCols * (y + 1);
            int bottomRight = x + 1 + numCols * (y + 1);
            
            mesh.addTriangle(topLeft, bottomLeft, topRight);
            mesh.addTriangle(bottomLeft, topRight, bottomRight);

        }
    }



    for (int x = 0; x < numCols; x++) {
        for (int y = 0; y < numRows; y++) {
             //mesh.addTexCoord(ofVec2f(1, 1));
             mesh.addTexCoord(ofVec2f(x, y));
//             mesh.addColor(ofColor(255, 255, 255));
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < mesh.getNumVertices(); i++){
        ofVec3f vec;
        vec = mesh.getVertex(i);
        vec.z = getZNoiseValue(vec.x, vec.y);
        mesh.setVertex(i, vec);
    }
    i+=.1;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    cam.begin();
    ofPushMatrix();
    ofSetColor(255,192,203);
    //    ofDrawBox(0, 0, 0, 10); // draw 3d box
//    ofDrawBox( 0, 10, getZNoiseValue(0, 10) + 20, 10);

    ofScale(5);
    ofTranslate(4.0f, 8.0f, -2.1f);
    ofRotateDeg(56);
    bunny.draw();
    ofPopMatrix();
    ofSetColor(0, 119, 190);
    //mesh.drawVertices();
//    texture.bind();
    texture.getTexture().bind();
    mesh.drawWireframe();
    mesh.draw();
    texture.getTexture().unbind();
    
    cam.end();
}

//--------------------------------------------------------------
float ofApp::getZNoiseValue(float x, float y){
    
    float time = ofGetFrameNum()*0.003;
    
    float n1freq = 0.02;
    float n1amp = 15;
    float n2freq = 0.0005;
    float n2amp = 6;
    
    float noise1 = ofNoise(x * n1freq, y * n1freq, time) * n1amp;
    float noise2 = ofNoise(x * n2freq, y * n2freq, time) * n2amp;
    float ret = noise1+ noise2;
    return ret;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'w':
            cam.dolly(-1);
            break;
        case 's':
            cam.dolly(1);
            break;
        case 'a':
            cam.panDeg(1);
            break;
        case 'd':
            cam.panDeg(-1);
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
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

