class Solution {
public:
    vector<string> divideString(string s, int k, char ch) {
        int n=s.size();
        vector<string>ans;

        if(n%k==0){
            for(int i=0;i<n-k+1;i+=k){
                string ss="";
                for(int j=0;j<k;j++){
                    ss+=s[i+j];
                }

                ans.push_back(ss);
            }
            return ans;
        }else{
            for(int i=0;i<n-k+1;i+=k){
                string ss="";
                for(int j=0;j<k;j++){
                    ss+=s[i+j];
                }

                ans.push_back(ss);
            }
            string ss="";
            for(int i=k*(n/k);i<n;i++){
                ss+=s[i];
            }
            for(int i=0;i<k-(n%k);i++){
                ss+=ch;
            }

            ans.push_back(ss);

            return ans;
        }
    }
};