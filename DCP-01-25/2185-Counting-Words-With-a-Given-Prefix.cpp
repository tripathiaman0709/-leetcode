class Solution {
public:
    int prefixCount(vector<string>& v, string s) {
        int n=v.size();
        int sz=s.size();
        int count=0;
        for(int i=0;i<n;i++){
            string s1=v[i];
            int size=s1.size();

            if(size<sz){
                continue;
            }else{
                if(s1.substr(0,sz)==s){
                    count++;
                }
            }
        }
        return count;
    }
};