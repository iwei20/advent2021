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
    for (string line : things) {
        for (int i = 0; i < line.size(); ++i) {
            count[i] += (line[i] == '1');
        }
    }

    cout << count << "\n";
    ll gamma = 0, eps = 0;
    for (int i = 0; i < count.size(); ++i) {
        if (count[i] > things.size() - count[i]) {
            ++gamma;
        } else {
            ++eps;
        }
        gamma *= 2;
        eps *= 2;
    }

    cout << gamma * eps / 4 << "\n";
}