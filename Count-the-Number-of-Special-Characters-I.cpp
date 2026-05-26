1class Solution {
2public:
3    int numberOfSpecialChars(string s) {
4        int n=s.size();
5        unordered_map<char,int>mpp;
6        for(auto it:s){
7            mpp[it]++;
8        }
9        int sum=0;
10        for(int i=0;i<n;i++){
11            if(s[i]>90){
12                continue;
13            }
14            int v1=mpp[s[i]];
15            int v2=mpp[s[i]+32];
16            if(v1 && v2){
17                sum++;
18            }
19            mpp[s[i]]=0;
20            mpp[s[i]+32]=0;
21        }
22        return sum;
23    }
24};