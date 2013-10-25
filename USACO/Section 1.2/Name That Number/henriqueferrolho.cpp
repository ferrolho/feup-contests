/*
ID: henriqu13
PROG: namenum
LANG: C++
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef vector<int> vi;
#define FOR(i, a, b) for(unsigned int i = a; i < b; i++)

#define MAXDIGITS 13
char S[MAXDIGITS];

void incVec(vector<unsigned int> &vec, int digit) {
    vec[digit]++;
    if(vec[digit] > 2) {
        vec[digit] = 0;

        digit--;
        if (digit < 0)
            return;

        incVec(vec, digit);
    }
}

int main() {
    ///////////////////
    // READING INPUT //
    ///////////////////
    FILE *fin, *fout;
    fin = fopen("namenum.in", "r");
    fscanf(fin, "%s", S);

    fin = fopen("dict.txt", "r");
    char name[MAXDIGITS];

    string dict[5000];
    unsigned int pos = 0;
    while(fscanf(fin, "%s", name) != EOF) {
        dict[pos] = name;
        pos++;
    }

    unsigned int size = 0;
    string keysPressed[MAXDIGITS];
    for(unsigned int i = 0; S[i] != 0; i++) {
        switch (S[i]) {
            case '2': keysPressed[size]= "ABC"; break;
            case '3': keysPressed[size]= "DEF"; break;
            case '4': keysPressed[size]= "GHI"; break;
            case '5': keysPressed[size]= "JKL"; break;
            case '6': keysPressed[size]= "MNO"; break;
            case '7': keysPressed[size]= "PRS"; break;
            case '8': keysPressed[size]= "TUV"; break;
            case '9': keysPressed[size]= "WXY"; break;
        }
        size++;
    }

    ///////////////////////
    // INITIALIZING DATA //
    ///////////////////////
    unsigned int possibilitiesSize = pow(3, size);
    vector<string> output;

    /////////////////////
    // PROCESSING DATA //
    /////////////////////
    FOR(j, 0, pos) {
        vector<unsigned int> temp (size, 0);
        FOR(i, 0, possibilitiesSize) {
            FOR(k, 0, size) {
                name[k] = keysPressed[k][temp[k]];
            }
            name[size] = 0;

            if(name[0] == dict[j][0]) {
                if(name[1] == dict[j][1]) {
                    if(dict[j].compare(name) == 0) {
                        output.push_back(name);
                        break;
                    }
                } else {
                    incVec(temp, 1);
                    i += pow(3, size-2) - 1;
                    continue;
                }
            } else {
                incVec(temp, 0);
                i += pow(3, size-1) - 1;
                continue;
            }

            incVec(temp, size-1);
        }
    }

    /////////////////////
    // OUTPUTTING DATA //
    /////////////////////
    fout = fopen("namenum.out", "w");
    if (output.size() == 0) {
        fprintf(fout, "NONE\n");
    } else {
        FOR(i, 0, output.size())
            fprintf(fout, "%s\n", output[i].c_str());
    }

    return 0;
}
