class Solution {
public:
    // bool isAlternating(vector<int>& check) {
    //     for(int i = 1; i < check.size(); i++) {
    //         if(check[i] == check[i-1]) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    int numberOfAlternatingGroups(vector<int>& v, int k) {
        // int n = v.size();
        // int ans = 0;

        // for(int i = 0; i < n; i++) {
        //     vector<int> check;
        //     for(int j = 0; j < k; j++) {
        //         check.push_back(v[(i + j) % n]);  
        //     }
        //     if(isAlternating(check)) {
        //         ans++;
        //     }
        // }
        
        // return ans;

        int n=v.size();
        vector<int>vec(n+k-1,0);
        for(int i=0;i<n;i++){
            vec[i]=v[i];
        }
        for(int i=0;i<k-1;i++){
            vec[n+i]=v[i];
        }

        int count=0;
        int right=1;
        int left=0;
        int size=0;

        while(right<n+k-1){
            if(vec[right-1]==vec[right]){
                left=right;
            }
            if(right-left+1>=k){
                count++;
            }
            right++;
        }
        return count;
    }
};
