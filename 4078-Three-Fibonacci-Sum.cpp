class Solution {
public:
    bool threeFibonacciSum(int x) {
        vector<long long>v;

        v.push_back(0);
        v.push_back(1);

        for(long long i=2;i<51;i++){
            v.push_back(v[i-1]+v[i-2]);
        }

        //if x exists in the vector then true else false
        for(int i=0;i<48;i++){
            int num=v[i]+v[i+1]+v[i+2];
            if(num>x){
                return false;
            }
            if(num==x){
                return true;
            }
        }

        return false;
        

        return false;
    }
};