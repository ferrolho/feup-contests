/*
 ID: henriq13
 PROG: barn1
 LANG: C++
 */
#include <stdio.h>
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
const string PROB_NAME = "barn1";

ui calcGap(const vui& stalls, int i) {
	return stalls[i + 1] - stalls[i];
}

ui getMinGapIndex(const vui& stalls, vui gaps) {
	ui min = 0;
	ui minValue = calcGap(stalls, gaps[min]);

	FOR (i, 1, gaps.size())
	{
		ui value = calcGap(stalls, gaps[i]);

		if (value < minValue) {
			minValue = value;
			min = i;
		}
	}

	return min;
}

int main() {
	string str;
	str = PROB_NAME + ".in";
	FILE *fin = fopen(str.c_str(), "r");
	str = PROB_NAME + ".out";
	FILE *fout = fopen(str.c_str(), "w");

	// -- input -- //
	ui M, S, C;
	fscanf(fin, "%d %d %d", &M, &S, &C);

	vui stalls;
	FOR (i, 0, C)
	{
		int stall;
		fscanf(fin, "%d", &stall);

		stalls.push_back(stall);
	}
	sort(ALL(stalls));

	// -- processing -- //
	ui blockedStalls = 0;
	ui maxGaps = M - 1;

	if (maxGaps == 0) {
		blockedStalls = stalls[stalls.size() - 1] - stalls[0] + 1;
	} else {
		vui gaps;

		FOR (i, 0, C-1)
		{
			if (gaps.size() < maxGaps)
				gaps.push_back(i);
			else {
				int currentGap = calcGap(stalls, i);

				int minSavedGapID = getMinGapIndex(stalls, gaps);
				int minSavedGap = calcGap(stalls, gaps[minSavedGapID]);

				if (currentGap > minSavedGap)
					gaps[minSavedGapID] = i;
			}
		}

		sort(ALL(gaps));

		FOR(i, 0, gaps.size() + 1)
		{
			int val;

			if (i == 0)
				val = stalls[gaps[i]] - stalls[0] + 1;
			else if (i == gaps.size())
				val = stalls[stalls.size() - 1] - stalls[gaps[i - 1] + 1] + 1;
			else
				val = stalls[gaps[i]] - stalls[gaps[i - 1] + 1] + 1;

			blockedStalls += val;
		}
	}

	// -- output -- //
	fprintf(fout, "%u\n", blockedStalls);

	return 0;
}
