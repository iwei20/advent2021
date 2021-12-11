#include <bits/stdc++.h>
#include "../../advent_utils.hpp"
using namespace std;
using ll = long long;
using vi = vector<int>;

unordered_map<char, int> score = {
    {')', 3},
    {']', 57},
    {'}', 1197},
    {'>', 25137}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ifstream fin("../input.in");
    string s;

    int total = 0;
    while(fin >> s) {
        stack<char> b;
        for (char c : s) {
            if (c == ')' || c == ']' || c == '}' || c == '>') {
                if (b.size() <= 0) {
                    total += score[c];
                    break;
                }
                char top = b.top();
                b.pop();
                if (c == ')' && top != '(') {
                    total += score[c];
                    break;
                }
                if (c == ']' && top != '[') {
                    total += score[c];
                    break;
                }
                if (c == '}' && top != '{') {
                    total += score[c];
                    break;
                }
                if (c == '>' && top != '<') {
                    total += score[c];
                    break;
                }
            } else {
                b.push(c);
            }
        }
    }
    cout << total << "\n";
}