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
    vector<int> crabs;
    ss >> crabs;

    int sum = 0;
    for (int c : crabs) {
        sum += c;
    }

    sort(crabs.begin(), crabs.end());
    int median = crabs[crabs.size() / 2];
    int sum_diffs = 0;
    for (int c : crabs) {
        sum_diffs += abs(c - median);
    }
    cout << median << "\n";
    cout << sum_diffs << "\n";
}