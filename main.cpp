#include <iostream>
#include <fstream>
#include "parser.h"

using namespace std;

int main(int argc, char* argv[]){
	char * file_name;
	cout << "argc = " << argc << endl;
	for(int i = 0; i < argc; i++)
		cout << "argv[" << i << "] = " << argv[i] << endl;

	if(argc>0)
		file_name= argv[1];

	file_open(file_name);
	return 0;
}
