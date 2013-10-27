#include <stdio.h>
#include <iostream>
#include <string>	
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<unsigned int> vui;
#define FOR(i, a, b) for(unsigned int i = a; i < b; i++)

struct Record {
	string plate;
	vui speeds;
};

bool faster(unsigned int i, unsigned int j) { return (i > j); }

void const printRecords(vector<Record> &records) {
	FOR(i, 0, records.size()) {
		// printing plate
		printf("%s", records[i].plate.c_str());

		// printing speeds
		FOR(j, 0, records[i].speeds.size()) {
			printf(" %u", records[i].speeds[j]);
		}
		printf("\n");
	}
}

void addRecord(string plate, unsigned int speed, vector<Record> &records) {
	FOR(i, 0, records.size()) {
		// license plate match found
		if (records[i].plate.compare(plate) == 0) {
			// pushing back speed
			records[i].speeds.push_back(speed);
			return;
		}
	}

	// if rec uses a license plate not yet on records
	Record temp;
	temp.plate = plate;
	temp.speeds = vui (1, speed);
	records.push_back(temp);
}

bool biggerRecord(Record r1, Record r2) {
	unsigned int limit = r1.speeds.size();

	if (r2.speeds.size() < r1.speeds.size())
		limit = r2.speeds.size();

	FOR(i, 0, limit) {
		if (r1.speeds[i] > r2.speeds[i])
			return true;
		else if (r1.speeds[i] < r2.speeds[i])
			return false;
	}

	// if all values are equal but one vec is bigger than other
	if (r1.speeds.size() > r2.speeds.size())
		return true;
	else if (r1.speeds.size() < r2.speeds.size())
		return false;
	// if speed reocrds are the same, compare plate
	else {
		if (r1.plate > r2.plate)
			return true;
		else
			return false;
	}
}

int main() {
	// initializing data
	vector<Record> records;

	// reading input
	char plate[12];
	unsigned int speed;
	while(scanf("%s %u", plate, &speed) != EOF)
		addRecord(plate, speed, records);

	// sorting speeds for each record
	FOR(i, 0, records.size())
		sort(records[i].speeds.begin(), records[i].speeds.end(), faster);
	// sorting records
	sort(records.begin(), records.end(), biggerRecord);

	// outputting data
	printRecords(records);

	return 0;
}