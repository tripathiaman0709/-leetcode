#define MOD 1000000007
#define MAX_NUM 100000

long long fact[MAX_NUM];
long long inv_fact[MAX_NUM];

class Solution {
private:
    long long qpow(long long x, int n) {    // x ^ n calculation
        long long res = 1;
        while (n) {
            if (n % 2 == 1) {
                res = (res * x) % MOD;
            }
            x = x * x % MOD;
            n /= 2;
        }
        return res;
    }
    long long comb(int n, int m) {
        // 1/fact[m] = inv_fact[m] => Fermet's Little Theorem
        // a^-1 = a^(p - 2) mod p
        // return fact[n]/fact[m] % MOD / fact[n - m] % MOD;
        return fact[n] * inv_fact[m] % MOD * inv_fact[n - m] % MOD;
    }
    void init() {
        if (fact[0]) {
            return;
        }

        fact[0] = 1;
        for (int i = 1; i < MAX_NUM; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        inv_fact[MAX_NUM - 1] = qpow(fact[MAX_NUM - 1], MOD - 2) % MOD;
        for (int i = MAX_NUM - 1; i > 0; i--) {
            inv_fact[i - 1] = inv_fact[i] * i % MOD;
        }
    }
public:
    int countGoodArrays(int n, int m, int k) {
        init();
        return comb(n - 1, k) * m % MOD * qpow(m - 1, n - 1 - k) % MOD;
    }
};

/*
    construction of array:
        - size: n
        - range: [1, m]
        - k adjacent pairs being equal

    n - 1 adjacent elements
        - equal pairs: k
        - remaining pairs: n - 1 - k
        => C(n - 1, n - 1 - k) = C(n - 1, k) 

    => m * C(n - 1, k) adjacent pairs (equal)
    => (m - 1)^(n - 1 - k) (non-equal)
    => total combination = m * C(n - 1, k) * (m - 1)^(n - 1 - k)

    Fermet's Little Theorem + Extened Inverse Modulo
    a^(p - 1) = 1 mod p ; p is prime no
    a^(p - 1) * a = a mod p
    a^(p - 2) = a mod p
*/