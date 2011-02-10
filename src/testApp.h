#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"

class testApp : public ofBaseApp{

	public:

	void setup();
	void update();
	void draw();

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void resized(int w, int h);

	ofVideoPlayer 		movie;
	float width;
	float height;
	float frames;
	
	// these should be modified when I figure out how to code them "correctly"
	unsigned char wholeMovie[210124800];
	
	
	// UI State
	// these range from -1 to 1
	float x1;
	float t1;
	float x2;
	float t2;
	
	float increment;
	


	ofImage img;
	

	

	
};

#endif
