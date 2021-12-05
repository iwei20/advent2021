#include <bits/stdc++.h>
#include "../../advent_utils.hpp"
using namespace std;
using ll = long long;
using vi = vector<int>;

int main() {
    ifstream fin("../input.in");
    string s;
    
    bool part1 = false;
    vector<vector<int>> pipes(1000, vector<int>(1000));
    int count = 0;

    while(getline(fin, s)) {
        
        int a, b, c, d;
        sscanf(s.c_str(), "%i,%i -> %i,%i\n", &a, &b, &c, &d);

        int dx = (a < c) - (a > c);
        int dy = (b < d) - (b > d);
        
        if (part1 && abs(dx) == abs(dy)) continue;

        for (int i = a, j = b; ; i += dx, j += dy) {
            ++pipes[i][j];
            count += (pipes[i][j] == 2);
            if(i == c && j == d) break;
        }
    }
    
    cout << count << "\n";
    
}