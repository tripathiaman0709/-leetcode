class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int ans=0;
        unordered_map<char,int>mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        for(auto it:mpp){
            if(it.second<3){
                ans+=it.second;
            }else if(it.second==3){
                ans++;
            }else{
                if(it.second%2){
                    ans++;
                }else{
                    ans+=2;
                }
            }
        }
        return ans;
    }
};