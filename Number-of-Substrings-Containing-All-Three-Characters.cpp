1class Solution {
2public:
3    int numberOfSubstrings(string s) {
4
5        int n = s.size();
6
7        vector<int> freq(3,0);
8
9        int left = 0;
10        int ans = 0;
11
12        for(int right=0; right<n; right++){
13
14            freq[s[right]-'a']++;
15
16            while(freq[0]>0 && freq[1]>0 && freq[2]>0){
17
18                ans += n-right;
19
20                freq[s[left]-'a']--;
21                left++;
22            }
23        }
24
25        return ans;
26    }
27};