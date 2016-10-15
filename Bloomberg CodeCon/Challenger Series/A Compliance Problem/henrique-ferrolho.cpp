#include <iostream>
#include <set>
using namespace std;

// Globals
set<char> toPair;

int main() {
    string str;
    cin >> str;

    while (!str.empty()) {
        char tail = str.back();

        if (toPair.find(tail) != toPair.end())
            toPair.erase(tail);
        else
            toPair.insert(tail);

        str.pop_back();
    }

    if (toPair.empty() || toPair.size() == 1)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}
