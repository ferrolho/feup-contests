/*
	ID: ptkevin1
	PROG: beads
	LANG: C++
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void loadNecklace(vector<char> & necklace) {

	ifstream file("beads.in");

	size_t n; file >> n;

	string str; file >> str;

	for(size_t i = 0; i < n; i++) necklace.push_back(str.at(i));


}

int count(vector<char> & necklace, bool forward, int pos, int size) {

	char color;
	int count = 0;

	// If we have something to count.
	if(size > 0) {

		// If we're going backward, start counting from the previous bead.
		if(!forward) pos--;

		// Adjusts position if needed.
		if(pos < 0) pos = necklace.size() - 1;

		// Pick initial color.
		color = necklace[pos];

	}

	for(int j = 0; j < size; j++) {

		// If picked color was white paints it with the next color.
		if( color == 'w' ) {

			color = necklace[pos];
			count++;

		}
		// Checks if next color is equal to the picked color or white.
		else if( (necklace[pos] == color) || (necklace[pos] == 'w') ) {

			count++;

		}
		// If next color is not white or equal to next color.
		else break;

		// Advances.
		if(forward) pos++;
		else pos--;

		// Adjusts position if needed.
		if( pos < 0 ) pos = necklace.size() - 1;
		else if( pos >= (int) necklace.size() ) pos = 0;

	}

	return count;

}


int main(void) {

	vector<char> necklace;

	loadNecklace(necklace);

	int max = 0;
	int count1 = 0, count2 = 0;

	for(int i = 0; i < (int) necklace.size(); i++) {

		// Counts forward.
		count1 = count(necklace, true, i, necklace.size());
		// Counts backward ignoring everything that has been already counted.
		count2 = count(necklace, false, i, necklace.size() - count1);

		if( (count1 + count2) > max ) max = (count1 + count2);

	}

	cout << "Max: " << max << endl;

	ofstream file("beads.out");
	file << max << endl;


	return 0;
}



