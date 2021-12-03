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
    string d;
    int horiz = 0;
    int height = 0;
    int aim = 0;
    while (fin >> d) {
        int n;
        fin >> n;
        if (d == "forward") {
            horiz += n;
            height += aim * n;
        }
        if (d == "up") aim -= n;
        if (d == "down") aim += n;
    }
    cout << height * horiz << "\n";
}