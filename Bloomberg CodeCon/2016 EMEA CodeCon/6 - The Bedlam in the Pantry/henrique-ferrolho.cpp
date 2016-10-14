#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

// Custom types
typedef unsigned int ui;
typedef vector<unsigned int> vui;

// Macros
#define ALL(v) (v).begin(), (v).end()

// Globals
bool visited[10000][10000];
vector<string> arena;
pair<ui, ui> coord;
queue<pair<pair<int, int>, ui>> astarQueue;

int astar(int y, int x, int len);

int astarAux() {
	auto y = astarQueue.front().first.first;
	auto x = astarQueue.front().first.second;
	auto len = astarQueue.front().second;
	astarQueue.pop();

	if (arena[y][x] == 'S')
		return len;

	return astar(y, x, len + 1);
}

void addToAstarQueue(int y, int x, int len) {
	if (0 <= y && y < (int) arena.size() &&
		0 <= x && x < (int) arena[y].size() &&
		!visited[y][x] && arena[y][x] != 'X')
		astarQueue.push(make_pair(make_pair(y, x), len));
}

int astar(int y, int x, int len) {
	visited[y][x] = true;

	addToAstarQueue(y - 1, x    , len);
	addToAstarQueue(y + 1, x    , len);
	addToAstarQueue(y    , x - 1, len);
	addToAstarQueue(y    , x + 1, len);

	if (astarQueue.empty())
		return -1;

	return astarAux();
}

int main() {
	ui N, M;
	cin >> N >> M;

	for (ui i = 0; i < N; i++) {
		string line;
		cin >> line;

		auto xCoord = line.find("*");
		if (xCoord != std::string::npos) {
			coord.first = i;
			coord.second = xCoord;
		}

		arena.push_back(line);
	}

	cout << astar(coord.first, coord.second, 1) << endl;

	return 0;
}
