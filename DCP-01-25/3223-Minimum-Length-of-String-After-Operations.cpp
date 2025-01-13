class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int ans=0;
        //using a vector array instead of unordered map
        //of size 26 as only 26 possible characters will be there
        // unordered_map<char,int>mpp;
        vector<int>v(26,0);
        for(int i=0;i<n;i++){
            v[s[i]-97]++;
        }
        for(auto it:v){
            if(it<3){
                ans+=it;
            }else if(it==3){
                ans++;
            }else{
                if(it%2){
                    ans++;
                }else{
                    ans+=2;
                }
            }
        }
        return ans;
    }
};