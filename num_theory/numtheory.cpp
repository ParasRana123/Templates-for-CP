#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9 + 7;

// multiplies 2 matrices and returns the MOD value
vector<vector<int>> matMul(const vector<vector<int>> &A , const vector<vector<int>> &B) {
    int n = A.size() , m = B[0].size() , p = B.size();
    vector<vector<int>> ans(n , vector<int>(m , 0));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            for(int k = 0 ; k < p ; k++) {
                ans[i][j] = (ans[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return ans;
}

// checks if a number is prime or not
// optimizes using the (6k + 1) rule
bool isPrime(int n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(int i = 5 ; i * i <= n ; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Return all the prime number <= n
// TC: O(n log log n);
vector<int> seive(int n) {
    vector<int> primes;
    vector<int> isPrime(n + 1 , true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2 ; i * i <= n ; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = i * i ; j <= n ; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return primes;
}

// return all the factors of a number in sorted order
vector<int> allFactors(int n) {
    vector<int> small , large;
    for(int i = 1 ; i * i <= n ; i += (n & 1) ? 2 : 1) {
        if(n % i == 0) {
            small.push_back(i);
            if(i != n / i) large.push_back(n / i);
        }
    }
    reverse(large.begin() , large.end());
    small.insert(small.end() , large.begin() , large.end());
    return small;
}

int main() {
    
}