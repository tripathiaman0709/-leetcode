1class Solution {
2public:
3    int numSpecial(vector<vector<int>>& v) {
4        int n=v.size();
5        int m=v[0].size();
6
7        vector<int>row;
8        vector<int>col;
9
10        for(int i=0;i<n;i++){
11            int count=0;
12            for(int j=0;j<m;j++){
13                if(v[i][j]==1)count++;
14            }
15            row.push_back(count);
16        }
17
18        for(int i=0;i<m;i++){
19            int count=0;
20            for(int j=0;j<n;j++){
21                if(v[j][i]==1)count++;
22            }
23            col.push_back(count);
24        }      
25
26        int ans=0;  
27
28        for(int i=0;i<n;i++){
29            for(int j=0;j<m;j++){
30                if(v[i][j]==1){
31                    //now checking the row and column
32                    if(row[i]==1 && col[j]==1)ans++;
33                }
34            }
35        }
36        return ans;
37    }
38};