/*
ID: henriqu13
LANG: C++
TASK: milk2
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
#define FOR(i, a, b) for(unsigned int i = a; i < b; i++)

struct Interval {
    unsigned int start;
    unsigned int end;
};

int main() {
    ///////////////////
    // READING INPUT //
    ///////////////////
    ifstream fin("milk2.in");
    unsigned int N;
    fin >> N;

    unsigned int a, b;
    vector<Interval> timeline;
    FOR(i, 0, N) {
        // reading interval
        fin >> a >> b;

        // --- deciding where to place interval --- //
        // creating new entry at the end of timeline
        if (i == 0 || timeline[timeline.size()-1].end < a) {
            Interval temp;
            temp.start = a;
            temp.end = b;
            timeline.push_back(temp);
            continue;
        }

        bool done = false;
        FOR(j, 0, timeline.size()) {
            // creating new entry before an interval
            if (b < timeline[j].start) {
                Interval temp;
                temp.start = a;
                temp.end = b;
                timeline.insert(timeline.begin() + j, temp);
                break;
            }

            // editing an interval
            if (a < timeline[j].start) {
                // a < timeline[j].start -> Edited interval
                timeline[j].start = a;

                FOR(k, j, timeline.size()) {
                    if (b <= timeline[k].end) {
                        // b is already inside the interval
                        done = true;
                        break;
                    }
                    else if (timeline[k].end < b && (b < timeline[k+1].start || k == timeline.size()-1)) {
                        // b < next interval start && b > current interval end -> REPLACING IT
                        timeline[k].end = b;
                        done = true;
                        break;
                    }
                    else {
                        // erasing an interval
                        // erasing interval
                        timeline.erase(timeline.begin() + k);
                        timeline[k].start = a;
                        k--;
                    }
                }
                break;
            }
            if (done)
                break;

            if (a <= timeline[j].end) {
                // a is already inside the interval
                FOR(k, j, timeline.size()) {
                    if (b <= timeline[k].end) {
                        // b is already inside the interval
                        done = true;
                        break;
                    }
                    else if (timeline[k].end < b && (b < timeline[k+1].start || k == timeline.size()-1)) {
                        // b < next interval start && b > current interval end -> REPLACING IT
                        timeline[k].end = b;
                        done = true;
                        break;
                    }
                    else {
                        // erasing an interval
                        timeline[k+1].start = timeline[k].start;
                        timeline.erase(timeline.begin() + k);
                        k--;
                    }
                }
            }
            if (done)
                break;
        }
    }

    ///////////////////////
    // INITIALIZING DATA //
    ///////////////////////
    unsigned int max1 = 0, max2 = 0;

    /////////////////////
    // PROCESSING DATA //
    /////////////////////
    FOR(i, 0, timeline.size()) {
        if (timeline[i].end - timeline[i].start > max1)
            max1 = timeline[i].end - timeline[i].start;

        if (i > 0 && timeline[i].start - timeline[i-1].end > max2)
            max2 = timeline[i].start - timeline[i-1].end;
    }

    /////////////////////
    // OUTPUTTING DATA //
    /////////////////////
    ofstream fout("milk2.out");
    fout << max1 << " " << max2 << endl;

    return 0;
}
