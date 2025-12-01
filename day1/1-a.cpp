#include <bits/stdc++.h>
using namespace std;
int main() {
    int pos = 50;
    int cnt = 0;
    vector<int> a, b;
        string filename = "input1.txt";
        ifstream inputFile(filename);
    
        string line;
        while (getline(inputFile, line)) { 
            istringstream lineStream(line);
            string word;
    
            lineStream >> word;
            
            if (word[0] == 'L') {
                pos = (pos - stoi(word.substr(1, word.size() - 1)) + 100) % 100;
            } else {
                pos = (pos + stoi(word.substr(1, word.size() - 1)) + 100) % 100;
            }

            if (pos == 0) cnt++;
        }
    
        inputFile.close();

cout << cnt << endl;

}