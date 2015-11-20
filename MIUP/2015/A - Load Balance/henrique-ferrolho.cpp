#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

typedef unsigned int ui;

const int N = 1000;
int totalRequestsReceived[N];
int ratios[N], requests[N];
bool status[N];

void startServers() {
	for (ui i = 0; i < N; i++)
		status[i] = true;
}

void toggleStatus(int server) {
	status[server] = !status[server];
	requests[server] = 0;
}

int main() {
	startServers();

	ui n;
	cin >> n;

	for (ui i = 0; i < n; i++)
		cin >> ratios[i];

	ui m;
	cin >> m;

	int worker = 0; // server currently handling requests
	for (ui i = 0; i < m; i++) {
		string str;
		cin >> str;

		if (str == "S") {
			cin >> str;

			toggleStatus(atoi(str.c_str()) - 1);
		} else {
			int incomingRequests = atoi(str.c_str());

			while (incomingRequests > 0) {
				// if worker can still handle more requests
				if (status[worker] && requests[worker] < ratios[worker]) {
					int accepted = min(incomingRequests,
							ratios[worker] - requests[worker]);

					requests[worker] += accepted;
					totalRequestsReceived[worker] += accepted;

					incomingRequests -= accepted;
				} else {
					requests[worker] = 0;
					worker = (worker + 1) % n;
				}
			}
		}
	}

	for (ui i = 0; i < n; i++)
		cout << totalRequestsReceived[i] << endl;

	return 0;
}
