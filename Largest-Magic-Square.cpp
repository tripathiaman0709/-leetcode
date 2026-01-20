1class Solution {
2public:
3
4    bool ispossible(int i,int j,int x,vector<vector<int>>&v){
5        int n=v.size();
6        int m=v[0].size();
7        if(i+x<=n && j+x<=m){
8            return true;
9        }
10        return false;
11    }
12
13    bool check(int i,int j,int x,vector<vector<int>>&v){
14        long long n=v.size();
15        unordered_set<long long>st;
16        //row sum
17        for(long long row=i;row<i+x;row++){
18            long long sum=0;
19            for(long long col=j;col<j+x;col++){
20                sum+=v[row][col]; 
21            }
22            st.insert(sum);
23        }
24        //col sum
25        for(long long col=j;col<j+x;col++){
26            long long sum=0;
27            for(long long row=i;row<i+x;row++){
28                sum+=v[row][col]; 
29            }
30            st.insert(sum);
31        }
32        //diagonal sum
33        long long total=0;
34        for(long long row=i, col=j;row<i+x && col<j+x;row++ ,col++){
35            total+=v[row][col];            
36        }
37        st.insert(total);
38
39        long long tot=0;
40        for (int row = i, col = j + x - 1; row < i + x && col >= j; row++, col--) {
41            tot += v[row][col];
42        }
43        st.insert(tot);
44        if(st.size()==1){
45            return true;
46        }
47        return false;
48    }
49
50    int largestMagicSquare(vector<vector<int>>& v) {
51        //we can simply try for all possible k's
52        int n=v.size();
53        int m=v[0].size();
54        int x=n;
55        while(x>1){
56        for(int i=0;i<n;i++){
57            for(int j=0;j<m;j++){
58                if(ispossible(i,j,x,v) && check(i,j,x,v)){
59                    return x;
60                }
61            }
62        }
63        x--;
64        }
65        return 1;
66    }
67};