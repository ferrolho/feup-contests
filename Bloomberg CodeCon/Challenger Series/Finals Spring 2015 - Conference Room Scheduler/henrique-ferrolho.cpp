#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// Custom types
typedef unsigned int ui;
typedef vector<ui> vui;
typedef vector<vector<ui>> vvui;

// Macros
#define ALL(v) (v).begin(), (v).end()

// Globals
ui n;
vector<vector<bool>> timeSlots;
vvui requests;

bool isBooking(const vui& request) {
    return request.size() == 3;
}

const char book(ui roomId, ui timeSlot, ui numOfSlots) {
    roomId--;
    timeSlot--;

    for (ui i = timeSlot; i < timeSlot + numOfSlots; i++) {
        if (timeSlots[i][roomId])
            return 'N';
    }

    for (ui i = timeSlot; i < timeSlot + numOfSlots; i++)
        timeSlots[i][roomId] = true;

    return 'Y';
}

const vui query(ui timeSlot, ui numOfSlots) {
    timeSlot--;

    vui roomsAvailable;

    for (ui i = 0; i < n; i++) {
        bool free = true;

        for (ui j = timeSlot; j < timeSlot + numOfSlots; j++) {
            if (timeSlots[j][i]) {
                free = false;
                break;
            }
        }

        if (free)
            roomsAvailable.push_back(i + 1);
    }

    return roomsAvailable;
}

int main() {
    cin >> n;

    timeSlots = vector<vector<bool>>(32, vector<bool>(n));

    string line;
    getline(cin, line);

    while (getline(cin, line)) {
        stringstream ss(line);
        ui x;

        vui request;

        while (ss >> x) {
            request.push_back(x);

            if (ss.peek() == '-')
                ss.ignore();
        }

        requests.push_back(request);
    }

    for (auto request : requests) {
        if (isBooking(request)) {
            ui roomId     = request[0];
            ui timeSlot   = request[1];
            ui numOfSlots = request[2];

            cout << book(roomId, timeSlot, numOfSlots) << endl;
        } else {
            ui timeSlot   = request[0];
            ui numOfSlots = request[1];

            vui roomsAvailable = query(timeSlot, numOfSlots);

            if (roomsAvailable.empty())
                cout << "None" << endl;
            else {
                for (ui i = 0; i < roomsAvailable.size(); i++) {
                    cout << roomsAvailable[i];

                    if (i < roomsAvailable.size() - 1)
                        cout << " ";
                }

                cout << endl;
            }
        }
    }

    return 0;
}
