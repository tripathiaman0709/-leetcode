class Solution {
public:
    int numOfUnplacedFruits(vector<int>& v1, vector<int>& v2) {
        int n=v1.size();
        int m=v2.size();

        vector<bool>vis(m,false);

        for(int i=0;i<n;i++){
            int fruit=v1[i];
            for(int j=0;j<m;j++){
                int basket=v2[j];

                if(basket>=fruit && vis[j]==false){
                    vis[j]=true;
                    break;
                }
            }
        }
        int count=0;
        for(auto it:vis){
            if(it==false){
                count++;
            }
        }
        return count;
    }
};