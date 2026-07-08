// Digit DP:
// In this we process we process digit by digit instead ofnumber by number
// because then the time complexity will be less.

// Question is:
// You are given three integers l, r and k.
// A number is considered good if the absolute difference between every pair of adjacent digits is at most k.
// Return the number of good integers in the range [l, r] (inclusive).
// The absolute difference between values x and y is defined as abs(x - y).

#include <bits/stdc++.h>
using namespace std;

string s;
long long dp[16][11][2][2];

long long f(int k , int pos , int prev , int started , int tight) {
    if(pos == s.size()) return 1;
    if(dp[pos][prev][started][tight] != -1) return dp[pos][prev][started][tight];
    long long ans = 0;
    int limit = tight ? (s[pos] - '9') : 9;
    for(int d = 0 ; d <= limit ; d++) {
        int nt = tight && (d == limit);
        if(!started && d == 0) {
            ans += f(k , pos + 1 , 10 , 0 , nt);
        } else {
            if(!started || abs(d - prev) <= k) {
                ans += f(k , pos + 1 , d , 1 , nt);
            }
        }
    }
    return dp[pos][prev][started][tight] = ans;
}

long long solve(long long x , int k) {
    if(x < 0) return 0;
    s = to_string(x);
    memset(dp , -1 , sizeof(dp));
    return f(k , 0 , 10 , 0 , 1);
}

void main() {
    long long l , r , k;
    cin >> l >> r >>  k;
    long long res = solve(r , k) - solve(l - 1 , k);
    cout << res << endl;
}