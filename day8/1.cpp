#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int points_to_merge = 1000 - 1;
    ifstream inputFile("input.txt");
    string line;
    vector<vector<ll>> points;

    while (getline(inputFile, line)) { 
        istringstream lineStream(line);
        string coord;
        vector<ll> point;

        while (getline(lineStream, coord, ',')) {
            point.push_back(stoll(coord));
        }
        points.push_back(point);
    }

    priority_queue<
                    pair<ll, pair<vector<ll>, vector<ll>>>, 
                    vector<pair<ll, pair<vector<ll>, vector<ll>>>>,
                    greater<pair<ll, pair<vector<ll>, vector<ll>>>>
                > pq;
                
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            pq.push({
                (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + 
                (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]) + 
                (points[i][2] - points[j][2]) * (points[i][2] - points[j][2]),
                {
                    points[i],
                    points[j]
                }
            });
        }
    }

    vector<set<vector<ll>>> connections;

    for (vector<ll> point : points) {
        set<vector<ll>> st;
        st.insert(point);
        connections.push_back(st);
    }

    while (!pq.empty() && points_to_merge--) {
        pair<ll, pair<vector<ll>, vector<ll>>> ptop = pq.top();
        vector<ll> p1 = ptop.second.first, p2 = ptop.second.second;
        // cout << ptop.first << endl;
        // cout << p1[0] << " " << p1[1] << " " << p1[2] << endl; 
        // cout << p2[0] << " " << p2[1] << " " << p2[2] << endl; 
        // cout << endl;
        pq.pop();

        int idx1 = -1, idx2 = -1;
        for (int i = 0; i < connections.size(); i++) {
            if (connections[i].find(p1) != connections[i].end()) {
                idx1 = i;
            }
            if (connections[i].find(p2) != connections[i].end()) {
                idx2 = i;
            }
        }

        if (idx1 == idx2) continue;

        set<vector<ll>> merged = connections[idx1];
        merged.insert(connections[idx2].begin(), connections[idx2].end());

        if (idx1 > idx2) swap(idx1, idx2);

        connections.erase(connections.begin() + idx2);
        connections.erase(connections.begin() + idx1);

        connections.push_back(merged);
    }
    
    sort(connections.begin(), connections.end(), [](set<vector<ll>> &a1, set<vector<ll>> &a2) {
        return a1.size() > a2.size();
    }); 

    ll answer = 1;
    for (int i = 0; i < min(3, (int)connections.size()); i++) {
        cout << connections[i].size() <<endl;
        answer *= connections[i].size();
    }
    cout << answer << endl;
}