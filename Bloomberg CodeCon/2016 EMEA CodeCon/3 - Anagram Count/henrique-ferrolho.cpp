#include <algorithm>
#include <iostream>
#include <map>
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
map<string, ui> anagrams;

int main() {
	unsigned int N;
	cin >> N;

	for (ui i = 0; i < N; i++) {
		string word;
		cin >> word;

		std::transform(word.begin(), word.end(), word.begin(), ::tolower);
		std::sort(word.begin(), word.end());

		auto it = anagrams.find(word);
		if (it == anagrams.end())
			anagrams.insert(make_pair(word, 1));
		else
			it->second++;
	}


	ui sum = 0;
	for (auto x : anagrams) {
		if (x.second > 1)
			sum += x.second;
	}

	cout << sum << endl;

	return 0;
}
