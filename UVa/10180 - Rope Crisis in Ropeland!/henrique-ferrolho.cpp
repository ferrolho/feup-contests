#include <cmath>
#include <iomanip>
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

// Globals

int main() {
	ui N;

	// input
	cin >> N;

	while (N--) {
		double x1, y1, x2, y2, r;

		cin >> x1 >> y1 >> x2 >> y2 >> r;

		// 'u' is the vector from p1 to p2
		double u[2];
		u[0] = x2 - x1;
		u[1] = y2 - y1;

		// 'v' is the vector from p1 to the origin
		double v[2];
		v[0] = 0 - x1;
		v[1] = 0 - y1;

		double dotProductUV = u[0] * v[0] + u[1] * v[1];
		double uNorm = sqrt(u[0] * u[0] + u[1] * u[1]);

		// (u . v) / ||u||^2 - this is part of the vector projection formula
		double proj = dotProductUV / (uNorm * uNorm);

		// distance of each point to origin
		double h1 = sqrt(x1 * x1 + y1 * y1);
		double h2 = sqrt(x2 * x2 + y2 * y2);

		double distToOrigin;

		if (0 <= proj && proj <= 1)
			// shortest distance from origin to the rope
			// note - this is the shortest distance from a point to a
			// line formula, but it is shorter because (x0, y0) = (0, 0)
			distToOrigin = abs(x2 * y1 - y2 * x1)
					/ sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2));
		else
			distToOrigin = h1 < h2 ? h1 : h2;

		// distance between points
		double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

		double answer;

		if (distToOrigin >= r)
			// since the rope does not intersect the pillar,
			// the minimum length is the distance between the two points
			answer = d;
		else {
			// angle between the two points and the origin (origin being the vertex)
			double alpha = acos((h1 * h1 + h2 * h2 - d * d) / (2 * h1 * h2));

			// beta1 and beta2 are the angles of the sector
			// where the rope is not touching the pillar
			double beta1 = acos(r / h1);
			double beta2 = acos(r / h2);

			// arc measure of the sector where the rope is in touch with the pillar
			double arcMeasure = alpha - (beta1 + beta2);

			// a and b is the length of the rope that is not in touch with the pillar
			double a = sqrt(h1 * h1 - r * r);
			double b = sqrt(h2 * h2 - r * r);

			// arc is the length of the rope in touch with the pillar
			double arc = arcMeasure * r;

			// the minimum rope size is the sum: a + b + arc
			answer = a + b + arc;
		}

		// output
		cout << fixed << setprecision(3) << answer << endl;
	}

	return 0;
}
