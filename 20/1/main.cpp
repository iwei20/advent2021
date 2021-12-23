#include <bits/stdc++.h>
#include "../../advent_utils.hpp"
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define F0R(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)

const int ITERATIONS = 2;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ifstream fin("../input.in");
    string algo;
    fin >> algo;
    
    map<pii, bool> coords;
    string row;
    fin >> row;
    for(int i = 0; fin >> row; ++i) {
        F0R(j, row.size()) coords[{i, j}] = (row[j] == '#');
    }

    F0R(i, ITERATIONS) {
        map<pii, bool> nextcoords;
        
    }
}