#include <iostream>
#include <map>
#include <set>
using namespace std;

// Custom types
typedef long long ll;
typedef unsigned int ui;

// Globals
set<char> unpaired;
map<char, ui> charPairToFreq;

ll factorial(ll n) {
    ll ans = 1;

    for (ll i = 2; i <= n; i++)
        ans *= i;

    return ans;
}

int main() {
    string str;
    cin >> str;

    for (char ch : str) {
        if (unpaired.find(ch) != unpaired.end()) {
            unpaired.erase(ch);
            charPairToFreq[ch]++;
        } else unpaired.insert(ch);
    }

    if (unpaired.size() > 1)
        cout << 0 << endl;
    else {
        ui freqSum = 0;
        ui denominator = 1;

        for (auto x : charPairToFreq) {
            freqSum += x.second;
            denominator *= factorial(x.second);
        }

        cout << factorial(freqSum) / denominator << endl;
    }

    return 0;
}
