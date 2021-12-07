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

    //sort(crabs.begin(), crabs.end());

    long long min_res = LLONG_MAX;
    
    for (int i = 0; i < 5000; ++i) {
        long long sum_diffs = 0;
        for (int c : crabs) {
            long long n = abs(c - i);
            sum_diffs += n * (n + 1) / 2;
            //cout << n * (n + 1) / 2 << "\n";
        }
        min_res = min(min_res, sum_diffs);
        //cout << "\n";
    }
    cout << min_res << "\n";
}