1class Solution {
2public:
3    string largestEven(string s) {
4        //if the last digit is odd we continuously remove it until we reach a even digit
5        int r=s.size()-1;
6        while(r>=0 && s[r]=='1'){
7            s[r]='?';
8            r--;
9        }
10
11        string ans="";
12        for(auto it:s){
13            if(it=='?'){
14                break;
15            }else{
16                ans+=it;
17            }
18        }
19        return ans;
20    }
21};