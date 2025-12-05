#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<long long, long long>> ranges;
    bool flag = true;
    long long cnt = 0;

    string filename = "input.txt";
    ifstream inputFile(filename);

    string line;
    while (getline(inputFile, line)) { 
        if (line == "") {
            flag = false;
            continue;
        }
        if (flag) {
            vector<long long> v;
            string num;
            istringstream numstream(line);
            while (getline(numstream, num, '-')) {
                v.push_back(stoll(num));
            }
            cout << v[0] << " " << v[1] << endl;
            ranges.push_back({v[0], v[1]});
        } else {
            
            long long curr = stoll(line);
            for (auto [l, r] : ranges) {
                if (l <= curr && r >= curr) {
                    cnt++;
                    break;
                }
            }
        }
    }
    inputFile.close();
    cout << cnt << endl;
}