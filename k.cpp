#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <time.h>

// main

int main (int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Insert one argument!" << std::endl;
		exit(1);	
	}
	
	int num;
	sscanf (argv[1],"%d",&num);
	
	if (num > 10000000) {
		std::cout << "Are you shure? This is going to take a looong time. y/n" << std::endl;
		exit(1);
	}
	
	std::vector<The_data> mkay;
	
	while(num--) {
		The_data data;
		data.print();
		mkay.push_back(data);
	}

	std::ofstream the_file;
	the_file.open("export.csv");
	the_file << "Test\n";
	the_file.close();

	


	return 0;
}

// endmain
