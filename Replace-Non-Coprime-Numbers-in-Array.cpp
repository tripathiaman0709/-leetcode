class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> v;
        for (int num : nums) {
            while (!v.empty()) {
                int top = v.back();
                int g = gcd(top,num);
                if (g == 1) {
                    break;
                }
                v.pop_back();
                long long merged = (long long)top / g * num;
                num = (int)merged;
            }
            v.push_back(num);
        }
        return v;
    }
    
private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};