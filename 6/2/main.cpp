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

    unordered_map<int, long long> fishcount;
    for (int foosh : fish) {
        ++fishcount[foosh];
    }

    for (int i = 0; i < 256; ++i) {
        long long tempreset = fishcount[0];
        for (int j = 0; j < 8; ++j) {
            fishcount[j] = fishcount[j + 1];
        }
        fishcount[8] = tempreset;
        fishcount[6] += tempreset;
    }
    long long sum = 0;
    for (int i = 0; i <= 8; ++i) {
        sum += fishcount[i];
    }
    cout << sum << "\n";
    cout << endl;
    
}