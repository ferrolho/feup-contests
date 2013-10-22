/*
ID: henriqu13
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef vector<int> vi;
#define FOR(i, a, b) for(unsigned int i = a; i < b; i++)

unsigned int B;
ofstream fout ("palsquare.out");

void convertToBaseAndPrint(unsigned int x) {
    vector<unsigned int> num;
    for(int i = 0;;i++) {
        num.insert(num.begin(), x%B);
        x /= B;
        if (x == 0)
            break;
    }
    FOR(i, 0, num.size()) {
        if(num[i] >= 10)
            fout << (char)('A' + num[i] - 10);
        else
            fout << num[i];
    }
}

bool isPal(unsigned int x) {
    vi digits;

    // placing digits on a vec
    while(1) {
        digits.insert(digits.begin(), x%B);
        if (x/B == 0)
            break;
        x /= B;
    }

    unsigned int size = digits.size();
    FOR(i, 0, size/2) {
        if(digits[i] != digits[size-1-i])
            return false;
    }

    return true;
}

int main() {
    // reading input
    ifstream fin ("palsquare.in");
    fin >> B;

    // processing data
    unsigned int square;
    FOR(i, 1, 301) {
        square = i*i;
        if (isPal(square)) {
            convertToBaseAndPrint(i); fout << " "; convertToBaseAndPrint(square); fout << endl;
        }
    }

    return 0;
}
