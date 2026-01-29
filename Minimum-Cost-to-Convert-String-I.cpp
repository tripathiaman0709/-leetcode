1class Solution {
2public:
3
4    void fw(vector<char>& original, vector<char>& changed,vector<int>&cost,vector<vector<long long>>&adj){
5        
6        for(int i=0;i<original.size();i++){
7            int o=original[i]-'a';
8            int c=changed[i]-'a';
9
10            adj[o][c]=min(adj[o][c],(long long)cost[i]);
11        }
12
13        //now applying floydd warshall
14        for(int k=0;k<26;k++){
15            for(int i=0;i<26;i++){
16                for(int j=0;j<26;j++){
17                    adj[i][j]=min(adj[i][j] , adj[i][k] + adj[k][j]);
18                }
19            }
20        }
21
22    }
23
24    long long minimumCost(string s1, string s2, vector<char>& original, vector<char>& changed, vector<int>& cost) {
25        //firstly applying floyd warshall approach which will be O(26*26*26) ie constant time complexity making the code of complexity O(n)
26        //floyd warshall is a multi source algorithm ie it stores 
27        vector<vector<long long>>adj(26,vector<long long>(26,INT_MAX));
28        fw(original,changed,cost,adj);
29        long long sum=0;
30        int n=s1.size();
31        for(int i=0;i<n;i++){
32            if(s1[i]==s2[i]){
33                continue;
34            }
35            if(adj[s1[i]-'a'][s2[i]-'a']==INT_MAX){
36                return -1;
37            }
38
39            sum+=adj[s1[i]-'a'][s2[i]-'a'];
40        }
41        return sum;
42    }
43};