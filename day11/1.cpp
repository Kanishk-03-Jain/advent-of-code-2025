#include <bits/stdc++.h>
using namespace std;
long long dfs(map<string, vector<string>> &adj, string curr) {
    if (curr == "out") return 1;
    long long ans = 0;
    for (string &child : adj[curr]) {
        ans += dfs(adj, child);
    }
    return ans;
}

int main() {
    map<string, vector<string>> adj;
    ifstream inputFile("input.txt");
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string word;
        vector<string> v;
        while (ss >> word) {
            v.push_back(word);
        }

        for (int i = 1; i < v.size(); i++) {
            adj[v[0].substr(0, v[0].size() - 1)].push_back(v[i]);
        }
    }
    cout << dfs(adj, "you") << endl;
}
