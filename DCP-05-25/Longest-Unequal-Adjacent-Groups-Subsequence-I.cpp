class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& w, vector<int>& g) {
        //matlab 1010 type select krna hai
        //ya 0101 type select krna hai
        //fir unme se longest vala answer hoga

        int n=w.size();
        
        vector<string>ans1;
        int x=0;
        for(int i=0;i<n;i++){
            if(g[i]==x){
                ans1.push_back(w[i]);
                if(x==0){
                    x=1;
                }else{
                    x=0;
                }
            }
        }

        vector<string>ans2;
        int y=1;
        for(int i=0;i<n;i++){
            if(g[i]==y){
                ans2.push_back(w[i]);
                if(y==1){
                    y=0;
                }else{
                    y=1;
                }
            }
        }

        if(ans1.size()>ans2.size()){
            return ans1;
        }else{
            return ans2;
        }

    }
};