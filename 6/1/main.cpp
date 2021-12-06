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
    string s;
    fin >> s;
    replace(s.begin(), s.end(), ',', ' ');

    stringstream ss(s);
    vector<int> fish;
    ss >> fish;

    for (int i = 0; i < 80; ++i) {
        for (int j = 0; j < fish.size(); ++j) {
            if (fish[j] == 0) {
                fish.push_back(9);
                fish[j] = 6;
            } else {
                --fish[j];
            }
        }
    }
    cout << fish.size();
}