#include <iostream>

using namespace std;

// Custom types
typedef unsigned int ui;

// Constants
const ui N = 10000;

// Globals
int bets[N][N];

int main() {
	ui n;

	bool done = false;
	while (!done) {
		cin >> n;

		if (n == 0)
			done = true;
		else {
			int best = 0;

			// input bets
			for (ui i = 0; i < n; i++) {
				cin >> bets[0][i];

				if (bets[0][i] > best)
					best = bets[0][i];
			}

			// go through all the possible consecutive bets
			for (ui i = 1; i < n; i++) {
				for (ui j = 0; j < n - i; j++) {
					bets[i][j] = bets[i - 1][j] + bets[0][i + j];

					if (bets[i][j] > best)
						best = bets[i][j];
				}
			}

			if (best > 0)
				cout << "The maximum winning streak is " << best << "." << endl;
			else
				cout << "Losing streak." << endl;
		}
	}

	return 0;
}
