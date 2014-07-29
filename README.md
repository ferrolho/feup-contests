FEUP-contests
=============

###Contest templates:
####C++
```c++
/*
 ID: USER_NAME
 PROG: PROB_NAME
 LANG: C++
 */
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <string>
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
const string PROB_NAME = "CHANGE THIS";

int main() {
	string str;
	str = PROB_NAME + ".in";
	FILE *fin = fopen(str.c_str(), "r");
	str = PROB_NAME + ".out";
	FILE *fout = fopen(str.c_str(), "w");
	assert(fin != NULL && fout != NULL);
	
	// -- input -- //
	ui x, y;
	fscanf(fin, "%d %d", &x, &y);

	// -- processing -- //
	x *= x;

	// -- output -- //
	fprintf(fout, "%u\n", x + y);
	
	return 0;
}
```
