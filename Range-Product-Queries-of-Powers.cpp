class Solution {
public:
    const int MOD = 1e9 + 7;
    
    vector<int> productQueries(int n, vector<vector<int>>& q) {
        vector<int> v; // store powers of 2 from n
        int power = 1;
        
        for (int i = 0; i < 31; i++) { 
            if (n & (1 << i)) {
                v.push_back(1 << i); // store this power of 2
            }
        }
        
        // prefix product modulo MOD
        vector<long long> pre(v.size());
        pre[0] = v[0] % MOD;
        for (int i = 1; i < v.size(); i++) {
            pre[i] = (pre[i-1] * v[i]) % MOD;
        }
        
        vector<int> ans;
        for (auto &query : q) {
            int l = query[0], r = query[1];
            if (l == 0) {
                ans.push_back(pre[r]);
            } else {
                // Modular inverse for division
                long long inv = modPow(pre[l-1], MOD-2, MOD);
                ans.push_back((pre[r] * inv) % MOD);
            }
        }
        return ans;
    }
    
    long long modPow(long long base, long long exp, long long mod) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }
};
