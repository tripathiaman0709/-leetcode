class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        int n=s.size();

        //finding maximum depth
        int depth=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                depth++;
            }else{
                depth--;
            }

            maxi=max(maxi,depth);
        }

        //now first half of the depth goes to first half and remaining goes to the second half

        int half=maxi/2;

        vector<int> ans(n, 0);
        int curr = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                curr++;
                ans[i] = curr % 2; 
            } 
            else {
                ans[i] = curr % 2;
                curr--;
            }
        }

        return ans;
    }
};