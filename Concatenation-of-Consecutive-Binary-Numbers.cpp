1class Solution {
2 public:
3  int concatenatedBinary(int n) {
4    constexpr int kMod = 1'000'000'007;
5    long ans = 0;
6
7    for (int i = 1; i <= n; ++i)
8      ans = ((ans << numberOfBits(i)) % kMod + i) % kMod;
9
10    return ans;
11  }
12
13 private:
14  int numberOfBits(int n) {
15    return log2(n) + 1;
16  }
17};