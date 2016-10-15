#include <iostream>
using namespace std;

// Custom types
typedef unsigned int ui;

ui scorePoints[3] = {7, 3, 2};

int main() {
	ui targetScore;
	cin >> targetScore;

	bool achievable = false;

	for (ui i = 0; i * scorePoints[0] <= targetScore; i++) {
		for (ui j = 0; j * scorePoints[1] <= targetScore; j++) {
			for (ui k = 0; k * scorePoints[2] <= targetScore; k++) {
				ui total = i * scorePoints[0] +
						   j * scorePoints[1] +
						   k * scorePoints[2];

				if (total == targetScore) {
					printf("%d %d %d\n", i, j, k);
					achievable = true;
				}
			}
		}
	}

	if (!achievable)
		cout << "0 0 0" << endl;

	return 0;
}
