class Solution {
public:
    bool rotateString(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        if(n!=m){
            return false;
        }
        string s=s1;
        string s3=s1.substr(0,n-1);
        s+=s3;

        size_t found = s.find(s2);
        if (found != string::npos){
            return true;
        }else{
            return false;
        }
    }
};