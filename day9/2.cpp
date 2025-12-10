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
        for (int j = i + 1; j < points.size(); j++) {
            ll minX = min(points[i][0], points[j][0]);
            ll minY = min(points[i][1], points[j][1]);
            ll maxX = max(points[i][0], points[j][0]);
            ll maxY = max(points[i][1], points[j][1]);

            bool valid = true;
            for (int k = 0; k < points.size(); k++) {
                // check if the boundaries are intersecting
                ll currX = points[k][0], currY = points[k][1];
                ll nexX = points[(k + 1)%points.size()][0], nexY = points[(k + 1)%points.size()][1];

                if (!(
                    minX >= max(currX, nexX) || 
                    maxX <= min(currX, nexX) || 
                    minY >= max(currY, nexY) || 
                    maxY <= min(currY, nexY))) {
                    valid = false;
                    break;
                }
                
            }
            if (valid)
                ans = max(ans, (abs(points[i][0] - points[j][0]) + 1) * (abs(points[i][1] - points[j][1]) + 1));
        }
    }
    cout << ans << endl;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << "Time taken: " << elapsed.count() << " seconds\n";
}