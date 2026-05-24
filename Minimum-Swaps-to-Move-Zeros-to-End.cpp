1class Solution {
2public:
3    int minimumSwaps(vector<int>& v) {
4        int n=v.size();
5        int zero=0;
6        for(auto it:v){
7            if(it==0)zero++;
8        }
9
10        int count=0;
11        for(int i=n-1;i>=0;i--){
12            if(v[i]!=0 && zero>0){
13                count++;
14                zero--;
15            }
16            else if(v[i]==0){
17                zero--;
18            }
19        }
20        return count;
21    }
22};