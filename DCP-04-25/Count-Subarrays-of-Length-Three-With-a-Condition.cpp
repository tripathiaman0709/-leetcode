class Solution {
public:
    int countSubarrays(vector<int>& v) {
        int n=v.size();
        int count=0;
        for(int i=0;i<n-2;i++){
            int first=v[i];
            int second=v[i+1];
            int third=v[i+2];
            if(2*(first+third) == second){
                count++;
            }
        }
        return count;
    }
};