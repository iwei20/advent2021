#include <bits/stdc++.h>
#include "../../advent_utils.hpp"
using namespace std;
using ll = long long;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ifstream fin("../input.in");
    vector<string> things;
    fin >> things;

    vector<int> count(things[0].size());

    string oxygen = "";
    string co2 = "";
    ll gamma = 0, eps = 0;
    for (int i = 0; i < count.size(); ++i) {
        ll ocount1 = 0, ocount0 = 0;
        for (int j = 0; j < things.size(); ++j) {
            if(things[j].substr(0, i) == oxygen) {
                if (things[j][i] == '1') ++ocount1;
                if (things[j][i] == '0') ++ocount0;
            }
        }
        cout << "Ox " << ocount1 << " " << ocount0 << "\n";
        if (ocount1 >= ocount0) {
            oxygen += '1';
        } else {
            oxygen += '0';
        }

    }
     for (int i = 0; i < count.size(); ++i) {
        ll ccount1 = 0, ccount0 = 0;
        for (int j = 0; j < things.size(); ++j) {
            if(things[j].substr(0, i) == co2) {
                if (things[j][i] == '1') ++ccount1;
                if (things[j][i] == '0') ++ccount0;
            }
        }
        cout << "CO2 " << ccount1 << " " << ccount0 << "\n";

        if (ccount1 + ccount0 == 1) {
            for (string j : things) {
                if(j.substr(0, i) == co2) co2 = j;
            }
            break;
        }
        if (ccount1 >= ccount0) {
            co2 += '0';
        } else {
            co2 += '1';
        }
    }

    cout << oxygen << endl;
    cout << co2 << endl;
    cout << stoi(oxygen, nullptr, 2) << "\n";
    cout << stoi(co2, nullptr, 2) << "\n";
    cout << stoi(oxygen, nullptr, 2) * stoi(co2, nullptr, 2) << "\n";
}