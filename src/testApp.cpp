#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(255,255,255);
	
	start = 0;
	end = 1;
	
	rotation = 0;
	
	moveInc = 0.05;

	movie.loadMovie("movies/MVI_1150.AVI");
	width = movie.getWidth();
	height = movie.getHeight();
	frames = movie.nFrames;
	
	//unsigned char wholeMovie[frames * width * height * 3];
	
	loaded = false;
	
	img.allocate(width, height, OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void testApp::update(){
    movie.idleMovie();
}

//--------------------------------------------------------------
void testApp::draw(){
	
	if (!loaded) {
		for (int frame = 0; frame < frames; frame++) {
			movie.setFrame(frame);
			unsigned char * pixels = movie.getPixels();
			for (int y = 0; y < height; y++) {
				for (int x = 0; x < width; x++) {
					for (int color = 0; color < 3; color++) {
						wholeMovie[(frame * width * height + y * width + x) * 3 + color] = pixels[(y * width + x) * 3 + color];
					}
				}
			}
		}		
	}
	
	loaded = true;

	ofSetColor(0xFFFFFF);
	
	unsigned char dest[width * height * 3];
	
//	for (int x = 0; x < width; x++) {
//		int frame = ofMap((float) x/(float) width, 0, 1, start, end, true) * (float) movie.nFrames;
//		movie.setFrame(frame);
//		unsigned char * pixels = movie.getPixels();
//		for (int y = 0; y < height; y++) {
//			int r = pixels[(y * width + x) * 3 ];
//			int g = pixels[(y * width + x) * 3 + 1];
//			int b = pixels[(y * width + x) * 3 + 2];
//			dest[(y * width + x) * 3] = r;
//			dest[(y * width + x) * 3 + 1] = g;
//			dest[(y * width + x) * 3 + 2] = b;
//		}
//	}
	
//	for (int x = 0; x < width; x++) {
//		int frame = ofMap((float) x/(float) width, 0, 1, start, end, true) * (float) movie.nFrames;
//		for (int y = 0; y < height; y++) {
//			int r = wholeMovie[(frame * width * height + y * width + x) * 3];
//			int g = wholeMovie[(frame * width * height + y * width + x) * 3 + 1];
//			int b = wholeMovie[(frame * width * height + y * width + x) * 3 + 2];
//			dest[(y * width + x) * 3] = r;
//			dest[(y * width + x) * 3 + 1] = g;
//			dest[(y * width + x) * 3 + 2] = b;
//		}
//	}
	
	for (int x = 0; x < width; x++) {
		int frame = ofMap(x, 0, width, 0, frames - 1, true);
		int srcx = ofMap(rotation, 0.0, 1.0, 0, width, true);
		for (int y = 0; y < height; y++) {
			int r = wholeMovie[(frame * width * height + y * width + srcx) * 3];
			int g = wholeMovie[(frame * width * height + y * width + srcx) * 3 + 1];
			int b = wholeMovie[(frame * width * height + y * width + srcx) * 3 + 2];
			dest[(y * width + x) * 3] = r;
			dest[(y * width + x) * 3 + 1] = g;
			dest[(y * width + x) * 3 + 2] = b;
		}
		
	}
	
	img.setFromPixels(dest, width, height, OF_IMAGE_COLOR, true);
	
	ofSetColor(0xFFFFFF);
	img.draw(20, 20);


}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    switch(key){
		case OF_KEY_UP:
			start += moveInc;
			end -= moveInc;
		break;
		case OF_KEY_DOWN:
			start -= moveInc;
			end += moveInc;
		break;
        case OF_KEY_LEFT:
            start -= moveInc;
			end -= moveInc;
			
        break;
        case OF_KEY_RIGHT:
            start += moveInc;
			end += moveInc;
			
        break;
		case 'z':
			rotation -= moveInc;
		break;
		case 'x':
			rotation += moveInc;
		break;
    }
	start = ofClamp(start, 0, 1);
	end = ofClamp(end, 0, 1);
	rotation = ofClamp(rotation, 0, 1);
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
