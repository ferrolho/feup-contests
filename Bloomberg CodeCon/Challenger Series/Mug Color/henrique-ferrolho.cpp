#include <iostream>
#include <map>
using namespace std;

// Custom types
typedef unsigned int ui;

// Globals
map<string, ui> colorToPosition;
map<ui, string> positionToColor;
bool seen[5];

void initMaps() {
	colorToPosition["White"]  = 0;
	colorToPosition["Black"]  = 1;
	colorToPosition["Blue"]   = 2;
	colorToPosition["Red"]    = 3;
	colorToPosition["Yellow"] = 4;

	positionToColor[0] = "White";
	positionToColor[1] = "Black";
	positionToColor[2] = "Blue";
	positionToColor[3] = "Red";
	positionToColor[4] = "Yellow";
}

bool found() {
	ui count = 0;

	for (auto x : seen)
		if (x) count++;

	return count == 4;
}

int main() {
	initMaps();

	ui n;
	cin >> n;

	for (ui i = 0; i < n && !found(); i++) {
		string color;
		cin >> color;

		seen[colorToPosition[color]] = true;
	}

	for (ui i = 0; i < 5; i++) {
		if (!seen[i])
			cout << positionToColor[i] << endl;
	}

	return 0;
}
