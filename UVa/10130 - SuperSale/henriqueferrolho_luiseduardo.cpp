#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

typedef unsigned int ui;
#define FOR(i, a, b) for(unsigned int i = a; i < b; i++)
#define ALL(v) (v).begin(), (v).end()

int dp[31][1001];
vector<int> P, W, MW;

int cost(int MW, int N) {
	if (MW < 0)
		return -2;
	if (N == 0)
		return 0;
	if (dp[MW][N] != -1)
		return dp[MW][N];

	int pi = P[N - 1];
	int wi = W[N - 1];
	int MAX = cost(MW, N - 1);
	if (cost(MW - wi, N - 1) >= 0)
		MAX = max(pi + cost(MW - wi, N - 1), MAX);

	dp[MW][N] = MAX;

	return MAX;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		ui N, G;
		cin >> N;

		P.resize(N);
		W.resize(N);
		FOR(i, 0 , N)
			cin >> P[i] >> W[i];

		cin >> G;
		MW.resize(G);
		FOR(i, 0, G)
			cin >> MW[i];
		sort(ALL(MW));

		memset(dp, -1, sizeof(dp));
		cost(MW.back(), N);

		int res = 0;
		FOR(i, 0, MW.size())
			res += cost(MW[i], N);

		cout << res << endl;
	}

	return 0;
}
