#ifndef PARSER_H
#define	PARSER_H

#include <fstream>
#include <sstream>
#include <queue>
#include <iostream>
#include <string>
#include "barrier.h"

using namespace std;

void file_open(string file_name, queue< queue<int> > * m_queue){
	string line;
	const char * fnc = file_name.c_str();
	ifstream myfile(fnc);
	cout << file_name << ":" << endl;
	myfile >> train_n >> station_n;
	getline(myfile, line);
	int c, length;
	while(getline(myfile, line)){
		queue<int> route;
		length = line.length();
		istringstream line_stream(line);
		line_stream >> c;//dumps the integer that indicates route length, not needed for this implementation
		while(line_stream >> c){
			cout << c;
			route.push(c);
		}
		cout << endl;
		m_queue->push(route);
	}
	cout << train_n << station_n << endl;
}

#endif
