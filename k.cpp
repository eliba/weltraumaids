#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <time.h>
#include "The_data.h"

int id_counter = 0;

static int get_new_id() {
	return id_counter++;
}

int The_data::gen_plz() {
	return (rand() % 99999);
}

std::string The_data::gen_birthday() {
	// https://stackoverflow.com/questions/14436462/c-time-stamp-to-human-readable-datetime-function
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

void The_data::print() {
	std::cout << "id: " << id << std::endl;
	std::cout << "plz: " << plz << std::endl;
	std::cout << "birthday: " << birthday << std::endl;
	std::cout << "nat: " << nationality << std::endl;
	std::cout << "disease: " << disease << std::endl;
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
		data.print();
		mkay.push_back(data);
	}

	return 0;
}

// endmain
