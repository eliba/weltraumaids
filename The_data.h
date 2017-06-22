#include <iostream>
#include <map>
#include <string>

class The_data {
	int id;
	int plz;
	std::string birthday;
	std::string nationality;
	std::string disease;
	
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
		The_data();
		void print();
};
