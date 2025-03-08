class Solution {
public:
    static vector<int> isprime;
    static bool isSieveComputed;

    static void sieve() {
        if (isSieveComputed) return; // Prevent recomputation

        int N = 1000000;  // Set N to 1e6
        isprime.assign(N + 1, 1);  // Resize and initialize with 1
        isprime[0] = isprime[1] = 0;

        for (int i = 2; i * i <= N; i++) {
            if (isprime[i]) {
                for (int j = i * i; j <= N; j += i) {
                    isprime[j] = 0;
                }
            }
        }
        isSieveComputed = true;
    }

    vector<int> closestPrimes(int l, int r) {
        sieve();  // Compute sieve once

        vector<int> v;
        for (int i = l; i <= r; i++) {
            if (isprime[i]) v.push_back(i);
        }
        if (v.size() < 2) return {-1, -1};

        int num1 = v[0], num2 = v[1], diff = v[1] - v[0];
        for (int i = 1; i < v.size(); i++) {
            int differ = v[i] - v[i - 1];
            if (differ < diff) {
                diff = differ;
                num1 = v[i - 1];
                num2 = v[i];
            }
        }
        return {num1, num2};
    }
};

// Define static members
vector<int> Solution::isprime;
bool Solution::isSieveComputed = false;
