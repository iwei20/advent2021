#include <bits/stdc++.h>
#include "../../advent_utils.hpp"
using namespace std;
using ll = long long;
using vi = vector<int>;

unordered_map<char, long long> score = {
    {')', 1},
    {']', 2},
    {'}', 3},
    {'>', 4}
};

unordered_map<char, char> rev = {
    {'(', ')'},
    {'[', ']'},
    {'{', '}'},
    {'<', '>'}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ifstream fin("../input.in");
    string s;

    vector<ll> totals;
    long long total = 0;
    while(fin >> s) {
        long long line_total = 0;
        stack<char> b;
        bool good_line = true;
        for (char c : s) {
            if (c == ')' || c == ']' || c == '}' || c == '>') {
                if (b.size() <= 0) {
                    good_line = false;
                    break;
                }
                char top = b.top();
                b.pop();
                if (c == ')' && top != '(') {
                    good_line = false;
                    break;
                }
                if (c == ']' && top != '[') {
                    good_line = false;
                    break;
                }
                if (c == '}' && top != '{') {
                    good_line = false;
                    break;
                }
                if (c == '>' && top != '<') {
                    good_line = false;
                    break;
                }
            } else {
                b.push(c);
            }
        }
        if(good_line) {
            while(b.size() > 0) {
                line_total *= 5;
                line_total += score[rev[b.top()]];
                b.pop();
            }
            totals.push_back(line_total);
            cout << line_total << "\n";
        }
    }
    sort(totals.begin(), totals.end());
    cout << totals[(totals.size() - 1) / 2] << "\n";
    cout << total << "\n";
}