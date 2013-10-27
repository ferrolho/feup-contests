#include <stdio.h>
#include <iostream>
#include <string>	
#include <vector>
#include <map>
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

bool const biggerRecord(Record r1, Record r2) {
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
	// if speed records are the same, compare plate
	else
		return r1.plate > r2.plate;
}

int main() {
	// initializing data
	map<string, vui> records;

	// reading input
	char plate[12];
	unsigned int speed;
	while(scanf("%s %u", plate, &speed) != EOF)
		records[plate].push_back(speed);

	// sorting speeds for each record
	for(map<string, vui>::iterator it = records.begin(); it != records.end(); it++)
		sort(it->second.begin(), it->second.end(), faster);

	// switching to vector to sort data
	vector<Record> sortedRecords;
	for(map<string, vui>::iterator it = records.begin(); it != records.end(); it++) {
		Record temp;
		temp.plate = it->first;
		temp.speeds = it->second;
		sortedRecords.push_back(temp);
	}

	// sorting records
	sort(sortedRecords.begin(), sortedRecords.end(), biggerRecord);

	// outputting data
	printRecords(sortedRecords);

	return 0;
}