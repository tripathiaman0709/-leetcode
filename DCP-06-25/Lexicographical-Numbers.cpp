class Solution {
public:

    void dfs(int x,int n,vector<int>&v){
        if(x>n){
            return;
        }
        v.push_back(x);

        for(int i=0;i<=9;i++){
            int newx=10*x+i;
            dfs(newx,n,v);
        }
        
    }

    vector<int> lexicalOrder(int n) {
        // //simplest approach

        // vector<string>v;

        // for(int i=1;i<=n;i++){
        //     string s=to_string(i);

        //     v.push_back(s);
        // }

        // sort(v.begin(),v.end());

        // vector<int>ans;

        // for(int i=0;i<v.size();i++){
        //     int x=stoi(v[i]);

        //     ans.push_back(x);
        // }

        // return ans;


        //better approach
        //using dfs
        vector<int>ans;
        for(int i=1;i<=9;i++){
            dfs(i,n,ans);
        }

        return ans;

    }
};