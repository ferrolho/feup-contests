#include <iostream>
#include <vector>
using namespace std;

// Custom types
typedef unsigned int ui;
typedef vector<ui> vui;
typedef vector<vector<ui>> vvui;

// Macros
#define ALL(v) (v).begin(), (v).end()

// Globals
vvui possibleMoves = {
    {4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9},
    {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}
};

ui dfs(ui section, ui movesLeft) {
    if (!movesLeft)
        return section == 9;

    ui sum = 0;

    for (auto nextSection : possibleMoves[section])
        sum += dfs(nextSection, movesLeft - 1);

    return sum;
}

ui uniquePaths(ui moves) {
    return dfs(1, moves);
}

int main() {
    ui n;
    cin >> n;

    cout << uniquePaths(n) << endl;

    return 0;
}
