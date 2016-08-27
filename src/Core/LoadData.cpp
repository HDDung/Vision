/*
 * LoadData.cpp
 *
 *  Created on: Aug 22, 2016
 *      Author: dung
 */

#include "LoadData.h"


LoadData::LoadData(char link[]){
	GiveLink(link);
}


void LoadData::GiveLink(char _link[]){
	ifstream fp;
	ifstream ft;
	fp.open(_link, ios::in);
	if (!fp.is_open()){
			std::cout << "Error open file" << endl;
	} else {
		cv::Mat List;
		cv::Mat img;
		string line, link = "Database/Face_Recog/";
		String name, file;
		int count = 0;
		while (getline( fp, line ).good()){

			std::istringstream iss(line);
			std::string token;
			if (std::getline(iss, token, ' ')){
				file = token;
			}
			if (std::getline(iss, token, ' ')){
				name = token;
			} else {
				name = "Ahihihi hok bik ai het";
			}

			count++;
			list.AddFace(Face(name, imread(link + file, IMREAD_GRAYSCALE)));
			std::cout << line << " " << count<< std::endl;
		}
	}
}

ListFace LoadData::GetData(){
	return this->list;
}
