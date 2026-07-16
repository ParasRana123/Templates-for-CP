#include <bits/stdc++.h>
using namespace std;

class NTT {
    public:
       static const int MOD = 998244353;
       static const int G = 3;

        long long modPow(long long a , long long b) {
           long long res = 1;
           while(b) {
              if(b & 1) res = res * a % MOD;
              a = a * a % MOD;
              b >>= 1;
           }
           return res;
        }

        void ntt(vector<long long>& a, bool invert) {
            int n = a.size();
            for (int i = 1, j = 0; i < n; i++) {
                int bit = n >> 1;
                while (j & bit) {
                    j ^= bit;
                    bit >>= 1;
                }
                j ^= bit;
                if (i < j) swap(a[i], a[j]);
            }
            for (int len = 2; len <= n; len <<= 1) {
                long long wlen = modPow(G, (MOD - 1) / len);
                if (invert) wlen = modPow(wlen, MOD - 2);
                for (int i = 0; i < n; i += len) {
                    long long w = 1;
                    for (int j = 0; j < len / 2; j++) {
                        long long u = a[i + j];
                        long long v = a[i + j + len / 2] * w % MOD;
                        a[i + j] = (u + v) % MOD;
                        a[i + j + len / 2] = (u - v + MOD) % MOD;
                        w = w * wlen % MOD;
                    }
                }
            }
            if (invert) {
                long long inv_n = modPow(n, MOD - 2);
                for (auto &x : a) x = x * inv_n % MOD;
            }
        }

        vector<long long> multiply(vector<long long> &a , vector<long long> &b) {
            int sz = a.size() + b.size() - 1;
            int n = 1;
            while(n < sz) {
                n <<= 1;
            }
            a.resize(n);
            b.resize(n);
            ntt(a , false);
            ntt(b , false);
            for(int i = 0 ; i < n ; i++) {
                a[i] = a[i] * b [i] % MOD;
            }
            ntt(a , true);
            a.resize(sz);
            return a;
        }
};

int main() {
    vector<long long> A = {1 , 2 , 3};
    vector<long long> B = {4 , 5};
    NTT ntt;
    auto c = ntt.multiply(A , B);
    for(auto &x: c) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}