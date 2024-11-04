class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n=a.size();
        int m=b.size();
        vector<int>ans;
        for(int i=0;i<m;i++){
            int count=0;
            int a1=b[i][0];
            int b1=b[i][1];
            int r=b[i][2];

            for(int j=0;j<n;j++){
                int x=a[j][0];
                int y=a[j][1];

                if(pow(x-a1,2)+pow(y-b1,2)<=pow(r,2)){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};