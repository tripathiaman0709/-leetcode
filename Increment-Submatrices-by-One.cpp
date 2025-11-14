class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
        //i think we should first flatten out the matrix
        //then apply the difference array technique
        //then rebuild the vector of vector again

        vector<int>v(n*n+1,0);
        for (auto &x : q) {
            int r1 = x[0], c1 = x[1], r2 = x[2], c2 = x[3];

            for (int row = r1; row <= r2; row++) {
                int l = row * n + c1;
                int r = row * n + c2;

                v[l]++;
                v[r + 1]--;
            }
        }

        //now we will take the cumulative sum to find the final

        for(int i=1;i<=n*n;i++){
            v[i]+=v[i-1];
        }


        //now converting it back to an n x n matrix

        vector<vector<int>>ans(n,vector<int>(n,0));
        // int r=0;
        // int c=0;
        for(int i=0;i<n*n;i++){
            ans[i/n][i%n]=v[i];
            // c++;
            // if(i%n==0 && i!=0){
            //     r++;
            //     // c=0;
            // }
        }

        return ans;
    }
};