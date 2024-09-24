class Solution {

    void fun(int num,int n,vector<int>&ans){
        if(num>n){
            //base case
            return;
        }
        ans.push_back(num);
        for(int i=0;i<=9;i++){
            int newnum=num*10+i;
            fun(newnum,n,ans);
        }
    }
    
public:
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        //using simple depth based recursion

        for(int i=1;i<=9;i++){
            fun(i,n,ans);
        }
        return ans;
    }
};