class Solution {
public:
    int minSwaps(string s) {
        int ans = 0, count = 0;
        for(char c : s){
            if (c == '[') count++;
            else if(c == ']' and count > 0) count --;
        }
        ans = (count+1)/2;
        return ans;
    }
};