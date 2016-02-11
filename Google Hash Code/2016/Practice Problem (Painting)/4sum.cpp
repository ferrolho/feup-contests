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

// Constants
const ui N = 1000;
const ui M = 1000;

// Globals
bool picture[N][M];
bool visited[N][M];

// Classes
class Instruction {

	virtual void markAsVisited() = 0;

	virtual std::ostream& print(std::ostream&) const = 0;

public:

	virtual ~Instruction() {
	}

	friend ostream& operator<<(ostream& os, const Instruction& i) {
		return i.print(os);
	}

};

class Square: public Instruction {

	ui r, c, s;

public:

	Square(ui r, ui c, ui s) {
		this->r = r;
		this->c = c;
		this->s = s;
	}

	void markAsVisited() {
		for (ui i = r - s; i <= r + s; i++)
			for (ui j = c - s; j <= c + s; j++)
				visited[i][j] = true;
	}

	std::ostream& print(std::ostream& os) const {
		return os << "PAINT_SQUARE " << r << " " << c << " " << s;
	}

};

class Line: public Instruction {

	ui r1, c1, r2, c2;

public:

	Line(ui r1, ui c1, ui r2, ui c2) {
		this->r1 = r1;
		this->c1 = c1;

		this->r2 = r2;
		this->c2 = c2;
	}

	void markAsVisited() {
		if (c1 == c2) {
			// vertical line
			for (ui i = r1; i <= r2; i++)
				visited[i][c1] = true;
		} else {
			// horizontal line
			for (ui i = c1; i <= c2; i++)
				visited[r1][i] = true;
		}
	}

	std::ostream& print(std::ostream& os) const {
		return os << "PAINT_LINE " << r1 << " " << c1 << " " << r2 << " " << c2;
	}

};

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
	 * Processing
	 */
	vector<Instruction*> instructions;

	for (ui i = 0; i < n; i++)
		for (ui j = 0; j < m; j++)
			if (picture[i][j] && !visited[i][j]) {
				// expand to the right
				ui right = j;
				ui horNonVisited = 0;

				while (right < m && picture[i][right]) {
					if (!visited[i][right])
						horNonVisited++;

					right++;
				}
				right--;

				// expand downwards
				ui down = i;
				ui verNonVisited = 0;

				while (down < n && picture[down][j]) {
					if (!visited[down][j])
						verNonVisited++;

					down++;
				}
				down--;

				// save best instruction
				Line* line =
						horNonVisited > verNonVisited ?
								new Line(i, j, i, right) :
								new Line(i, j, down, j);

				instructions.push_back(line);

				// update visited cells matrix
				line->markAsVisited();
			}

	/*
	 * Output
	 */
	cout << instructions.size() << endl;

	for (auto inst : instructions)
		cout << *inst << endl;

	return 0;
}
