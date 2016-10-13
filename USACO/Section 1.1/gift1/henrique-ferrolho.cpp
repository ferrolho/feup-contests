/*
ID: henriqu13
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Account {
    string name;
    int money;
};

void displayPeopleAccounts(vector<Account> &vec) {
    for (unsigned int i = 0; i < vec.size(); i++) {
        cout << vec[i].name << " " << vec[i].money << endl;
    }
    cout << endl;
}

void deposit(int amount, string name, vector<Account> &vec) {
    for (unsigned int i = 0; i < vec.size(); i++) {
        if (vec[i].name.compare(name) == 0) {
            vec[i].money += amount;
            break;
        }
    }
}

int main() {
    // reading input
    ifstream fin ("gift1.in");

    int NP;
    fin >> NP;

    string personName;
    vector<Account> people;
    Account temp;
    temp.money = 0;
    for (int i = 0; i < NP; i++) {
        fin >> temp.name;
        people.push_back(temp);
    }
    //displayPeopleAccounts(people);

    // processing data
    int amount, divider;
    for (int i = 0; i < NP; i++) {
        fin >> personName;
        //cout << "test: " << personName << endl;

        for (unsigned int j = 0; j < NP; j++) {
            // found person
            if (people[j].name.compare(personName) == 0) {
                fin >> amount >> divider;
                //cout << "divider: " << divider << endl;

                people[j].money -= amount;
                if (divider != 0)
                    people[j].money += amount%divider;

                for (int k = 0; k < divider; k++) {
                    fin >> personName;
                    //cout << "test2: " << personName << endl;

                    deposit(amount/divider, personName, people);
                }

                break;
            }
        }
        //displayPeopleAccounts(people);
    }

    // outputting data
    ofstream fout ("gift1.out");
    for (unsigned int i = 0; i < NP; i++) {
        fout << people[i].name << " " << people[i].money << endl;
    }

    return 0;
}
