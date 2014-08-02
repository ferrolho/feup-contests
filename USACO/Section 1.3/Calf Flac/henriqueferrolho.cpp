/*
 ID: henriqu13
 PROG: calfflac
 LANG: C++
 */
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <cmath>
#include <string>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<unsigned int> vui;
#define FOR(i, a, b) for(unsigned int i = a; i < b; i++)
#define ALL(v) (v).begin(), (v).end()
#define foreach(v, it) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

// TODO CHANGE THIS ACCORDINGLY!
const string PROB_NAME = "calfflac";

struct PalInfo {
	int startID;
	int size;
};

bool invalidChar(char ch) {
	ch = tolower(ch);

	return ch < 'a' || 'z' < ch;
}

string filterInvalidChars(const string& w, vector<ui>& ids) {
	ids.clear();

	string res = "";
	int counter = 0;
	for (ui i = 0; i < w.size(); i++) {
		if (!invalidChar(w[i])) {
			res += tolower(w[i]);
			ids.push_back(counter);
		}

		counter++;
	}

	return res;
}

string preprocessManacherAlgorithm(const string& s) {
	int n = s.length();

	if (n == 0)
		return "^$";

	string t = "^";
	for (int i = 0; i < n; i++)
		t += "#", t += s[i];
	t += "#$";

	return t;
}

PalInfo manacherAlgorithm(const string& s) {
	string t = preprocessManacherAlgorithm(s);

	int n = t.size();
	int* P = new int[n];
	int C = 0, R = 0;

	int maxPalCenterID = 1;
	for (int i = 1; i < n - 1; i++) {
		// i' = C - (i-C)
		int ii = 2 * C - i;

		P[i] = (R > i) ? min(R - i, P[ii]) : 0;

		// attempt to expand palindrome centered at i
		while (t[i + 1 + P[i]] == t[i - 1 - P[i]])
			P[i]++;

		// if palindrome centered at i expand past R,
		// adjust center based on expanded palindrome.
		if (i + P[i] > R) {
			C = i;
			R = i + P[i];
		}

		if (P[i] > P[maxPalCenterID])
			maxPalCenterID = i;
	}

	int maxPalSize = P[maxPalCenterID];
	delete[] P;

	PalInfo palInfo;
	palInfo.startID = (maxPalCenterID - 1 - maxPalSize) / 2;
	palInfo.size = maxPalSize;

	return palInfo;
}

int main() {
	string str;
	str = PROB_NAME + ".in";
	FILE *fin = fopen(str.c_str(), "r");
	str = PROB_NAME + ".out";
	FILE *fout = fopen(str.c_str(), "w");
	assert(fin != NULL && fout != NULL);

	// -- input -- //
	string text = "";
	char temp[90];
	while (fgets(temp, 90, fin) != 0)
		text += temp;

	// -- processing -- //
	vector<ui> originalIds;

	string filteredText = filterInvalidChars(text, originalIds);

	PalInfo palInfo = manacherAlgorithm(filteredText);

	string pal = "";
	for (int i = 0, j = originalIds[palInfo.startID]; i < palInfo.size; j++) {
		char ch = text[j];

		if (!invalidChar(ch))
			i++;

		pal += ch;
	}

	// -- output -- //
	fprintf(fout, "%u\n%s\n", palInfo.size, pal.c_str());

	return 0;
}
