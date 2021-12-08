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

    int count = 0;

    map<int, vector<int>> pos = {
        {0, {0, 1, 2, 4, 5, 6}},
        {1, {2, 5}},
        {2, {0, 2, 3, 4, 6}},
        {3, {0, 2, 3, 5, 6}},
        {4, {1, 2, 3, 5}},
        {5, {0, 1, 3, 5, 6}},
        {6, {0, 1, 3, 4, 5, 6}},
        {7, {0, 2, 5}},
        {8, {0, 1, 2, 3, 4, 5, 6}},
        {9, {0, 1, 2, 3, 5, 6}}
    };

    while(fin.good()) {
        vector<string> signals;
        for (int i = 0; i < 10; ++i) {
            string s;
            fin >> s;
            sort(s.begin(), s.end());
            signals.push_back(s);
        }
        string line;
        fin >> line;
        vector<string> output;
        for (int i = 0; i < 4; ++i) {
            string s;
            fin >> s;
            sort(s.begin(), s.end());
            output.push_back(s);
        }
        
        string perm = "abcdefg";
        map<string, int> to_num;
        do {

            map<string, int> temp_to_num;
            map<char, int> to_pos;

            for (int i = 0; i < perm.size(); ++i) {
                to_pos[perm[i]] = i;
                //cout << perm[i] << ":" << i << " ";
            }
            //cout << "\n";

            bool works = true;
            for (string s : signals) {
                bool found_this_s = false;
                vector<int> poos;
                
                for (char c : s) {
                    poos.push_back(to_pos[c]);
                }
                sort(poos.begin(), poos.end());
                for (int i = 0; i <= 9; ++i) {
                    if(pos[i] == poos) {
                        found_this_s = true;
                        temp_to_num[s] = i;
                    }
                }

                if (!found_this_s) works = false;
            }

            if(works) {
                to_num = temp_to_num;
            }
        } while(next_permutation(perm.begin(), perm.end()));    

        int result = 1000 * to_num[output[0]] + 100 * to_num[output[1]] + 10 * to_num[output[2]] + to_num[output[3]];
        count += result;
        cout << result << "\n";
    }

    cout << count;
}