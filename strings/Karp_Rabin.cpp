#include <bits/stdc++.h>
#include <cmath>
using namespace std;


static const int PRIME = 101;

int calculateHash(string s) {
    int hash = 0;
    int n = s.size();
    for(int i = 0 ; i < n ; i++) {
        hash = hash + s[i] * pow(PRIME , i);
    }
    return hash;
}

int updateHash(int prevHash , char oldChar , char newChar , int patternLength) {
    int newHash = (prevHash - oldChar) / PRIME;
    newHash = newHash + newChar * pow(PRIME , patternLength - 1);
    return newHash;
}

void search(string text , string pattern) {
    int patternLength = pattern.size();
    int patternHash = calculateHash(pattern);
    int textHash = calculateHash(text.substr(0 , patternLength));
    for(int i = 0 ; i <= text.size() - patternLength ; i++) {
        if(patternHash == textHash) {
            if(text.substr(i , patternLength) == pattern) {
                cout << "Match found at index: " << i << endl;
            }
        }
        if(i < text.size() - patternLength) {
            textHash = updateHash(textHash , text[i] , text[i + patternLength] , patternLength);
        }
    }
}

int main() {
    string s = "ParasAbc123";
    string p = "Abc";
    search(s , p);
    return 0;
}