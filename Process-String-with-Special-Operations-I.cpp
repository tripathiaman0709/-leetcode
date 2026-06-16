1class Solution {
2public:
3    string processStr(string s) {
4        int n=s.size();
5        string ans="";
6
7        for(int i=0;i<n;i++){
8            if(s[i]!='*' && s[i]!='#' && s[i]!='%'){
9                ans+=s[i];
10            }else if(s[i]=='*' && ans.size()!=0){
11                ans.pop_back();
12            }else if(s[i]=='%' && ans.size()!=0){
13                reverse(ans.begin(),ans.end());
14            }else if(s[i]=='#' && ans.size()!=0){
15                string add=ans;
16                ans+=add;
17            } 
18        }
19        return ans;
20    }
21};