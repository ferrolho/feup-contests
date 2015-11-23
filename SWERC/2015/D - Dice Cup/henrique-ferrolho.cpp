#include <iostream>
#include <map>
#include <set>
using namespace std;

typedef unsigned int ui;
typedef set<int> si;

int main() {
	ui N, M;
	cin >> N >> M;

	map<int, int> sumNumOutcomes;

	for (ui i = 1; i <= N; i++)
		for (ui j = 1; j <= M; j++)
			sumNumOutcomes[i + j]++;

	si sums;
	int best = -1;

	for (const auto& pair : sumNumOutcomes) {
		if (best == -1) {
			best = pair.second;

			sums.insert(pair.first);
		} else if (pair.second == best)
			sums.insert(pair.first);
		else if (pair.second > best) {
			best = pair.second;

			sums.clear();
			sums.insert(pair.first);
		}
	}

	for (const auto& sum : sums)
		cout << sum << endl;

	return 0;
}
