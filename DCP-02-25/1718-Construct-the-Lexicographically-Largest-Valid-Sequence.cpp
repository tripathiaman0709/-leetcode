class Solution {
public:

    bool fun(int i,int n,vector<bool>&used,vector<int>&result){
        if(i>=result.size()){
            return true;
        }
        if(result[i]!=-1){
            return fun(i+1,n,used,result);
        }
        for(int num=n;num>=1;num--){
            if(used[num]){
                //already used
                continue;
            }
            used[num]=true;
            result[i]=num;

                if(num==1){
                    if(fun(i+1,n,used,result)==true){
                            return true;
                    }
                }else{
                    int j=i+result[i];
                    if(j<result.size() && result[j]==-1){
                        result[j]=num;
                        if(fun(i+1,n,used,result)==true){
                            return true;
                        }
                        result[j]=-1;
                    }
                }
                used[num]=false;
                result[i]=-1;            
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        //my 200th daily streak code
        //oh hell yeah..

        //simple recursion and backtracing as we need to find al possible ways

        vector<bool>used(n+1,false);
        int sz=2*n-1;

        vector<int>res(sz,-1);
        
        fun(0,n,used,res);
        return res;
    }
};