#include <bits/stdc++.h>
using namespace std;
int main() {
    long long ans = 0;
    vector<string> grid;
    string filename = "input.txt";
    ifstream inputFile(filename);

    string line;
    while (getline(inputFile, line)) { 
        grid.push_back("."+line+".");
    }
    inputFile.close();
    grid.insert(grid.begin(), string(grid[0].size(), '.'));
    grid.push_back(string(grid[0].size(), '.'));
    int m = grid.size(), n = grid[0].size();
    for (int i = 1; i < m - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (grid[i][j] == '.') continue;
            int neigh = (grid[i - 1][j] == '@')
                        + (grid[i + 1][j] == '@')
                        + (grid[i][j - 1] == '@')
                        + (grid[i][j + 1] == '@')
                        + (grid[i - 1][j - 1] == '@')
                        + (grid[i - 1][j + 1] == '@')
                        + (grid[i + 1][j - 1] == '@')
                        + (grid[i + 1][j + 1] == '@');
            if (neigh < 4) {
                ans++;
            }
                        
        }
    }
    cout << ans << endl;

}