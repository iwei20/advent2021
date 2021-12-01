#include <bits/stdc++.h>
#include "../advent_utils.hpp"
using namespace std;
using ll = long long;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ifstream fin("bruh.in");
    int a, b, c;
    int curr;
    int count = 0;

    fin >> a >> b >> c;
    while(fin >> curr) {
        if (curr + b + c > a + b + c) {
            ++count;
        }
        a = b;
        b = c;
        c = curr;
    }
    cout << count;
    // cout << smanip::slice("Hello", -2, nullopt, -2) << "\n";
}