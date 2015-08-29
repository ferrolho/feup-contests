FEUP Contests
=============

###Contest templates:

####C++11

```c++
/*
 ID: USER_NAME
 PROG: PROB_NAME
 LANG: C++11
 */

#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

/*
 * READ ME!
 * Change this to the respective problem name! And don't
 * forget to change the name in the top comment as well.
 */
const string PROB_NAME = "CHANGE THIS";

// Custom types
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<unsigned int> vui;
typedef vector<vector<int>> vvi;
typedef vector<vector<unsigned int>> vvui;

// Macros
#define ALL(v) (v).begin(), (v).end()

// Constants

// Globals
ui n;

vi mergeSort(const vi &data) {
	if (data.size() <= 1)
		return data;

	int middle = data.size() / 2;
	vi left(data.begin(), data.begin() + middle);
	vi right(data.begin() + middle, data.end());

	left = mergeSort(left);
	right = mergeSort(right);

	vi result(data.size());
	merge(ALL(left), ALL(right), result.begin());

	return result;
}

ui solve(ui n) {
	return n;
}

int main() {
	// DO NOT MESS WITH THIS BLOCK
	string str;
	str = PROB_NAME + ".in";
	FILE *fin = fopen(str.c_str(), "r");
	str = PROB_NAME + ".out";
	FILE *fout = fopen(str.c_str(), "w");
	assert(fin != NULL && fout != NULL);

	// input
	fscanf(fin, "%d", &n);

	// output
	fprintf(fout, "%u\n", solve(n));

	return 0;
}
```

####C++

```c++
/*
 ID: USER_NAME
 PROG: PROB_NAME
 LANG: C++
 */
#include <assert.h>
#include <iostream>
#include <fstream>
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
	ifstream fin;
	fin.open(str.c_str());
	str = PROB_NAME + ".out";
	ofstream fout;
	fout.open(str.c_str());
	assert(fin != NULL && fout != NULL);

	// -- input -- //
	ui x, y;
	fin >> x >> y;

	// -- processing -- //
	x *= x;

	// -- output -- //
	fout << x + y << endl;

	return 0;
}
```

####C

```c
/*
 ID: USER_NAME
 PROG: PROB_NAME
 LANG: C
 */
#include <stdio.h>
#include <assert.h>
#include <string.h>

// TODO CHANGE THIS ACCORDINGLY!
const char PROB_NAME[20] = "CHANGE THIS";

int main() {
    char str[25];
    strcpy(str, PROB_NAME), strcat(str, ".in");
    FILE *fin = fopen(str, "r");
    strcpy(str, PROB_NAME), strcat(str, ".out");
    FILE *fout = fopen(str, "w");
    assert(fin != NULL && fout != NULL);

    // -- input -- //
    int x, y;
    fscanf(fin, "%d %d", &x, &y);

    // -- processing -- //
    x *= x;

    // -- output -- //
    fprintf(fout, "%d\n", x + y);

    return 0;
}
```
