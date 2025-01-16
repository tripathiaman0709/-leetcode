class Solution {
public:
    int xorAllNums(vector<int>& v1, vector<int>& v2) {
        int n=v1.size();
        int m=v2.size();



        int xoro=0;
        if(m%2){
        for(int i=0;i<n;i++){
            xoro^=v1[i];
        }
        }
        if(n%2){
        for(int i=0;i<m;i++){
            xoro^=v2[i];
        }
        }
        return xoro;        
    }
};