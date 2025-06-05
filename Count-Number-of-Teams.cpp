class Solution {
public:
    int n;
    int t1[100001][3];
    int t2[100001][3];
    int solve_inc(vector<int>&rating,int i,int count){
        if(count==2) return 1;
        if(i>=n) return 0;
        if(t1[i][count]!=-1) return t1[i][count];
        int ans=0;
        for(int j=i+1;j<n;j++){
            if(rating[j]>rating[i]){
                ans+=solve_inc(rating,j,count+1);
            }
        }
        return t1[i][count]=ans;
    }
    int solve_dec(vector<int>&rating,int i,int count){
        if(count==2) return 1;
        if(i>=n) return 0;
        if(t2[i][count]!=-1) return t2[i][count];
        int ans=0;
        for(int j=i+1;j<n;j++){
            if(rating[j]<rating[i]){
                ans+=solve_dec(rating,j,count+1);
            }
        }
        return t2[i][count]=ans;
    }
    int numTeams(vector<int>& rating) {
        memset(t1,-1,sizeof(t1));
        memset(t2,-1,sizeof(t2));
        n=rating.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=solve_inc(rating,i,0)+solve_dec(rating,i,0);
        }
        return ans;
    }
};