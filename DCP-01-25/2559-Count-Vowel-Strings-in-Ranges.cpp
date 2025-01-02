class Solution {
public:
    vector<int> vowelStrings(vector<string>& v, vector<vector<int>>& q) {
        int n=v.size();
        vector<int>x(n,0);
        for(int i=0;i<n;i++){
            string s=v[i];
            int sz=s.size();
            if((s[0]=='a' || s[0]=='e' || s[0]=='i' || s[0]=='o' ||s[0]=='u') &&  (s[sz-1]=='a' || s[sz-1]=='e' || s[sz-1]=='i' || s[sz-1]=='o' ||s[sz-1]=='u')){
                x[i]=1;
            }
        }
        vector<int>pre(n,0);
        pre[0]=x[0];
        for(int i=1;i<n;i++){
            pre[i]=x[i]+pre[i-1];
        }
        int sz=q.size();
        vector<int>ans;
        for(int i=0;i<sz;i++){
            int l=q[i][0];
            int r=q[i][1];
            if(l==0){
                ans.push_back(pre[r]);
            }else{
                ans.push_back(pre[r]-pre[l-1]);
            }            
        }
        return ans;
    }
};