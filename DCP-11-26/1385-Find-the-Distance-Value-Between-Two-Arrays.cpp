class Solution {
public:
    int findTheDistanceValue(vector<int>& v1, vector<int>& v2, int k) {
        int n=v1.size();
        int m=v2.size();

        bool flag=0;
        int ans=0;
        

        for(int i=0;i<n;i++){
            flag=0;
            for(int j=0;j<m;j++){
                int dis=abs(v1[i]-v2[j]);
                if(dis<=k)flag=1;
            }
            if(flag){
                ans++;
            }
        }

        return n-ans;
    }
};