class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& v, int start, int k) {
        int n=v.size();
        //two options 
        //left to right 
        //right to left

        //firstly finding all the positions available for working
        vector<int>pos;
        for(int i=0;i<n;i++){
            pos.push_back(v[i][0]);
        }

        //now using prefix sum
        vector<int>pre(n,0);
        pre[0]=v[0][1];

        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+v[i][1];
        }

        int maxi=0;

        //left to right

        for(int i=0;i<=k/2;i++){
            int leftind= start-i;
            int rightind=start+(k-2*i);

            int lb=lower_bound(pos.begin(),pos.end(),leftind)-pos.begin();
            int ub=upper_bound(pos.begin(),pos.end(),rightind)-pos.begin()-1;
            if(ub>=lb && ub<n){
                if(lb==0){
                    maxi=max(pre[ub],maxi);
                }else{
                    maxi=max(pre[ub]-pre[lb-1],maxi);
                }
            }
            
        }

        //right to left

        for(int i=0;i<=k/2;i++){
            int leftind= start-(k-2*i);
            int rightind=start+i;

            int lb=lower_bound(pos.begin(),pos.end(),leftind)-pos.begin();
            int ub=upper_bound(pos.begin(),pos.end(),rightind)-pos.begin()-1;
            if(ub>=lb && ub<n){
                if(lb==0){
                    maxi=max(pre[ub],maxi);
                }else{
                    maxi=max(pre[ub]-pre[lb-1],maxi);
                }
            }
            

        }

        return maxi;
    }
};