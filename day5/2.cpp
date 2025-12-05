#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<long long, long long>> ranges;
    long long cnt = 0;

    string filename = "input.txt";
    ifstream inputFile(filename);

    string line;
    while (getline(inputFile, line)) {
        if (line == "") break;
        vector<long long> v;
        string num;
        istringstream numstream(line);
        while (getline(numstream, num, '-')) {
            v.push_back(stoll(num));
        }
        ranges.push_back({v[0], v[1]});
    }

    sort(ranges.begin(), ranges.end());
    cnt += ranges[0].second - ranges[0].first + 1;
    long long maxe = ranges[0].second;
    for (int i = 1; i < ranges.size(); i++) {
        if (maxe >= ranges[i].second) {
            continue;
        } else if (maxe >= ranges[i].first) {
            cnt += ranges[i].second - maxe;
        } else {
            cnt += ranges[i].second - ranges[i].first + 1;
        }
        maxe = max(maxe, ranges[i].second);
    }
    inputFile.close();
    cout << cnt << endl;
}