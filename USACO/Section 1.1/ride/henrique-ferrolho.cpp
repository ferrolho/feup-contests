/*
ID: henriqu13
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // reading input
    ifstream fin ("ride.in");
    string comet, group;
    getline(fin, comet);
    getline(fin, group);

    // processing data
    int prod1, prod2;
    prod1 = prod2 = 1;
    for (unsigned int i = 0; i < comet.length(); i++) {
        prod1 *= comet[i] - 'A' + 1;
    }
    for (unsigned int i = 0; i < group.length(); i++) {
        prod2 *= group[i] - 'A' + 1;
    }

    // outputting data
    ofstream fout ("ride.out");
    if (prod1%47 == prod2%47)
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;

    return 0;
}
