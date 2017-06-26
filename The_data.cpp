/*
* ----------------------------------------------------------------------------
* "THE BEER-WARE LICENSE" (Revision 42):
* <backmund@hs-furtwangen.de> and <schwaerf@hs-furtwangen.de> wrote this file. 
* As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think
* this stuff is worth it, you can buy me a beer in return
* ----------------------------------------------------------------------------
*/


#include "The_data.h"

int global_id = 0;

int get_random_number() {
	return 4; // chosen by fair dice roll.
}				// guaranteed to be random.

The_data::The_data() {
	id = global_id++;
	plz = gen_plz();
	birthday = gen_birthday();
	nationality = gen_nationality();
	disease = gen_disease();
	std::cout << "----- Test lol wtf yolo kay" << std::endl;
}


int The_data::gen_plz() {
	return (rand() % 99999);
}

int The_data::gen_birthday() {
	int foo = rand();
	return foo;
}

std::string The_data::gen_nationality() {
	int nat = (rand() + get_random_number()) % 6;
	return natmap[nat];
}

std::string The_data::gen_disease() {
	int disease = (rand() + get_random_number()) % 6;
	return dismap[disease];
}

int The_data::get_id () {
	return id;
}

int The_data::get_plz() {
	return plz;
}

std::string The_data::get_bday() {
	// https://stackoverflow.com/questions/14436462/c-time-stamp-to-human-readable-datetime-function
	const time_t foo = birthday;
	struct tm *dt;
	char buffer [30];
	dt = localtime(&foo);
	strftime(buffer, sizeof(buffer), "%Y-%m-%d", dt);
	return std::string(buffer);
}
		
std::string The_data::get_nation() {
	return nationality;
}

std::string The_data::get_disease() {
	return disease;
}

void The_data::print() {
	std::cout << "id: " << id << std::endl;
	std::cout << "plz: " << plz << std::endl;
	std::cout << "birthday: " << get_bday() << std::endl;
	std::cout << "nat: " << nationality << std::endl;
	std::cout << "disease: " << disease << std::endl;
	anonymize();
}

void The_data::anonymize() {
	// anonymize plz
	anon_plz = plz/1000;
	// anonymize birthday
	// ain't no duplicate
	const time_t foo = birthday;
	struct tm *dt;
	char buffer [30];
	dt = localtime(&foo);
	strftime(buffer, sizeof(buffer), "%Y", dt);
	std::string::size_type sz;
	anon_bday = std::stoi(buffer, &sz);
	// anonymize nationality
	anon_nat = nationality[0];
}

int The_data::get_anon_plz() {
	return anon_plz;
}

int The_data::get_anon_bday() {
	return anon_bday;
}

char The_data::get_anon_nat() {
	return anon_nat;
}
