#include <iostream>
#include <vector>
using namespace std;

typedef unsigned int uint;
typedef vector<vector<bool>> Board;

void printBoard(const Board& board) {
	for (auto row : board) {
		for (auto elem : row)
			cout << elem << " ";
		cout << endl;
	}
}

bool blockIsFree(uint r1, uint c1, uint r2, uint c2, const Board& board) {
	for (uint i = r1 - 1; i < r2; i++) {
		for (uint j = c1 - 1; j < c2; j++) {
			if (board[i][j])
				return false;
		}
	}

	return true;
}

int main() {
	uint p;
	cin >> p;

	for (uint i = 0; i < p; i++) {
		uint s, n;
		cin >> s >> n;

		Board board(s, vector<bool>(s));

		for (uint j = 0; j < n; j++) {
			uint r1, c1, r2, c2;
			cin >> r1 >> c1 >> r2 >> c2;

			for (uint k = r1 - 1; k < r2; k++) {
				for (uint l = c1 - 1; l < c2; l++)
					board[k][l] = true;
			}
		}

		//printBoard(board);
		//cout << blockIsFree(4, 4, 7, 10, board) << endl;

		uint largestBlockArea = 0;

		for (uint r = 1; r <= s; r++) {
			for (uint c = 1; c <= s; c++) {
				for (int h = s - r; h >= 0; h--) {
					for (int w = s - c; w >= 0; w--) {
						uint blockArea = (w + 1) * (h + 1);

						if (blockArea <= largestBlockArea) break;

						if (blockIsFree(r, c, r + h, c + w, board)) {
							largestBlockArea = max(largestBlockArea, blockArea);
						}
					}
				}
			}
		}

		cout << largestBlockArea << endl;
	}

	return 0;
}
