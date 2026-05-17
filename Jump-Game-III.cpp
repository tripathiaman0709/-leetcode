1class Solution {
2public:
3    bool canReach(vector<int>& v, int k) {
4        //simply doing bfs untill we reach array element that equals to 0
5        int n=v.size();
6        queue<int>q;
7        q.push(k);
8        vector<bool>vis(n,false);
9        vis[k]=true;
10        while(!q.empty()){
11            int ind=q.front();
12            q.pop();
13            //checking for front and back
14            if(v[ind]==0){
15                return true;
16            }
17            if(ind-v[ind]>=0 && ind-v[ind]<n && !vis[ind-v[ind]]){
18                vis[ind-v[ind]]=true;
19                q.push(ind-v[ind]);
20            }
21            if(ind+v[ind]>=0 && ind+v[ind]<n && !vis[ind+v[ind]]){
22                vis[ind+v[ind]]=true;
23                q.push(ind+v[ind]);
24            }
25        }
26        return false;
27    }
28};