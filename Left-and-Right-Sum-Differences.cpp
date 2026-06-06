1class Solution {
2public:
3    vector<int> leftRightDifference(vector<int>& v) {
4        //simply making an array by prefix sum suffix sum
5        int n=v.size();
6        vector<int>ans;
7        vector<int>suff(n+1,0);
8
9        suff[n-1]=v[n-1];
10        for(int i=n-2;i>=0;i--){
11            suff[i]=suff[i+1]+v[i];
12        }
13
14        int presum=0;
15        // if(n==1){
16        //     return {0};
17        // }
18        for(int i=0;i<n;i++){
19            int val=abs(presum-suff[i+1]);
20            ans.push_back(val);
21            presum+=v[i];
22        }
23
24        return ans;
25    }
26};