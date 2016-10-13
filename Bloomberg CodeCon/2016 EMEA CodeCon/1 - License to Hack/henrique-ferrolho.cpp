#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    getline(cin, line);

    unsigned int N;
    cin >> N;

    //cout << N << endl;
    //cout << line << endl;

    for (unsigned int i = 0; i < line.size(); i += 2 * N) {
        auto end = line.begin() + i + N;

        if (i + N > line.size())
            end = line.end();

        reverse(line.begin() + i, end);
    }

    cout << line << endl;

    return 0;
}
