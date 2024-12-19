class Solution {
public:
    int maxChunksToSorted(vector<int>& v) {
        int n=v.size();
        vector<int>pre(n,0);
        for(int i=0;i<n;i++){
            pre[i]=i;
        }
        for(int i=1;i<n;i++){
            pre[i]=pre[i]+pre[i-1];
        }
        for(int i=1;i<n;i++){
            v[i]=v[i]+v[i-1];
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(pre[i]==v[i]){
                count++;
            }
        }
        return count;
    }
};