1class Solution {
2public:
3
4    int rev(int n){
5        //no need to use stoll, we will rather use stoi
6        //and there are no negetive integers as well
7
8        string s=to_string(n);
9        reverse(s.begin(),s.end());
10        int num=stoi(s);
11
12        return num;
13    }
14
15    int minMirrorPairDistance(vector<int>& v) {
16        int n=v.size();
17        //storing the number along with their position
18        unordered_map<int,vector<int>>mpp;
19        for(int i=0;i<n;i++){
20            mpp[v[i]].push_back(i);
21        }
22        int mini=INT_MAX;
23        bool bullu=false;
24        //now checking if their reverse exists
25        for(int i=0;i<n;i++){
26            int x=rev(v[i]);
27            if(mpp[x].size()>0){
28                auto &vec = mpp[x];
29
30                // first index strictly greater than i
31                auto it = upper_bound(vec.begin(), vec.end(), i);
32
33                if(it != vec.end()){
34                    bullu = true;
35                    mini = min(mini, *it - i);
36                }
37            }
38        }
39        if(!bullu)return -1;
40        return mini;
41    }
42};