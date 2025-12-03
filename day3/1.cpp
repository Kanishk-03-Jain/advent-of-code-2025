#include <bits/stdc++.h>
using namespace std;
int main() {
    long long ans = 0;
    vector<int> a, b;
        string filename = "input.txt";
        ifstream inputFile(filename);
    
        string line;
        while (getline(inputFile, line)) { 
            // cout << line << endl;
            string maxi = line;
           string st;
           int torem = line.size() - 2;
           for (char c : line) {
                while (!st.empty() && torem > 0 && st.back() < c) {
                    st.pop_back();
                    torem--;
                }
                st.push_back(c);
           }
           string num = st.substr(0, 2);

           ans += stoll(num);
        }
    
        inputFile.close();

    cout << ans << endl;

}