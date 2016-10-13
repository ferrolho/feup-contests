#include "stdio.h"
#include <iostream>
#include <string>	
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<unsigned int> vui;
#define PB push_back
#define FOR(i, a, b) for(unsigned int i = a; i < b; i++)
#define ALL(v) (v).begin(), (v).end()
#define foreach(v, it) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++ )

void print(const vector<string> &grid) {
    FOR(i, 0, grid.size())
    cout << grid[i] << endl;
    cout << endl;
}

int main() {
	// initializing data
	unsigned int T, N;
	string line;
	vector<string> grid;
	bool squareDetected;
	unsigned int x1, y1, x2, y2;

	cin >> T;
	FOR(t, 0, T) {
		// reading input
		cin >> N;
		grid.clear();
		FOR(i, 0, N) {
			cin >> line;
			grid.PB(line);
		}
		
		// processing input
		squareDetected = true;

		// finding first '#'
		bool cardinalFound = false;
		FOR(i, 0, N) {
			FOR(j, 0, N) {
				if (grid[i][j] == '#') {
					cardinalFound = true;
					x1 = j;
					y1 = i;

					unsigned int k;
					for(k = j; k < N; k++)
						if (grid[i][k] == '.')
							break;
					x2 = k-1;
					y2 = y1 + (x2-x1);

					break;
				}
			}

			if (cardinalFound)
				break;
		}
		if (!cardinalFound)
			squareDetected = false;

		// checking if everything inside the coords is a '#'
		if (squareDetected) {
			FOR(i, y1, y2+1) {
				FOR(j, x1, x2+1) {
					if (grid[i][j] == '.') {
						squareDetected = false;
						break;
					}
				}

				if (!squareDetected)
					break;
			}
		}

		// checking if everything outside the coords is a '.'
		if (squareDetected) {
			FOR(i, y1, N) {
				FOR(j, 0, N) {
					if (y1 <= i && i <= y2 && x1 <= j && j <= x2)
						j = x2+1;

					if (j < N && grid[i][j] != '.') {
						squareDetected = false;
						break;
					}
				}

				if (!squareDetected)
					break;
			}
		}

		// outputting data
		printf("Case #%d: ", t+1);
		if (squareDetected)
			printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}