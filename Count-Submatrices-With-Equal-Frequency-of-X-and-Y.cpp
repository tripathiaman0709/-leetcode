1class Solution {
2public:
3    int numberOfSubmatrices(vector<vector<char>>& v) {
4        int n=v.size();
5        int m=v[0].size();
6
7        vector<vector<int>>x(n,vector<int>(m,0));
8        vector<vector<int>>y(n,vector<int>(m,0));
9
10        for(int i=0;i<n;i++){
11            for(int j=0;j<m;j++){
12                if(v[i][j]=='X'){
13                    x[i][j]=1;
14                }if(v[i][j]=='Y'){
15                    y[i][j]=1;
16                }
17            }
18        }
19        for(int i=0;i<n;i++){
20            for(int j=0;j<m;j++){
21                if(i>0)x[i][j]+=x[i-1][j];
22                if(j>0)x[i][j]+=x[i][j-1];
23                if(i>0 && j>0)x[i][j]-=x[i-1][j-1];
24            }
25        }
26        for(int i=0;i<n;i++){
27            for(int j=0;j<m;j++){
28                if(i>0)y[i][j]+=y[i-1][j];
29                if(j>0)y[i][j]+=y[i][j-1];
30                if(i>0 && j>0)y[i][j]-=y[i-1][j-1];
31            }
32        }
33        int count=0;
34        for(int i=0;i<n;i++){
35            for(int j=0;j<m;j++){
36                if(x[i][j]==y[i][j] && x[i][j]>0){
37                    count++;
38                }
39            }
40        }
41        return count;
42    }
43};