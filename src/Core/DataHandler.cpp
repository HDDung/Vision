/*
 * LoadData.cpp
 *
 *  Created on: Aug 22, 2016
 *      Author: dung
 */

#include "DataHandler.h"


DataHandler::DataHandler(char _link[1000]){
	std::cout << "Get link" << std::endl;
	GiveLink(_link);
}

void DataHandler::GiveLink(char _link[1000]){
	strcpy(this->link, _link);
	std::cout << this->link << "this link have been gotten"<< std::endl;
}

ListFace DataHandler::LoadData(){

	ListFace list;
	ifstream fp;
	fp.open(link, ios::in);
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
				name = "Ahihihi hok bik";
			}

			count++;
			list.AddFace(Face(name, imread(link + file, IMREAD_GRAYSCALE)));
			std::cout << line << " " << count<< std::endl;
			this->count++;
		}
	}
	fp.close();
	return list;
}

void DataHandler::StoreData(cv::Mat face, String name){
	ofstream fp;
	fp.open(link, ios::out | ios::app | ios::ate);
	if (!fp.is_open()){
				std::cout << "Error open file" << endl;
	} else {
		this->count++;
		String link, file;
		link = "Database/Face_Recog/";
		ostringstream convert; convert << this->count;
		file = "face" + convert.str() + ".bmp";
		imwrite(link+file, face);
		fp << file + " " + name << std::endl;
	}

	fp.close();
}

