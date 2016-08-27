/*
 * LoadData.h
 *
 *  Created on: Aug 22, 2016
 *      Author: dung
 */

#ifndef CORE_LOADDATA_H_
#define CORE_LOADDATA_H_


#include "../Data/ListFace.h"
#include "../Data/Face.h"

#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/core.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace cv;
class LoadData {
public:
	LoadData(char link[]);
	void GiveLink(char _link[]);
	ListFace GetData();
private:
	ListFace list;
};

#endif /* CORE_LOADDATA_H_ */
