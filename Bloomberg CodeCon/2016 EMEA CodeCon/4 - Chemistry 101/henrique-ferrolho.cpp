#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

// Custom types
typedef unsigned int ui;
typedef vector<unsigned int> vui;

// Macros
#define ALL(v) (v).begin(), (v).end()

// Globals
map<string, bool> added;
multimap<string, string> rules;

int main() {
	unsigned int N;
	cin >> N;

	for (ui i = 0; i < N; i++) {
		string chem;
		ui ingNum;

		cin >> chem >> ingNum;

		added.insert(make_pair(chem, 0));

		for (ui j = 0; j < ingNum; j++) {
			string ing;
			cin >> ing;

			added.insert(make_pair(ing, 0));
			rules.insert(make_pair(chem, ing));
		}
	}

	string line;
	getline(cin, line);
	getline(cin, line);

	istringstream iss(line);
	string str;

	while (iss >> str) {
		for (auto rule : rules) {
			if (rule.first == str) {
				if (!added[rule.second]) {
					cout << "BOOM!" << endl;
					return 0;
				}
			}
		}

		added[str] = true;
	}

	cout << "SAFE!" << endl;

	/*
	cout << "N: " << N << endl;
	cout << endl;

	cout << "rules:" << endl;
	for (auto x : rules)
		cout << x.first << " - " << x.second << endl;
	cout << endl;

	cout << "added:" << endl;
	for (auto x : added)
		cout << x.first << " - " << x.second << endl;
	*/

	return 0;
}
