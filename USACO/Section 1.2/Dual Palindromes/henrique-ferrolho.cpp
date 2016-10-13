/*
ID: henriqu13
PROG: dualpal
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

vector<unsigned int> convertToBase(unsigned int x, unsigned int Base) {
    vector<unsigned int> num;
    for(int i = 0;; i++) {
        num.insert(num.begin(), x % Base);
        x /= Base;
        if (x == 0)
            break;
    }
    return num;
}

bool isPal(vector<unsigned int> &num) {
    unsigned int size = num.size();
    FOR(i, 0, size/2) {
        if(num[i] != num[size-1-i])
            return false;
    }
    return true;
}

int main() {
    ///////////////////
    // READING INPUT //
    ///////////////////
    ifstream fin ("dualpal.in");
    unsigned int N, S;
    fin >> N >> S;

    ///////////////////////
    // INITIALIZING DATA //
    ///////////////////////
    vector<unsigned int> output, convertedNum;
    unsigned int palindromesCount;

    /////////////////////
    // PROCESSING DATA //
    /////////////////////
    while(output.size() < N) {
        ++S;
        palindromesCount = 0;
        FOR(i, 2, 11) {
            convertedNum = convertToBase(S, i);
            if (isPal(convertedNum)) {
                palindromesCount++;
                if (palindromesCount == 2) {
                    output.push_back(S);
                    break;
                }
            }
        }
    }

    /////////////////////
    // OUTPUTTING DATA //
    /////////////////////
    ofstream fout ("dualpal.out");
    FOR(i, 0, output.size())
        fout << output[i] << endl;

    return 0;
}
