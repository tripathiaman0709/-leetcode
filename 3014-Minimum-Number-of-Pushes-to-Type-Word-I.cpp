class Solution {
public:
    int minimumPushes(string s) {

        vector<int> freq(26, 0);

        for(char c : s){
            freq[c - 'a']++;
        }

        sort(freq.rbegin(), freq.rend());

        int ans = 0;
        int a = 0, b = 0, c = 0, d = 0;

        for(int i = 0; i < 26; i++){

            if(freq[i] == 0){
                break;
            }

            if(a < 8){
                ans += freq[i];
                a++;
            }
            else if(b < 8){
                ans += 2 * freq[i];
                b++;
            }
            else if(c < 8){
                ans += 3 * freq[i];
                c++;
            }
            else{
                ans += 4 * freq[i];
                d++;
            }
        }

        return ans;
    }
};