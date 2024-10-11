class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();

        if(m<n){
            return false;
        }

        vector<int>fre1(256,0);
        for(int i=0;i<n;i++){
            fre1[s1[i]]++;
        }
        //made up frequency 1 array
        vector<int>fre2(256,0);
        for(int i=0;i<n;i++){
            fre2[s2[i]]++;
        }
        if(fre2==fre1){
            return true;
        }
        for(int l=1,r=n;r<m;r++,l++){
            fre2[s2[l-1]]--;
            fre2[s2[r]]++;
            if(fre2==fre1){
                return true;
            }
        }
        return false;
    }
};