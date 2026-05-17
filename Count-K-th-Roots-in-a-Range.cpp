1class Solution {
2public:
3    int countKthRoots(int l, int r, int k) {
4        if(k==1){
5            return r-l+1;
6        }else{
7            //brute forcing approach
8            //calculating till r then subtracting till l to get final answer
9            vector<int>v;
10            for(int i=0;i<=r;i++){
11                long long x=pow(i,k);
12                if(x>r)break;
13                v.push_back(x);
14            }
15            int count=0;
16            for(auto it:v){
17                if(it>=l && it<=r)count++;
18            }
19            return count;
20        }
21        return -1;
22    }
23};