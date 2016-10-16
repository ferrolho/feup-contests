#include <cmath>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// Custom types
typedef unsigned int ui;

// Globals
vector<vector<float>> originalData;
vector<vector<float>> newData;
vector<bool> assignedRows;

float diff(const vector<float>& row1, const vector<float>& row2) {
    float delta = 0;

    for (ui i = 0; i < row1.size(); i++)
        delta += abs(row1[i] - row2[i]);

    return delta;
}

int main() {
    ui k;
    cin >> k;

    string line;
    getline(cin, line);

    for (ui j = 0; j < 2; j++) {
        for (ui i = 0; i < k; i++) {
            getline(cin, line);
            stringstream ss(line);

            float val;
            vector<float> dataRow;

            while (ss >> val) {
                dataRow.push_back(val);

                if (ss.peek() == ',')
                    ss.ignore();
            }

            if (j == 0)
                originalData.push_back(dataRow);
            else
                newData.push_back(dataRow);
        }
    }

    assignedRows = vector<bool>(k);

    for (ui i = 0; i < k; i++) {
        int matchRow = -1;
        float minDiff;

        for (ui j = 0; j < k; j++) {
            if (assignedRows[j])
                continue;

            float rowsDiff = diff(originalData[i], newData[j]);

            if (rowsDiff < minDiff || matchRow == -1) {
                minDiff = rowsDiff;
                matchRow = j;
            }
        }

        assignedRows[matchRow] = true;

        cout << i << ',' << matchRow << endl;
    }

    return 0;
}
