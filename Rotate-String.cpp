1class Solution {
2public:
3    bool rotateString(string s, string goal) {
4        int n=s.size();
5        for(int i=0;i<n;i++){
6            string str="";
7            for(int j=0;j<n;j++){
8                str+=s[(i+j)%n];
9            }
10            if(str==goal)return true;
11        }
12        return false;
13    }
14};