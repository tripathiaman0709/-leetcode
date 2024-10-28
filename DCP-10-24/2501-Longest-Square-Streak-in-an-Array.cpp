class Solution {
public:
    int longestSquareStreak(vector<int>& a) {
        //TC=O(N)
        int n=a.size();
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(a[i]);
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            long long num=a[i];
            int count=0;
            while(st.count(num)){
                count++;
                if(num*num>100000){
                    break;
                }
                num*=num;                
            }
            maxi=max(maxi,count);
        }
        if(maxi<2){
            return -1;
        }else{
            return maxi;
        }
    }
};