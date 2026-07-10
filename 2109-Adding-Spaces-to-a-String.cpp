class Solution {
public:
    string addSpaces(string s, vector<int>& v) {
        int n=s.size();
        int m=v.size();

        int newtotal=n+m;

        string ans(newtotal,'?');
        int j=0;
        for(int i=0;i<n;i++){
            if(j<m && i==v[j]){
                j++;
                ans[i+j]=s[i];
            }
            else{
                ans[i+j]=s[i];
            }
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]=='?'){
                ans[i]=' ';
            }
        }

        return ans;
    }
};