class Solution {
public:

    bool fun(string s1,string s2){
        int n=s1.size();
        int m=s2.size();

        //is s1 both a prefix and suffix of s2

        if(m<n){
            return false;
        }
        string s3=s2.substr(0,n);
        string s4=s2.substr(m-n,n);

        if(s1==s3 && s1==s4){
            return true;
        }
        return false;
    }

    int countPrefixSuffixPairs(vector<string>& v) {
        int count=0;
        int n=v.size();
        for(int i=0;i<n;i++){
            string s1=v[i];
            for(int j=i+1;j<n;j++){                
                string s2=v[j];
                if(fun(s1,s2)){
                    count++;
                }                
            }
        }
        return count;
    }
};