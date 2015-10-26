#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

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
ui cases, NP, NS;
vvi segments, sources;
vi answers;

float segmentYatX(vi segment, int x) {
	float m = (float) (segment[3] - segment[1]) / (segment[2] - segment[0]);

	float b = segment[1] - m * segment[0];

	return m * x + b;
}

vi segmentDropPoint(const vi& segment) {
	vi point(2);

	// y1 < y2
	if (segment[1] < segment[3]) {
		point[0] = segment[0];
		point[1] = segment[1];
	} else {
		point[0] = segment[2];
		point[1] = segment[3];
	}

	return point;
}

int flowAt(int x, int y) {
	// id and y-coord of the plane where this water will drop
	int bestIndex = -1, bestY = -1;

	// for every segment
	for (ui i = 0; i < segments.size(); i++) {

		// check if any segX1 < sourceX < segX2
		if (segments[i][0] < x && x < segments[i][2]) {

			float segmentCollisionY = segmentYatX(segments[i], x);

			// if water source is above or on the plane
			if (segmentCollisionY <= y) {

				// then this plane might be the one where the
				// water runs when dropped from this source
				if (bestIndex == -1 || segmentCollisionY > bestY) {
					bestIndex = i;
					bestY = segmentCollisionY;
				}
			}
		}
	}

	if (bestIndex >= 0) {
		vi newDrop = segmentDropPoint(segments[bestIndex]);
		return flowAt(newDrop[0], newDrop[1]);
	} else
		return x;
}

void solve() {
	// let water flow from each source
	for (auto source : sources)
		answers.push_back(flowAt(source[0], source[1]));
}

int main() {
	// input
	cin >> cases;

	while (cases--) {
		// segments
		cin >> NP;

		segments.clear();
		for (ui i = 0; i < NP; i++) {
			vi segment(4);

			cin >> segment[0] >> segment[1] >> segment[2] >> segment[3];

			// x2 < x1
			if (segment[2] < segment[0]) {
				swap(segment[0], segment[2]);
				swap(segment[1], segment[3]);
			}

			segments.push_back(segment);
		}

		// source points
		cin >> NS;

		sources.clear();
		for (ui i = 0; i < NS; i++) {
			vi source(2);

			cin >> source[0] >> source[1];

			sources.push_back(source);
		}

		// processing
		answers.clear();
		solve();

		// output
		for (auto answer : answers)
			cout << answer << endl;

		if (cases > 0)
			cout << endl;
	}

	return 0;
}
