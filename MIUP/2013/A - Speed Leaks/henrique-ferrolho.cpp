#include <stdio.h>
#include <string>	
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<unsigned int> vui;
#define FOR(i, a, b) for(unsigned int i = a; i < b; i++)
#define ALL(v) (v).begin(), (v).end()
#define foreach(v, it) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++ )
 
struct Record {
	string plate;
	vui speeds;

	bool operator <(const Record &r) const {
		if (speeds != r.speeds)
			return speeds > r.speeds;
		return plate < r.plate;
	}
};

bool faster(unsigned int i, unsigned int j) { return i > j; }

void const printRecords(vector<Record> &records) {
    FOR(i, 0, records.size()) {
        // printing plate
        printf("%s", records[i].plate.c_str());

        // printing speeds
        FOR(j, 0, records[i].speeds.size())
        	printf(" %u", records[i].speeds[j]);
        printf("\n");
    }
}

int main() {
	// initializing data
	map<string, vui> records;
	vector<Record> sortedRecords;

	// reading input
	char plate[12];
	unsigned int speed;
	while(scanf("%s %u", plate, &speed) != EOF)
		records[string(plate)].push_back(speed);

	// sorting speeds for each record and placing data in a vector
	foreach(records, it) {
		sort(ALL(it->second), faster);

		Record temp;
		temp.plate = it->first;
		temp.speeds = it->second;
		sortedRecords.push_back(temp);
	}

	// sorting records
	sort(ALL(sortedRecords));

	// outputting data
	printRecords(sortedRecords);

	return 0;
}