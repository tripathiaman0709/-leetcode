1class Solution {
2public:
3
4    bool check(int n){
5        //now finding all digits and checking if they divide the number n
6        vector<int>digits;
7        int x=n;
8        while(x){
9            digits.push_back(x%10);
10            x/=10;
11        }
12        //now checking divisibility
13        for(auto it:digits){
14            if(it==0)return false;
15            if(n%it)return false;
16        }
17        return true;
18    }
19
20    vector<int> selfDividingNumbers(int l, int r) {
21        //no need to precompute 
22        //had there been t test cases and it was a codeforces like problem then precomputation would have helped
23        vector<int>ans;
24        for(int i=l;i<=r;i++){
25            if(check(i))ans.push_back(i);
26        }
27        return ans;
28    }
29};