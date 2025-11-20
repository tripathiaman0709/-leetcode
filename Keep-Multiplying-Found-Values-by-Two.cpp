class Solution {
public:

    bool check(vector<int>&v,int o){
        bool bullu=false;

        for(auto it:v){
            if(it==o){
                return true;
            }
        }

        return false;
    }

    int findFinalValue(vector<int>& v, int o) {
        int n=v.size();
        while(1){
            if(check(v,o)){
                o*=2;
            }else{
                break;
            }
        }

        return o;
    }
};