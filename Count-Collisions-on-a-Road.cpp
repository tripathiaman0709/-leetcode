1class Solution {
2public:
3    int countCollisions(string D) {
4        int n=D.size();
5        if (n==1) return 0;
6        int l=0, r=n-1;
7        while (D[l]=='L') l++;
8        while (l<r && D[r]=='R') r--;
9        if (l>=r) return 0;
10        int col=0;
11    
12        for( ; l<=r; l++){
13            while(D[l]=='R'){
14                l++;
15                col++;
16            }
17            if (D[l]=='L') col++;
18        }
19        return col;      
20    }
21};
22auto init = []()
23{ 
24    ios::sync_with_stdio(0);
25    cin.tie(0);
26    cout.tie(0);
27    return 'c';
28}();