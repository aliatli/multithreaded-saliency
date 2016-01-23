/* saliency.cpp - Saliency heuristics
 * (c) 2014-2015 The Grid
 *
 */

#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include "Saliency/GMRsaliency.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <chrono>

using namespace std;


int main(int argc, char *argv[]) {
	
    if(argc < 2){
        cout << "See readme for usage.\n";
        return 0;
    }
    
    char original_image_path[256];
	strcpy(original_image_path, argv[1]);
    
    Mat original;
    original = imread(original_image_path, CV_LOAD_IMAGE_COLOR);

 
    chrono::time_point< chrono::system_clock > startTime = chrono::system_clock::now();
  
    GMRsaliency GMRsal;
    Mat saliency_map;
    Mat original_image;
    resize(original, original_image, Size(original.rows/5, original.cols/10));
    saliency_map = GMRsal.GetSal(original_image);
	
    chrono::time_point< chrono::system_clock > endTime = chrono::system_clock::now();
    chrono::duration<double> elapsedTime = endTime - startTime;
    
    cout << elapsedTime.count() << " seconds in total" << endl;
	
    namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window", saliency_map );                   // Show our image inside it.

    waitKey(0);          
	
    return 0;
}
