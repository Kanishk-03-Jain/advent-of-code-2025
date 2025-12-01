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
            int rot = stoi(word.substr(1, word.size() - 1));
            int full = rot / 100;
            rot %= 100;
            int newpos = -1;
            if (word[0] == 'L') {
                newpos = (pos - rot + 100) % 100;
                if (pos != 0 && (newpos == 0 || newpos > pos)) {
                    cnt++;
                }
            } else {
                newpos = (pos + rot + 100) % 100;
                if (pos > newpos) {
                    cnt++;
                }
                
            }
            // cout<<word << endl;
            // cout << pos << " " << newpos << " " << cnt << endl;
            // if (newpos == 0 && pos != 0) cnt++;
            pos = newpos;

            
            cnt += full;
            
        }
    
        inputFile.close();

cout << cnt << endl;

}