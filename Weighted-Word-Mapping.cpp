1class Solution {
2public:
3    string mapWordWeights(vector<string>& v, vector<int>& w) {
4        int n=v.size();
5        string ans="";
6        // unordered_map<char,int>mpp;
7        // for(int i=0;i<26;i++){
8        //     mpp[i]=w[i];
9        // }
10        for(int i=0;i<n;i++){
11            string s=v[i];
12            int sum=0;
13            for(auto ch:s){
14                sum+=w[ch-'a'];
15            }
16            sum%=26;
17            ans+=(char(122-sum));
18        }
19        return ans;
20    }
21};