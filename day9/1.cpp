#include<bits/stdc++.h>
#include <chrono>
using namespace std;

#define ll long long

int main() {
    auto start = chrono::high_resolution_clock::now();
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
    ll ans = 0;
    for (int i = 0; i < points.size(); i++) {
        for (int j = 0; j < points.size(); j++) {
            ans = max(ans, (abs(points[i][0] - points[j][0]) + 1) * (abs(points[i][1] - points[j][1]) + 1));
        }
    }
    cout << ans << endl;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Time taken: " << elapsed.count() << " seconds\n";

}