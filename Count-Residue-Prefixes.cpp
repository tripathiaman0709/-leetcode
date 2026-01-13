1class Solution {
2public:
3    int residuePrefixes(string s) {
4        int n=s.size();
5        vector<int>pre(n,0);
6        unordered_set<char>st;
7        for(int i=0;i<n;i++){
8            st.insert(s[i]);
9            pre[i]=st.size();
10        }
11        int ans=0;
12        for(int i=0;i<n;i++){
13            if(pre[i]==((i+1)%3)){
14                ans++;
15            }
16        }
17        return ans;
18    }
19};