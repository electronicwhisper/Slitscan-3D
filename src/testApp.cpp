#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(255,255,255);
	
	x1 = 0;
	t1 = 0.5;
	x2 = 1;
	t2 = 0.5;
	
	
	increment = 0.025;

	movie.loadMovie("movies/MVI_1150.AVI");
	width = movie.getWidth();
	height = movie.getHeight();
	frames = movie.nFrames;
	
	//unsigned char wholeMovie[frames * width * height * 3];
	
	for (int frame = 0; frame < frames; frame++) {
		movie.setFrame(frame);
		unsigned char * pixels = movie.getPixels();
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				for (int color = 0; color < 3; color++) {
					wholeMovie[(frame * (int) width * (int) height + y * (int) width + x) * 3 + color] = pixels[(y * (int) width + x) * 3 + color];
				}
			}
		}
	}
	
	img.allocate(width, height, OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void testApp::update(){
    movie.idleMovie();
}

//--------------------------------------------------------------
void testApp::draw(){
	
	
	ofSetColor(0x000000);
	ofNoFill();
	
	// Draw X-Time Graph
	ofRect(0, 0, 200, 200);	
	ofLine(x1*200, (1-t1)*200, x2*200, (1-t2)*200);
	
	// Draw Instructions
	ofDrawBitmapString("UP: zoom in\nDOWN: zoom out\nLEFT: pan left\nRIGHT: pan right\nZ: rotate left\nX: rotate right", 20, 220);
	
	
	
	// Draw image
	
	unsigned char dest[(int) width * (int) height * 3]; // destination image
	
	for (int destx = 0; destx < width; destx++) {
		int srcx = ofMap(destx, 0, width, x1*(width-1), x2*(width-1), true);
		int srcframe = ofMap(destx, 0, width, t1*(frames-1), t2*(frames-1), true);
		for (int y = 0; y < height; y++) {
			for (int color = 0; color < 3; color++) {
				dest[(y * (int) width + destx) * 3 + color] = wholeMovie[(srcframe * (int) width * (int) height + y * (int) width + srcx) * 3 + color];
			}
		}
	}
	
	img.setFromPixels(dest, width, height, OF_IMAGE_COLOR, true);
	ofSetColor(0xFFFFFF);
	img.draw(220, 20);


}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
	switch (key) {
		case OF_KEY_UP:
			// zoom in
			if (x1 == 0 && x2 == 1) {
				t1 = ofClamp(t1 + increment, 0, 1);
				t2 = ofClamp(t2 - increment, 0, 1);
			} else if (t1 == 0 && t2 == 1) {
				x1 = ofClamp(x1 - increment, 0, 1);
				x2 = ofClamp(x2 + increment, 0, 1);
			}
			break;
		case OF_KEY_DOWN:
			// zoom out
			if (t1 == 0 && t2 == 1) {
				x1 = ofClamp(x1 + increment, 0, 1);
				x2 = ofClamp(x2 - increment, 0, 1);
				if (x1 > x2) {
					float middle = (x1 + x2) / 2;
					x1 = middle;
					x2 = middle;
				}
			} else if (x1 == 0 && x2 == 1) {
				t1 = ofClamp(t1 - increment, 0, 1);
				t2 = ofClamp(t2 + increment, 0, 1);
			}
			break;
		case OF_KEY_LEFT:
			// pan left
			if (x1 == 0 && x2 == 1) {
				t1 = ofClamp(t1 - increment, 0, 1);
				t2 = ofClamp(t2 - increment, 0, 1);
			}
			break;
		case OF_KEY_RIGHT:
			// pan right
			if (x1 == 0 && x2 == 1) {
				t1 = ofClamp(t1 + increment, 0, 1);
				t2 = ofClamp(t2 + increment, 0, 1);
			}
			break;
		case 'z':
			// rotate left
			if (t1 == 0 && t2 == 1) {
				x1 = ofClamp(x1 - increment, 0, 1);
				x2 = ofClamp(x2 - increment, 0, 1);
			}
			break;
		case 'x':
			// rotate right
			if (t1 == 0 && t2 == 1) {
				x1 = ofClamp(x1 + increment, 0, 1);
				x2 = ofClamp(x2 + increment, 0, 1);
			}
			break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}


//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::resized(int w, int h){

}
