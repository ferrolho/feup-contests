/*
 * main.cpp
 *
 *  Created on: 22 de Set de 2013
 *      Author: Henrique Ferrolho
 *       Title: Sentry Robots
 */

#include <iostream>
#include <vector>
using namespace std;

void printGrid(vector<vector<char> > &vec, int Y, int X) {
	for (int j = 0; j < Y; j++) {
		for (int k = 0; k < X; k++) {
			cout << vec[j][k] << " ";
		}
		cout << endl;
	}
}

int main() {
	// declaring variables
	int C, Y, X, P, W;
	vector<int> output;
	vector<vector<char> > grid;
	int tempX, tempY;
	int delX, delY;
	int robots;

	// getting number of test cases
	cin >> C;

	for (int i = 0; i < C; i++) {
		// ----- READING INPUT -----
		// getting grid height and width
		cin >> Y >> X;

		// building grid
		grid = vector<vector<char> > (Y, vector<char> (X, '.'));

		// getting number of POI
		cin >> P;
		// reading coords of the poi
		for (int j = 0; j < P; j++) {
			cin >> tempY >> tempX;
			grid[tempY-1][tempX-1] = '*';
		}

		// getting number of obstacles
		cin >> W;
		// reading coords of the obstacles
		for (int j = 0; j < W; j++) {
			cin >> tempY >> tempX;
			grid[tempY-1][tempX-1] = '#';
		}

		// ----- PROCESSING INFO -----
		robots = 0;

		int horLineSize = 1, verLineSize = 1;
		// scanning grid for first point
		for (int j = 0; j < Y; j++) {
			for (int k = 0; k < X; k++) {
				if (grid[j][k] == '*') {
					// resetting variables
					tempX = tempY = 1;
					delX = delY = 1;

					for (int l = k+1; l < X; l++) {
						if (grid[j][l] != '#') {
							delX++;
							if (grid[j][l] == '*')
								tempX++;
						} else
							break;
					}
					for (int l = j+1; l < Y; l++) {
						if (grid[l][k] != '#') {
							delY++;
							if (grid[l][k] == '*')
								tempY++;
						} else
							break;
					}

					// checking best option
					if (tempX > tempY) {
						//cout << "deleting line" << endl;
						robots++;
						for (int l = k; l-k < delX; l++) {
							grid[j][l] = '.';
						}
					} else {
						//cout << "deleting row" << endl;
						robots++;
						for (int l = j; l-j < delY; l++) {
							grid[l][k] = '.';
						}
					}

					//printGrid(grid, Y, X);
				}
			}
		}

		//cout << "Robots: " << robots << endl;
		output.push_back(robots);
	}

	// ----- PRINTING OUTPUT -----
	for (int i = 0; i < C; i++)
		cout << output[i] << endl;

	return 0;
}
