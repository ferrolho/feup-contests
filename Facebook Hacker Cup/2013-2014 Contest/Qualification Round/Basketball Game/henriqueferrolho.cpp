#include "stdio.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<unsigned int> vui;
#define PB push_back
#define FOR(i, a, b) for(unsigned int i = a; i < b; i++)
#define ALL(v) (v).begin(), (v).end()
#define foreach(v, it) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++ )

struct Player {
	string name;
	ui shotP;
	ui height;

	ui draft;
	ui time;
};

bool operator >(Player &pl1, Player &pl2) {
	if (pl1.shotP != pl2.shotP)
		return (pl1.shotP > pl2.shotP);
	else return (pl1.height > pl2.height);
}

Player getOut(vector<Player> &vec) {
	int pos = 0;
	Player temp = vec[pos];
	FOR(i, 1, vec.size()) {
		if(vec[i].time > temp.time) {
			temp = vec[i];
			pos = i;
		} else if (vec[i].time == temp.time && vec[i].draft > temp.draft) {
			temp = vec[i];
			pos = i;
		}
	}
	vec.erase(vec.begin() + pos);
	return temp;
}

Player getIn(vector<Player> &vec) {
	int pos = 0;
	Player temp = vec[pos];
	FOR(i, 1, vec.size()) {
		if(vec[i].time < temp.time) {
			temp = vec[i];
			pos = i;
		} else if (vec[i].time == temp.time && vec[i].draft < temp.draft) {
			temp = vec[i];
			pos = i;
		}
	}
	vec.erase(vec.begin() + pos);
	return temp;
}

int main() {
	// initializing data
	ui T, N, M, P;
	string name;
	ui shotP, height;
	vector<Player> players, team1, team2;
	vector<Player> team1Bench, team2Bench;

	cin >> T;
	FOR(t, 0, T) {
		// reading input
		cin >> N >> M >> P;
		players.clear();
		FOR(n, 0, N) {
			cin >> name >> shotP >> height;

			Player temp;
			temp.name = name;
			temp.shotP = shotP;
			temp.height = height;
			temp.time = 0;

			bool inserted = false;
			FOR(i, 0, players.size()) {
				if (temp > players[i]) {
					players.insert(players.begin() + i, temp);
					inserted = true;
					break;
				}
			}
			if (!inserted)
				players.PB(temp);
		}
		FOR(i, 0, N)
			players[i].draft = i+1;
		
		// processing input
		team1.clear();
		team2.clear();
		team1Bench.clear();
		team2Bench.clear();
		FOR(i, 0, N) {
			if (i%2) team2Bench.PB(players[i]);
			else team1Bench.PB(players[i]);
		}

		FOR(i, 0, P) {
			team1.PB(team1Bench[0]);
			team1Bench.erase(team1Bench.begin());

			team2.PB(team2Bench[0]);
			team2Bench.erase(team2Bench.begin());
		}

		Player in, out;
		FOR(m, 0, M) {
			FOR(i, 0, P) {
				team1[i].time++;
				team2[i].time++;
			}

			if (team1Bench.size() != 0) {
				out = getOut(team1);
				in = getIn(team1Bench);
				team1Bench.PB(out);
				team1.PB(in);
			}

			if (team2Bench.size() != 0) {
				out = getOut(team2);
				in = getIn(team2Bench);
				team2Bench.PB(out);
				team2.PB(in);
			}
		}
		vector<string> result;
		FOR(i, 0, P) {
			result.PB(team1[i].name);
			result.PB(team2[i].name);
		}
		sort(ALL(result));

		// outputting data
		printf("Case #%d:", t+1);
		FOR(i, 0, 2*P)
			cout << " " << result[i];
		printf("\n");
	}

	return 0;
}