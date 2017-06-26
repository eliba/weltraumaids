/*
* ----------------------------------------------------------------------------
* "THE BEER-WARE LICENSE" (Revision 42):
* <backmund@hs-furtwangen.de> and <schwaerf@hs-furtwangen.de> wrote this file. 
* As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think
* this stuff is worth it, you can buy me a beer in return
* ----------------------------------------------------------------------------
*/


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
	
	long num;
	sscanf (argv[1],"%ld",&num);

		if (num > 10000000) {
		std::cout << "This is going to take a looong time." << std::endl;
	}
	
	//std::vector<The_data> mkay;

	/* initialize random seed: */
	srand (time(NULL));

	
	std::ofstream the_file;	
	the_file.open("export.csv");
	// generates the head	
	the_file << "ID,PLZ,BDAY,NATION,DISEASE\n";
	
	std::ofstream the_anon_file;	
	the_anon_file.open("export_anon.csv");
	// generates the head	
	the_anon_file << "ID,PLZ,BDAY,NATION,DISEASE\n";
	
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
		data.anonymize();
		the_anon_file << data.get_id() << ",";
		the_anon_file << data.get_anon_plz() << ",";
		the_anon_file << data.get_anon_bday() << ",";
		the_anon_file << data.get_anon_nat() << ",";
		the_anon_file << data.get_disease();
		the_anon_file << "\n";
	}

	the_file.close();
	the_anon_file.close();

	return 0;
}

// endmain
