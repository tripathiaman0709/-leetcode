1class Solution {
2public:
3    vector<int> findValidElements(vector<int>& v) {
4        int n=v.size();
5        //checking for each element and storing them in the final array;
6        vector<int>ans;
7        ans.push_back(v[0]);
8        for(int i=1;i<n;i++){
9            //checking for left elements
10            int x=v[i];
11            bool left=true;
12            for(int j=i-1;j>=0;j--){
13                if(v[j]>=x){
14                    left=false;
15                    break;
16                }
17            }
18            bool right=true;
19            for(int j=i+1;j<n;j++){
20                if(v[j]>=x){
21                    right=false;
22                    break;
23                }
24            }
25
26            if(right || left){
27                ans.push_back(x);
28            }
29        }
30
31        return ans;
32    }
33};