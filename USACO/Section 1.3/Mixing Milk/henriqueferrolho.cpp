/*
 ID: henriqu13
 PROG: milk
 LANG: C++
 */
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>

using namespace std;

typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<unsigned int> vui;
#define FOR(i, a, b) for(unsigned int i = a; i < b; i++)
#define ALL(v) (v).begin(), (v).end()
#define foreach(v, it) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

// TODO CHANGE THIS ACCORDINGLY!
const string PROB_NAME = "milk";

int main() {
	string str;
	str = PROB_NAME + ".in";
	FILE *fin = fopen(str.c_str(), "r");
	str = PROB_NAME + ".out";
	FILE *fout = fopen(str.c_str(), "w");

	// input
	multimap<ui, ui> farmersData;

	ui n, m;
	fscanf(fin, "%d %d", &n, &m);

	FOR(i, 0, m)
	{
		ui p, a;
		fscanf(fin, "%u %u", &p, &a);

		farmersData.insert(pair<ui, ui>(p, a));
	}

	// processing
	ui cost = 0;
	foreach (farmersData, it)
	{
		ui qnt;
		if (it->second <= n)
			qnt = it->second;
		else
			qnt = n;

		cost += qnt * it->first;
		n -= qnt;

		if (n <= 0)
			break;
	}

	// output
	fprintf(fout, "%u\n", cost);

	return 0;
}
