1class Solution {
2public:
3    char nextGreatestLetter(vector<char>& v, char ch) {
4        int n=v.size();
5        for(int i=0;i<n;i++){
6            char x=v[i];
7            if(x>ch){
8                return x;
9            }
10        }
11        return v[0];
12    }
13};