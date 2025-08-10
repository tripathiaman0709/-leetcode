class Solution {
public:
    
    string fun(int n){
        string s=to_string(n);
        sort(s.begin(),s.end());
        return s;
    }

    bool reorderedPowerOf2(int n) {
        string s=fun(n);

        for(int i=0;i<=29;i++){
            if(s==fun(1<<i)){
                return true;
            }
        }

        return false;

    }
};