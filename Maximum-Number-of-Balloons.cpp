1class Solution {
2public:
3    int maxNumberOfBalloons(string s) {
4        vector<int>fre(26,0);
5        for(int i=0;i<s.size();i++){
6            fre[s[i]-'a']++;
7        }
8        //balloon
9
10        int b=fre[1];
11        int a=min(b,fre[0]);
12        int l=min(a,fre['l'-'a']/2);
13        int o=min(l,fre['o'-'a']/2);
14        int n=min(o,fre['n'-'a']);
15
16        return n;
17    }
18};