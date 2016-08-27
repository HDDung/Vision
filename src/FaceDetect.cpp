//============================================================================
// Name        : FaceDetect.cpp
// Author      : KenKoko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/core.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include "Core/FaceRecognition.h"
#include "Core/FaceDetector.h"
#include "Core/LoadData.h"

using namespace std;
using namespace cv;
int main() {
	cout << "FaceDetectA" << endl; // prints FaceDetect

		VideoCapture capture;
	    Mat frame;
	    FaceDetector dtor1 = FaceDetector(LoadData("Database/face").GetData());
	    dtor1.Training();
	    //-- 2. Read the video stream
	    capture.open( -1 );
	    if ( ! capture.isOpened() ) { printf("--(!)Error opening video capture\n"); return -1; }

	    while ( capture.read(frame) )
	    {
	        if( frame.empty() )
	        {
	            printf(" --(!) No captured frame -- Break!");
	            break;
	        }

	        //-- 3. Apply the classifier to the frame
	        FaceRecognition recog(frame);
	        try {
		        recog.detectAndDisplay(dtor1);
	        }
	        catch (const char* msg){
	        	cerr << msg << endl;
	        }

	        //-- bail out if escape was pressed
	        int c = waitKey(10);
	        if( (char)c == 27 ) { break; }
	    }
/*
	    frame = imread("Test/test1.jpg");
	    FaceRecognition recog(frame);
		try {
			recog.detectAndDisplay(dtor1);
		}
		catch (const char* msg){
			cerr << msg << endl;
		}

		imshow( "Ahihi", frame );
		waitKey(0);*/
	return 0;
}
