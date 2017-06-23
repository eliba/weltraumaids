#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <time.h>
#include "The_data.h"

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
	
	std::ofstream the_file;	
	the_file.open("export.csv");
	
	the_file << "ID,PLZ,BDAY,NATION,DISEASE\n";
	while(num--) {
		The_data data;
		data.print();
		//mkay.push_back(data);
		the_file << data.get_id() << ",";
		the_file << data.get_plz() << ",";
		the_file << data.get_bday() << ",";
		the_file << data.get_nation() << ",";
		the_file << data.get_disease();
		the_file << "\n";
	}

	the_file.close();

	return 0;
}

// endmain
