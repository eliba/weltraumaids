#include "The_data.h"

int global_id = 0;

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

std::string The_data::gen_birthday() {
	// https://stackoverflow.com/questions/14436462/c-time-stamp-to-human-readable-datetime-function
	const time_t foo = rand();
	struct tm *dt;
	char buffer [30];
	dt = localtime(&foo);
	strftime(buffer, sizeof(buffer), "%Y-%m-%d", dt);
	return std::string(buffer);
}

int get_random_number() {
	return 4; // chosen by fair dice roll.
}				// guaranteed to be random.

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
	return birthday;
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
	std::cout << "birthday: " << birthday << std::endl;
	std::cout << "nat: " << nationality << std::endl;
	std::cout << "disease: " << disease << std::endl;
}

void The_data::anonymize() {
	// anonymize plz
	
	// anonymize birthday
	
}
