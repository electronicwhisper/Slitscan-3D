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
		int width;
		int height;
		int frames;
	
		unsigned char wholeMovie[210124800];
	
		ofImage img;
		float start;
		float end;
		float moveInc;
	
		float rotation;
	
		bool loaded;
	
};

#endif
