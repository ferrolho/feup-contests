/*
 ID: pereira1
 PROG: gift1
 LANG: C++11
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>

using namespace std;

pair<string, int>* find(vector<pair<string, int>*> persons, string name) {
	for (unsigned int i = 0; i < persons.size(); i++)
		if (persons[i]->first == name)
			return persons[i];

	return new pair<string, int>("null", 0);
}

string toString(vector<pair<string, int>*> persons) {
	stringstream ss;

	for (unsigned int i = 0; i < persons.size(); i++)
		ss << persons[i]->first << " " << persons[i]->second << endl;

	return ss.str();
}

int main() {

	ifstream in("gift1.in");
	ofstream out("gift1.out");

	int np = 0;
	string line;
	vector<pair<string, int>*> persons;

	if (in.is_open()) {
		getline(in, line);
		np = atoi(line.c_str());

		for (int i = 0; i < np; i++) {
			getline(in, line);
			persons.push_back(new pair<string, int>(line, 0));
		}

		while (!in.eof()) {
			int amount = 0, num_persons = 0;

			// gets the name of the person who will give gifts to the others
			getline(in, line);

			// gets the amount of cash and the number of persons to divide it
			in >> amount;
			in >> num_persons;

			if (num_persons != 0)
				find(persons, line)->second -= amount - (amount % num_persons);

			// get character \n to parsing next data
			in.get();

			for (int i = 0; i < num_persons; i++) {
				getline(in, line);

				if (num_persons != 0)
					find(persons, line)->second += (int) (amount / num_persons);
			}
		}
	}

	in.close();

	if (out.is_open())
		out << toString(persons);

	out.close();

	return 0;
}
