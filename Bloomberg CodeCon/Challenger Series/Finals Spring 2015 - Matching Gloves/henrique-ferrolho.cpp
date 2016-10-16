#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

// Custom types
typedef unsigned int ui;

// Macros
#define ALL(v) (v).begin(), (v).end()

// Globals
set<string> unpairedGloves;

const bool isPalindrome(const string& str) {
    return str == string(str.rbegin(), str.rend());
}

int main() {
    ui n;
    cin >> n;

    ui count = 0;

    for (ui i = 0; i < n; i++) {
        string str;
        cin >> str;

        if (!isPalindrome(str)) {
            sort(ALL(str));

            if (unpairedGloves.find(str) != unpairedGloves.end()) {
                unpairedGloves.erase(str);
                count++;
            } else unpairedGloves.insert(str);
        }
    }

    if (unpairedGloves.empty())
        cout << count << endl;
    else
        cout << -1 << endl;

    return 0;
}
