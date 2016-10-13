/*
 ID: henriqu13
 PROG: crypt1
 LANG: C++
 */
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<unsigned int> vui;
#define FOR(i, a, b) for(unsigned int i = a; i < b; i++)
#define ALL(v) (v).begin(), (v).end()
#define foreach(v, it) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

// TODO CHANGE THIS ACCORDINGLY!
const string PROB_NAME = "crypt1";

ui vecToNum(const ui v[]) {
	ui res = 0;

	FOR (i, 0, 3)
		res *= 10, res += v[i];

	return res;
}

vui numToVec(ui num) {
	vui res;

	while (num > 0) {
		res.insert(res.begin(), num % 10);
		num /= 10;
	}

	return res;
}

bool exists(ui value, vui vec) {
	FOR (i, 0, vec.size())
		if (value == vec[i])
			return true;

	return false;
}

bool valid(ui num, vui numSet) {
	vui vec = numToVec(num);

	FOR(i, 0, vec.size())
		if (!exists(vec[i], numSet))
			return false;

	return true;
}

bool validCrypt(const ui num1[], const ui num2[], const vui& numSet) {
	vui partProds;

	FOR(i, 0, 2)
	{
		ui partProd = vecToNum(num1) * num2[1 - i];
		if (partProd >= 1000)
			return false;

		if (!valid(partProd, numSet))
			return false;

		partProds.push_back(partProd);
	}

	ui result = 0;
	FOR(i, 0, partProds.size())
		result += pow(10, i) * partProds[i];
	if (result >= 10000)
		return false;

	if (!valid(result, numSet))
		return false;

	return true;
}

int main() {
	string str;
	str = PROB_NAME + ".in";
	ifstream fin;
	fin.open(str.c_str());
	str = PROB_NAME + ".out";
	ofstream fout;
	fout.open(str.c_str());
	assert(fin != NULL && fout != NULL);

	// -- input -- //
	ui N;
	fin >> N;

	vui numSet;
	FOR (i, 0, N)
	{
		ui temp;
		fin >> temp;

		numSet.push_back(temp);
	}

	// -- processing -- //
	ui solutions = 0;
	ui num1[3];
	ui num2[2];

	FOR (i, 0, N)
		FOR (j, 0, N)
			FOR (k, 0, N)
				FOR (l, 0, N)
					FOR (m, 0, N)
					{
						num1[0] = numSet[i];
						num1[1] = numSet[j];
						num1[2] = numSet[k];

						num2[0] = numSet[l];
						num2[1] = numSet[m];

						// if result is valid
						if (validCrypt(num1, num2, numSet))
							solutions++;
					}

	// -- output -- //
	fout << solutions << endl;

	return 0;
}
