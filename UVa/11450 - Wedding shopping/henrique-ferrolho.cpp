#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int dp[201][21];

int cost(int M, int C, const vector<vector<int> >& garments) {
	if (M < 0)
		return -2;

	if (C == 0)
		return 0;

	if (dp[M][C] != -1)
		return dp[M][C];

	int MAX = -2;
	for (int i = 0; i < garments[C - 1].size(); i++) {
		int ci = garments[C - 1][i];
		int maxi = cost(M - ci, C - 1, garments);

		if (maxi != -2)
			MAX = max(MAX, ci + maxi);
	}
	dp[M][C] = MAX;

	return MAX;
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int M, C;
		cin >> M >> C;

		vector<vector<int> > garments;
		for (int j = 0; j < C; j++) {
			int K;
			cin >> K;

			vector<int> garment;
			for (int k = 0; k < K; k++) {
				int temp;

				cin >> temp;
				garment.push_back(temp);
			}
			garments.push_back(garment);
		}

		// set dp
		memset(dp, -1, sizeof(dp));

		// magrik
		if (cost(M, C, garments) < 0)
			cout << "no solution" << endl;
		else
			cout << cost(M, C, garments) << endl;

		/*
		 for (int j = 0; j < garments.size(); j++) {
		 for (int k = 0; k < garments[j].size(); k++)
		 cout << garments[j][k] << " ";
		 cout << endl;
		 }
		 */
	}

	return 0;
}
