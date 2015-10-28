#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// Custom types
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<unsigned int> vui;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<unsigned int>> vvui;
typedef vector<vector<double>> vvd;

// Macros
#define ALL(v) (v).begin(), (v).end()

// Constants
const double PI = acos(-1);

// Globals

int main() {
	vd answers;

	bool done = false;

	while (!done) {
		int n;

		// read the number of vertices in the polygon
		cin >> n;

		if (n == 0)
			done = true;
		else {
			double x1, y1, x2, y2, x3, y3;

			// read three vertices of the polygon
			cin >> x1 >> y1;
			cin >> x2 >> y2;
			cin >> x3 >> y3;

			// calculate slopes
			double ma = (y2 - y1) / (x2 - x1);
			double mb = (y3 - y2) / (x3 - x2);

			// slope of a line perpendicular to another line with slope ma
			double invma = std::isinf(ma) ? 0 : -1 / ma;

			// calculate center of the circle (x, y)
			double x =
					std::isinf(ma) ?
							0 :
							(ma * mb * (y1 - y3) + mb * (x1 + x2)
									- ma * (x2 + x3)) / (2 * (mb - ma));
			double y = invma * (x - (x1 + x2) / 2) + (y1 + y2) / 2;

			// initialize answer boundaries
			double minX = x1, maxX = x1, minY = y1, maxY = y1;

			// calculate variables required to get next vertex
			double theta = 2 * PI / n;
			double cosTheta = cos(theta);
			double sinTheta = sin(theta);

			for (int i = 0; i < n - 1; i++) {
				// calculate next vertex
				double vertexX = x + cosTheta * (x1 - x) - sinTheta * (y1 - y);
				double vertexY = y + sinTheta * (x1 - x) + cosTheta * (y1 - y);

				// updating minX, minY, maxX, and maxY
				minX = min(minX, vertexX);
				minY = min(minY, vertexY);
				maxX = max(maxX, vertexX);
				maxY = max(maxY, vertexY);

				// update x1 and y1 being used to calculate next vertex
				x1 = vertexX;
				y1 = vertexY;
			}

			answers.push_back((maxX - minX) * (maxY - minY));
		}
	}

	// output
	for (ui i = 0; i < answers.size(); i++) {
		cout << fixed << setprecision(3);
		cout << "Polygon " << i + 1 << ": " << answers[i] << endl;
	}

	return 0;
}
