1class Solution {
2public:
3    int countBinarySubstrings(string s) {
4        int n=s.size();
5        int cur=1;
6        int pre=0;
7        int ans=0;
8        for(int i=1;i<n;i++){
9            if(s[i]==s[i-1]) cur++;
10            else{
11                int x=min(cur,pre);
12                ans+=x;
13                pre=cur;
14                cur=1;
15            } 
16        }
17        return ans+min(cur,pre);
18    }
19};