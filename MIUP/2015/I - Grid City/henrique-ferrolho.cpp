#include <iostream>
using namespace std;

typedef unsigned int ui;

const int N = 10000000;
long long dp[N + 1];

void prepareDP() {
	dp[1] = 2;
	dp[2] = 5;
	dp[3] = 8;

	for (ui i = 4; i <= N; i++) {
		if (i % 2 == 0)
			dp[i] = dp[i / 2] + dp[i / 2 - 1] + i + 1; // even side
		else
			dp[i] = dp[i / 2] + dp[i / 2] + i + 1; // odd side
	}
}

int main() {
	prepareDP();

	ui T;
	cin >> T;

	for (ui i = 0; i < T; i++) {
		int N;
		cin >> N;

		cout << dp[N] << endl;
	}

	return 0;
}
