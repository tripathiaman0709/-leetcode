class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& v) {
        int n=v.size();
        int count=0;
        for(int i=0;i<n;i++){
            int a=v[i][0];
            int b=v[i][1];

            for(int j=i+1;j<n;j++){
                int c=v[j][0];
                int d=v[j][1];

                if((a==c && b==d) || (a==d && b==c)){
                    count++;
                }
            }
        }
        return count;
    }
};