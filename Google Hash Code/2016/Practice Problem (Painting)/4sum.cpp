#include <iostream>
#include <vector>

using namespace std;

// Custom types
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<unsigned int> vui;
typedef vector<vector<int>> vvi;
typedef vector<vector<unsigned int>> vvui;

// Macros
#define ALL(v) (v).begin(), (v).end()

// Classes
class Instruction {
	virtual std::ostream& print(std::ostream&) const = 0;
public:
	virtual ~Instruction() {
	}

	friend ostream& operator<<(ostream& os, const Instruction& i) {
		return i.print(os);
	}
};

class Square : public Instruction {
	ui r, c, s;
public:
	Square(ui r, ui c, ui s) {
		this->r = r;
		this->c = c;
		this->s = s;
	}

	std::ostream& print(std::ostream& os) const {
		return os << "PAINT_SQUARE " << r << " " << c << " " << s;
	}
};

class Line : public Instruction {
	ui r1, c1, r2, c2;
public:
	Line(ui r1, ui c1, ui r2, ui c2) {
		this->r1 = r1;
		this->c1 = c1;

		this->r2 = r2;
		this->c2 = c2;
	}

	std::ostream& print(std::ostream& os) const {
		return os << "PAINT_LINE " << r1 << " " << c1 << " " << r2 << " " << c2;
	}
};

class Erase : public Instruction {
	ui r, c;
public:
	Erase(ui r, ui c) {
		this->r = r;
		this->c = c;
	}

	std::ostream& print(std::ostream& os) const {
		return os << "ERASE_CELL " << r << " " << c;
	}
};

// Constants
const ui N = 1000;
const ui M = 1000;

// Globals
bool picture[N][M];
bool visited[N][M];
vector<Instruction*> instructions;

int main() {
	/*
	 * Input
	 */
	ui n, m;
	cin >> n >> m;

	for (ui i = 0; i < n; i++) {
		for (ui j = 0; j < m; j++) {
			char ch;

			cin >> ch;

			picture[i][j] = ch == '#';
		}
	}

	/*
	 * Processing NxN squares with N-2 empty cells
	 */

	for (ui i = 1; i < n; i++) {
		for (ui j = 1; j < m; j++) {
			if (picture[i][j] && !visited[i][j]) {
				ui n = 0;
				vector<pair<ui, ui>> emptyCells = vector<pair<ui, ui>>();
				bool flag = false, make = false;
				while (n++ && emptyCells.size() <= n) {
					if (flag) {
						visited[i + n - 1][j] = true;
						visited[i - n - 1][j] = true;
						visited[i + n - 1][j + n - 1] = true;
						visited[i - n - 1][j - n - 1] = true;
						visited[i + n - 1][j - n - 1] = true;
						visited[i - n - 1][j - n - 1] = true;
						visited[i][j + n - 1] = true;
						visited[i][j - n - 1] = true;
						make = true;
					}
					if (!picture[i + n][j]) {
						emptyCells.push_back(make_pair(i + n, j));
					}
					if (!picture[i - n][j]) {
						emptyCells.push_back(make_pair(i - n, j));
					}
					if (!picture[i + n][j - n]) {
						emptyCells.push_back(make_pair(i + n, j - n));
					}
					if (!picture[i + n][j + n]) {
						emptyCells.push_back(make_pair(i + n, j + n));
					}
					if (!picture[i - n][j + n]) {
						emptyCells.push_back(make_pair(i - n, j + n));
					}
					if (!picture[i - n][j - n]) {
						emptyCells.push_back(make_pair(i - n, j - n));
					}
					if (!picture[i][j + n]) {
						emptyCells.push_back(make_pair(i, j + n));
					}
					if (!picture[i][j - n]) {
						emptyCells.push_back(make_pair(i, j - n));
					}
					flag = true;
				}

				if (make) {
					for (ui i = 0; i < emptyCells.size(); i++)
						instructions.push_back(new Erase(emptyCells[i].first, emptyCells[i].second));
					instructions.push_back(new Square(i, j, n));
				}
			}
		}
	}


	/*
	* Processing lines and isolated squares
	*/

	for (ui i = 0; i < n; i++)
		for (ui j = 0; j < m; j++)
			if (picture[i][j] && !visited[i][j]) {
				ui jStart = j;

				do {
					j++;
				} while (j < m && picture[i][j]);

				instructions.push_back(new Line(i, jStart, i, j - 1));
			}

	/*
	 * Output
	 */
	cout << instructions.size() << endl;

	for (auto inst : instructions)
		cout << *inst << endl;

	return 0;
}
