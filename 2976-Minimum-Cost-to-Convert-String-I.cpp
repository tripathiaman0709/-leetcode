class Solution {
public:

    void fw(vector<char>& original, vector<char>& changed,vector<int>&cost,vector<vector<long long>>&adj){
        
        for(int i=0;i<original.size();i++){
            int o=original[i]-'a';
            int c=changed[i]-'a';

            adj[o][c]=min(adj[o][c],(long long)cost[i]);
        }

        //now applying floydd warshall
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    adj[i][j]=min(adj[i][j] , adj[i][k] + adj[k][j]);
                }
            }
        }

    }

    long long minimumCost(string s1, string s2, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        //firstly applying floyd warshall approach which will be O(26*26*26) ie constant time complexity making the code of complexity O(n)
        //floyd warshall is a multi source algorithm ie it stores 
        vector<vector<long long>>adj(26,vector<long long>(26,INT_MAX));
        fw(original,changed,cost,adj);
        long long sum=0;
        int n=s1.size();
        for(int i=0;i<n;i++){
            if(s1[i]==s2[i]){
                continue;
            }
            if(adj[s1[i]-'a'][s2[i]-'a']==INT_MAX){
                return -1;
            }

            sum+=adj[s1[i]-'a'][s2[i]-'a'];
        }
        return sum;
    }
};