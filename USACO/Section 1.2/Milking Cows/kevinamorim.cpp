/*
	ID: ptkevin1
	PROG: milk2
	LANG: C++
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <limits>

using namespace std;

typedef vector<pair<int, int> > DATES;

void printVector(DATES & times) {

	for(DATES::iterator it = times.begin(); it != times.end(); ++it) {
		cout << it->first << " " << it->second << endl;
	}

}

void insertionSort(DATES & times) {

	for (unsigned int p = 1; p < times.size(); p++)
	{
		pair<int, int> tmp = times[p];
		int j;
		for (j = p; j > 0 && tmp.first <= times[j-1].first; j--) {

			if(tmp.first == times[j-1].first) {
				if(tmp.second < times[j-1].second) {
					times[j] = times[j-1];
				}
			} else {
				times[j] = times[j-1];
			}

		}

		times[j] = tmp;
	}

}

void loadData(DATES & times) {

	ifstream file("milk2.in");

	int i; file >> i;

	int start, end;
	pair<int, int> time;

	for( ; i > 0; i--) {

		file >> start; file >> end;

		time = make_pair(start, end);

		times.push_back(time);

	}


	// Prints loaded data.
	// For testing purposes.
	/*
	for(DATES::iterator it = times.begin();
			it != times.end(); ++it) {
		cout << it->first << " " << it->second << endl;
	}
	*/


}

/**
 * Searches minimum next start time. That is, the next starting time for a cow being milked that is after the actualTime.
 */
int searchMinStartTime(DATES & times, int actualTime) {

	int min = numeric_limits<int>::max(); // Assuming numeric_limits<int>::max() as the biggest time we can have.

	for(DATES::iterator it = times.begin();
			it != times.end(); ++it) {

		if( (it->first < min) && (it->first >= actualTime) ) min = it->first;

	}

	if(min == numeric_limits<int>::max()) min = -1;

	return min;

}

/**
 * Searches best stopping time (time when no cows are being milked).
 */
int searchStopTime(DATES & times, int startTime) {

	// Stop time that matches the start time.
	int correspondingStopTime;

	// Searches for the matching stop time.
	for(DATES::iterator it = times.begin(); it != times.end(); ++it) {

		if( it->first == startTime ) correspondingStopTime = it->second;

	}

	int stopTime = correspondingStopTime;

	// Searches for a stop time that matches a starting time that is less or equal than the corresponding stop time but bigger than our actual stop time.
	// That will give us the time when no cows are being milked.
	int i = 0;
	for(DATES::iterator it = times.begin(); it != times.end(); ++it) {

		if( it->first <= correspondingStopTime ) {

			if( it->second > stopTime ) {

				stopTime = it->second;
				correspondingStopTime = stopTime;
				i++;

			}

		}
	}

	// Erases all times that are older than our new stop time. Reduces vector size.
	times.erase(times.begin(), times.begin()+i);

	return stopTime;


}


int main( void ) {

	DATES times;

	loadData(times);
	insertionSort(times);

	// Testing purposes.
	//printVector(times);

	// Initial Values.
	int actualTime = searchMinStartTime(times, -1); // Passing -1 as actual time argument so we can accept 0 as a starting time.
	int nextStopTime = searchStopTime(times, actualTime);

	int max_milking = (nextStopTime - actualTime);
	int max_idle = 0;

	while(actualTime >= 0) {

		actualTime = nextStopTime;

		// Holds next starting time for when a cow will be milked.
		int temp = searchMinStartTime(times, actualTime);

		// If we got -1 that means no more time are available, so we reached the end.
		if( temp == -1 ) break;

		// Checks how many time has passed since no cows are being milked until at least one cow is being milked.
		if( (temp - actualTime) > max_idle ) max_idle = (temp - actualTime);

		actualTime = temp;

		nextStopTime = searchStopTime(times, actualTime);

		// Checks how many time has passed since a cow has started being milked until no cows were being milked.
		if( (nextStopTime - actualTime) > max_milking ) max_milking = (nextStopTime - actualTime);

	}

	// Prints results. (Testing purposes).
	cout << "Max milking: " << max_milking << endl;
	cout << "Max idle: " << max_idle << endl;

	ofstream file ("milk2.out");

	file << max_milking << " " << max_idle << endl;


	return 0;
}




