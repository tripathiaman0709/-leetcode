class Solution {
public:
    int minimumIndex(vector<int>& v) {
        //not using majority element approach but rather simply solving by map approach
        int n=v.size();
        unordered_map<int,int>mpp1;
        unordered_map<int,int>mpp2;
        for(int i=0;i<n;i++){
            mpp2[v[i]]++;
        }
        for(int i=0;i<n;i++){
            int left=i+1;
            int right=n-i-1;

            mpp2[v[i]]--;
            mpp1[v[i]]++;

            if(mpp1[v[i]]*2>left && mpp2[v[i]]*2>right){
                return i;
            }
        }
        return -1;
    }
};