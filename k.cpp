#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <time.h>

class The_data {
	int id;
	int plz;
	char birthday;
	char nationality;
	char disease;
	
	std::map<int, std::string> natmap = {
		{0, "Angesteller der BRD GmbH"},
		{1, "USA"}, 		// make america great again!
		{2, "Mexicho"},		// and they gonna pay for it
		{3, "China"},
		{4, "Iceland"},
		{5, "Finland"},
		{6, "Sealand"}
	};
	std::map<int, std::string> dismap = {
		{0, "T-Virus"},
		{1, "Syphilis"},
		{2, "Aids"},
		{3, "Herpes"},
		{4, "Weltraumaids"},
		{5, "Kloeten am Arsch"},
		{6, "Verwandt mit Trump"}
	};
	int gen_plz();
	std::string gen_birthday();
	std::string gen_nationality();
	std::string gen_disease();

	public:
		The_data() {
			std::cout << "Test lol wtf yolo kay" << std::endl;
		}

};

int The_data::gen_plz() {
	return (rand() % 99999);
}

std::string The_data::gen_birthday() {
	const time_t foo = rand();
	struct tm *dt;
	char buffer [30];
	dt = localtime(&foo);
	strftime(buffer, sizeof(buffer), "%Y-%m-%d", dt);
	return std::string(buffer);
}

std::string The_data::gen_nationality() {
	int nat = rand() % 6;
	return natmap[nat];
}

std::string The_data::gen_disease() {
	int disease = rand() % 6;
	return dismap[disease];
}


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
		mkay.push_back(data);
	}

	return 0;
}

// endmain
