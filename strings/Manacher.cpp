// Manacher's Algo:
// Manacher's Algorithm finds the length of the longest palindrome centered at every possible position in a string in O(n) time.

#include <bits/stdc++.h>
using namespace std;

struct Manacher {
    string t;
    vector<int> p;

    void runManacher() {
        int n = t.size();
        p.assign(n , 0);
        int l = 1 , r = 1;
        for(int i = 1 ; i < n - 1 ; i++) {
            if(i < r) {
                p[i] = min(r - i , p[l + r - i]);
            }
            while(t[i + p[i] + 1] == t[i - p[i] - 1]) {
                p[i]++;
            }
            if(i +p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
    };

    void buildManacher(string &s) {
        t.clear();
        t.push_back('@');
        for(char c: s) {
            t.push_back('#');
            t.push_back(c);
        }
        t += "#$";
    }

    void print() {
        for(int i = 0 ; i < p.size() ; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
    }

};

void main() {
    string s = "abacaba";
    Manacher M;
    M.buildManacher(s);
    M.runManacher();
    M.print();
}