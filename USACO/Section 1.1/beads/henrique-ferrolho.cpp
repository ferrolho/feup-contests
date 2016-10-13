/*
ID: henriqu13
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string printInfo(string str, vector<int> &vec) {
    stringstream ss;

    for (unsigned int i = 0; i < str.length(); i++) {
        ss << str[i] << " ";
    }
    ss << endl;

    for (unsigned int i = 0; i < vec.size(); i++) {
        ss << vec[i] << " ";
    }
    ss << endl;

    return ss.str();
}

int getMax(vector<int> &vec) {
    int max = -1;

    for (unsigned int i = 0; i < vec.size(); i++) {
        if (vec[i] > max)
            max = vec[i];
    }

    return max;
}

int main() {
    ///////////////////
    // reading input //
    ///////////////////
    ifstream fin ("beads.in");
    int N;
    fin >> N;
    string str, strReverse;
    fin >> str;
    str += str;

    ///////////////////////
    // initializing data //
    ///////////////////////
    vector<int> vec (2*N, 2);

    /////////////////////
    // processing data //
    /////////////////////
    char pivot;
    for (int cutPos = 0; cutPos < 2*N; cutPos++) {
        pivot = str[cutPos];
        for (int i = cutPos+1; i < 2*N; i++) {
            if (pivot == 'w') {
                if (str[i] != 'w') {
                    pivot = str[i];
                }

                vec[cutPos]++;
            } else if (pivot == str[i] || str[i] == 'w') {
                vec[cutPos]++;
            } else {
                break;
            }
        }
    }
    for (int cutPos = 2*N; cutPos >= 0; cutPos--) {
        pivot = str[cutPos-1];
        for (int i = cutPos-2; i >= 0; i--) {
            if (pivot == 'w') {
                if (str[i] != 'w') {
                    pivot = str[i];
                }

                if (cutPos == 2*N)
                    vec[0]++;
                else
                    vec[cutPos]++;
            } else if (pivot == str[i] || str[i] == 'w') {
                if (cutPos == 2*N)
                    vec[0]++;
                else
                    vec[cutPos]++;
            } else {
                break;
            }
        }
    }


    /////////////////////
    // outputting data //
    /////////////////////
    ofstream fout ("beads.out");
    //fout << printInfo(str, vec);
    int solution = getMax(vec);
    if (solution > N)
        solution = N;
    fout << solution << endl;

    return 0;
}
