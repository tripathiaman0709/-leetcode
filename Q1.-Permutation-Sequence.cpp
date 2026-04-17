1class Solution {
2public:
3    string getPermutation(int n, int k) {
4        string s="";
5
6        for(int i=1;i<=n;i++){
7            s.push_back(i+48);
8        }
9        int count=0;
10        do {
11            count++;
12            if(count==k){
13                return s;
14            }
15        } while (next_permutation(s.begin(), s.end()));
16
17        return "";
18    }
19};