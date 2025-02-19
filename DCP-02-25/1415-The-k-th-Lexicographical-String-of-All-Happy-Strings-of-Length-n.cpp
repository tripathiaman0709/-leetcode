class Solution {
public:

    void fun(int n,int k,string &curr,vector<string> &ans){
        if(curr.size()==n){
            ans.push_back(curr);
            return;
        }
        for(char ch='a';ch<='c';ch++){
            if(!curr.empty() && curr.back()==ch){
                continue;
            }
            //do
            curr.push_back(ch);
            //explore
            fun(n,k,curr,ans);
            //undo
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr="";
        vector<string>ans;

        int count=0;
        fun(n,k,curr,ans);
        if(ans.size()<k){
            return "";
        }
        return ans[k-1];
    }
};