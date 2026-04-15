1class Solution {
2public:
3    int closestTarget(vector<string>& v, string t, int k) {
4        int n=v.size();
5        //finding minimum by checking only two possible ways
6        //left or right
7        int mini=n;
8        bool bullu=false;
9        //right
10        for(int i=0;i<n;i++){
11            if(v[((k+i)%(n))]==t){
12                mini=min(mini,i);
13                bullu=1;
14            }
15        }
16        // left
17        for(int i=0;i<n;i++){
18            if(v[((k-i+n)%(n))]==t){
19                mini=min(mini,i);
20                bullu=1;
21            }
22        }
23        if(bullu)return mini;    
24        return -1;
25    }
26};