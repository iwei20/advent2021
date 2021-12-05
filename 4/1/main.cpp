#include <bits/stdc++.h>
#include "../../advent_utils.hpp"
using namespace std;
using ll = long long;
using vi = vector<int>;

class board {
    
    public: 
        int b[5][5];
        bool marked[5][5] = {{false}};
        int rows[5] = {0};
        int cols[5] = {0};
        
        void update(int num) {
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (b[i][j] == num) {
                        marked[i][j] = true;
                        ++rows[i];
                        ++cols[j];
                    }
                }
            }
        }
        bool winning() {
            for (int i : rows) {
                if(i == 5) return true;
            }
            for (int i : cols) {
                if(i == 5) return true;
            }
            return false;
        }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ifstream fin("../input.in");
    string s;
    fin >> s;
    replace( s.begin(), s.end(), ',', ' ');
    stringstream ss(s);

    vector<board> boards;
    int c;
    while(fin.good()) {
        board next;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                fin >> c;
                next.b[i][j] = c;
            }
        }
        boards.push_back(next);
    }

    int nextnum;
    int totalrow = 0;
    while(ss >> nextnum) {
        int winner = -1;
        for (int i = 0; i < boards.size(); ++i) {
            boards[i].update(nextnum);
            if(boards[i].winning()) winner = i;
        }
        if (winner != -1) {
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    cout << boards[winner].b[i][j] << " ";
                    if (!boards[winner].marked[i][j]) totalrow += boards[winner].b[i][j];
                }
                cout << "\n";
            }
            break;
        }
    }
    
    cout << nextnum << " " << totalrow << "\n";
    cout << nextnum * totalrow << "\n";
}