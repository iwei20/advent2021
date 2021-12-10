#include <bits/stdc++.h>
#include "../../advent_utils.hpp"
using namespace std;
using ll = long long;
using vi = vector<int>;

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

int basin_size(vector<vector<int>>& hmap, vector<vector<bool>>& visited, int i, int j) {
    if(hmap[i][j] == INT_MAX || visited[i][j] || hmap[i][j] == 9) return 0;
    visited[i][j] = true;
    int result = 1;
    for (int k = 0; k < 4; ++k) {
        result += basin_size(hmap, visited, i + dx[k], j + dy[k]);
    }
    return result;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ifstream fin("../input.in");
    string s;
    
    
    vector<vector<int>> heightmap;
    while(fin >> s) {
        vector<int> row;
        row.push_back(INT_MAX);
        for (char c : s) {
            row.push_back(c - '0');
        }
        row.push_back(INT_MAX);
        heightmap.push_back(row);
    }
    vector<int> bruh1, bruh2;
    for (int i = 0; i < heightmap[0].size(); ++i) {
        bruh1.push_back(INT_MAX);
        bruh2.push_back(INT_MAX);        
    }
    heightmap.insert(heightmap.begin(), bruh1);
    heightmap.push_back(bruh2);

    vector<vector<bool>> awesome(heightmap.size(), vector<bool>(heightmap[0].size()));

    // Part 1
    int count = 0;
    for (int i = 1; i < heightmap.size() - 1; ++i) {
        for (int j = 1; j < heightmap[0].size() - 1; ++j) {
            bool works = true;
            for (int k = 0; k < 4; ++k) {
                if(heightmap[i + dx[k]][j + dy[k]] <= heightmap[i][j]) works = false;
            }
            awesome[i][j] = works;
            if (works) count += heightmap[i][j] + 1;
        }
    }
    
    // Part 2
    vector<int> sizes;
    vector<vector<bool>> visited(heightmap.size(), vector<bool>(heightmap[0].size()));
    for (int i = 1; i < heightmap.size() - 1; ++i) {
        for (int j = 1; j < heightmap[0].size() - 1; ++j) {
            if(awesome[i][j]) sizes.push_back(basin_size(heightmap, visited, i, j));
        }
    }
    sort(sizes.begin(), sizes.end());
    int prod = 1;
    for (int i = sizes.size() - 1; i >= sizes.size() - 3; --i) {
        prod *= sizes[i];
    }
    cout << sizes << "\n";
    cout << prod;
}


