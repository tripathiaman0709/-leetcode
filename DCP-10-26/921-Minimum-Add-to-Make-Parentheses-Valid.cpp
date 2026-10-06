class Solution {
public:
    int minAddToMakeValid(string s) {
        //could solve it using it a stack , but greedy approach will work faster here
        int n=s.size();
        int l=0;
        int r=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                l++;
            }else{
                if(l>0){
                    l--;
                }else{
                    r++;
                }
            }
        }
        int ans=r+l;
        return ans;
    }
};