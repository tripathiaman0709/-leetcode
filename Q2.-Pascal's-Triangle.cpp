1class Solution {
2public:
3    vector<vector<int>> generate(int r) {
4        vector<int>curr(1,1);
5        vector<vector<int>>ans;
6        ans.push_back(curr);
7        while(r>1){
8            vector<int>newcurr(curr.size()+1,1);
9            for(int i=1;i<curr.size();i++){
10                newcurr[i]=curr[i-1]+curr[i];
11            }
12            ans.push_back(newcurr);
13            curr=newcurr;
14            r--;
15        }
16        return ans;
17    }
18};
19