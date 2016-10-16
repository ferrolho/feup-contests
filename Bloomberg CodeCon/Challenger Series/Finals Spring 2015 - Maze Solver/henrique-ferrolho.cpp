#include <iostream>
#include <vector>
using namespace std;

// Custom types
typedef unsigned int ui;
typedef vector<pair<ui, ui>> vpuiui;

// Globals
ui R, C;
vector<string> maze;

bool visited(ui row, ui col, const vpuiui& path) {
    for (auto coord : path)
        if (row == coord.first && col == coord.second)
            return true;

    return false;
}

bool canGoTo(ui row, ui col, const vpuiui& path) {
    return maze[row][col] == '_' && !visited(row, col, path);
}

vpuiui possibleMoves(ui row, ui col, const vpuiui& path) {
    vpuiui moves;

    if (row > 0     && canGoTo(row - 1, col, path))
        moves.push_back(make_pair(row - 1, col));

    if (row < R - 1 && canGoTo(row + 1, col, path))
        moves.push_back(make_pair(row + 1, col));

    if (col > 0     && canGoTo(row, col - 1, path))
        moves.push_back(make_pair(row, col - 1));

    if (col < C - 1 && canGoTo(row, col + 1, path))
        moves.push_back(make_pair(row, col + 1));

    return moves;
}

void dfs(ui row, ui col, vpuiui path) {
    path.push_back(make_pair(row, col));

    if (row == R - 2 && col == C - 1) {
        for (auto coord : path)
            cout << coord.first << "," << coord.second << endl;
    } else {
        auto moves = possibleMoves(row, col, path);

        for (auto move : moves)
            dfs(move.first, move.second, path);
    }
}

int main() {
    cin >> R >> C;

    maze = vector<string>(R);

    for (ui i = 0; i < R; i++)
        cin >> maze[i];

    dfs(1, 0, vpuiui());

    return 0;
}
