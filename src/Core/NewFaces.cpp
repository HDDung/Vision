/*
 * NewFaces.cpp
 *
 *  Created on: Aug 27, 2016
 *      Author: dung
 */

#include "NewFaces.h"

NewFaces::NewFaces() {
	// TODO Auto-generated constructor stub

}
void NewFaces::AddFace(cv::Mat face, double diff){
	// Add face
	newface t;
	t.diff = diff;
	t.face = face;
	if (list.size() <= 50){
		if (CheckFace(t)){
				list.push_back(t);
			}

	}

	count++;


}
bool NewFaces::CheckFace(newface t){
	// Check whether new face should or shouldn't add to the array
	// true: can add; false: cannot add;
	for (int i = 0; i < list.size(); i++){
		if (std::fabs(list[i].diff - t.diff) < Threshold){
			return false;
		}
	}
	return true;
}
void NewFaces::UpdateData(DataHandler& handler){
	// update new face to database

	std::cout << this->count << " " << list.size() << std::endl;
	if (list.size() != 0){
	string name;
	namedWindow( "NewFace", WINDOW_AUTOSIZE );
	/*
	waitKey(1000);
	usleep(10000);*/
	cv::imshow( "NewFace", list[0].face );
	waitKey(0);
	int i;
	for (i = 1; i < list.size(); i++){
		cout << "What's the name? ";
		cin >> name;
		if (name != "0"){
			handler.StoreData(list[i-1].face, name);
		}
		cv::imshow( "NewFace", list[i].face );
		waitKey(0);
	}

		cout << "What's the name? ";
		cin >> name;
		if (name != "0"){
			handler.StoreData(list[i].face, name);
		}
	}


}


NewFaces::~NewFaces() {
	// TODO Auto-generated destructor stub
}

