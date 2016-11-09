/*
 ID: bmpj13
 PROG: The 3n+1 Problem
 LANG: C++11
 */


#include <unordered_map>
#include <chrono>
#include <iostream>

using namespace std;


typedef unordered_map<int, int> CycleLengthMap;
typedef unsigned long ul;





ul processCycleLength(ul number, CycleLengthMap& map) {
    ul candidate;
    ul cycleLength;


    if (number == 1)
        return 1;
    else if (number % 2 == 0)
        candidate = number/2;
    else
        candidate = 3*number + 1;


    auto search = map.find(candidate);
    if (search != map.end()) {
        cycleLength = 1 + map[candidate];
    }
    else {
        cycleLength = 1 + processCycleLength(candidate, map);
    }


    map.insert( {number, cycleLength} );
    return cycleLength;
}


ul solve(ul i, ul j) {
    CycleLengthMap map;
    ul max = 0;


    for (ul number = i; number <= j; number++) {
        ul cycleLength = processCycleLength(number, map);

        if (cycleLength > max) max = cycleLength;
    }

    return max;
}



int main() {
    ul i, j, max;

    while(cin >> i >> j) {

        if (i < j)
            max = solve(i, j);
        else
            max = solve(j, i);


        cout << i << ' ' << j << ' ' << max << endl;
    }

    return 0;
}
