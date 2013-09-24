/*
 * main.cpp
 *
 *  Created on: 21 de Set de 2013
 *      Author: Henrique Ferrolho
 *       Title: Bits Equalizer
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	// getting number of test cases
	int testCases;
	cin >> testCases;
	vector<int> vec;

	for (int c = 0; c < testCases; c++) {
		// reading strings
		string S, T;
		cin >> S >> T;
		int size = S.length();
		int moves = 0;

		// getting number of 1's and 0's on S
		int numOnesS = 0;
		int numZerosS = 0;
		for (int i = 0; i < size; i++) {
			if (S[i] == '1') {
				numOnesS++;
			}
			else if (S[i] == '0') {
				numZerosS++;
			}
		}
		// getting number of 1's and 0's on T
		int numOnesT = 0;
		int numZerosT = 0;
		for (int i = 0; i < size; i++) {
			if (T[i] == '1') {
				numOnesT++;
			}
			else if (T[i] == '0') {
				numZerosT++;
			}
		}

		/*
		cout << "numOnesS: " << numOnesS << endl;
		cout << "numZerosS: " << numZerosS << endl;
		cout << "numOnesT: " << numOnesT << endl;
		cout << "numZerosT: " << numZerosT << endl;*/

		// checking if is possible
		if (numOnesS > numOnesT) {
			//cout << "Impossivel!!!" << endl;
			moves = -1;
            vec.push_back(moves);
            continue;
		}

		// eliminating ?
		for (int i = 0; i < size; i++) {
			if (S[i] == '?') {
				if (T[i] == '1') {
					if (numOnesS < numOnesT) {
						moves++;
						S[i] = '1';
						numOnesS++;
					}
					else if (numZerosS < numZerosT) {
						moves++;
						S[i] = '0';
						numZerosS++;
					}
					else {
						//cout << "ERROR1!" << endl;
					}
				}
				else if (T[i] == '0') {
					if (numZerosS < numZerosT) {
						moves++;
						S[i] = '0';
						numZerosS++;
					}
					else if (numOnesS < numOnesT) {
						moves++;
						S[i] = '1';
						numOnesS++;
					}
					else {
						//cout << "ERROR2!" << endl;
					}
				}
			}
		}

		// swapping elems if needed
		for (int i = 0; i < size; i++) {
			if (S[i] != T[i]) {
				for (int j = i; j < size; j++) {
					if (S[i] != S[j] && S[j] != T[j]) {
						moves++;
						char temp = S[i];
						S[i] = S[j];
						S[j] = temp;
						break;
					}
				}
			}
		}

        // changing 0's to 1's if needed
        for (int i = 0; i < size; i++) {
            if (S[i] != T[i] && S[i] == '0') {
                moves++;
                S[i] = 1;
            }
        }

		/*
		cout << S << endl;
		cout << T << endl;
		cout << "Moves: " << moves << endl;*/

		vec.push_back(moves);
	}

	for (int c = 0; c < testCases; c++) {
		cout << "Case " << c+1 << ": " << vec[c] << endl;
	}

	return 0;
}
