#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<unsigned int> vui;
#define FOR(i, a, b) for(unsigned int i = a; i < b; i++)
#define ALL(v) (v).begin(), (v).end()
#define foreach(v, it) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

string n1, n2, n3, n4;

int charToNum(char ch) {
    if('0' <= ch && ch <= '9')
        return ch - '0';
    else if ('A' <= ch && ch <= 'Z')
        return 10 + ch - 'A';
    else
        return -1;
}

unsigned int convertFromBase(unsigned int base, string str) {
    unsigned int num = 0;

    FOR(i, 0, str.size())
    num = num * base + charToNum(str[i]);

    return num;
}

int getStartBase() {
    int base = 1;
    FOR(i, 0, n1.size())
    if (charToNum(n1[i]) > base)
        base = charToNum(n1[i]);

    FOR(i, 0, n2.size())
    if (charToNum(n2[i]) > base)
        base = charToNum(n2[i]);

    FOR(i, 0, n3.size())
    if (charToNum(n3[i]) > base)
        base = charToNum(n3[i]);

    FOR(i, 0, n4.size())
    if (charToNum(n4[i]) > base)
        base = charToNum(n4[i]);

    return base;
}

int main() {
    // reading input
    cin >> n1 >> n2 >> n3 >> n4;

    unsigned int base = 2;
    FOR(i, getStartBase()+1, 37) {
        //cout << "\nBase: " << i << endl;
        //cout << convertFromBase(i, n1) + convertFromBase(i, n2) << " == " << convertFromBase(i, n3) * convertFromBase(i, n4) << endl;
        if(convertFromBase(i, n1) + convertFromBase(i, n2) == convertFromBase(i, n3) * convertFromBase(i, n4)) {
            base = i;
            break;
        }
    }

    // outputting data
    cout << base << endl;

    return 0;
}
