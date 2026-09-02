class Solution {
public:
    bool uniformArray(vector<int>& v) {
        int n=v.size();
        //sbko even banao
        bool even=true;
        bool odd=true;
        for(int i=0;i<n;i++){
            if(v[i]%2){
                bool billu=false;
                for(int j=0;j<n;j++){
                    if(v[i]==v[j])continue;

                    if(v[j]-v[i]>=1 && ((v[j]-v[i])%2)==0){
                        billu=true;
                    }
                }
                if(billu=false){
                    even=false;
                }
            }
        }

        for(int i=0;i<n;i++){
            if(v[i]%2==0){
                bool billu=false;
                for(int j=0;j<n;j++){
                    if(v[i]==v[j])continue;

                    if(v[j]-v[i]>=1 && ((v[j]-v[i])%2)==1){
                        billu=true;
                    }
                }
                if(billu=false){
                    odd=false;
                }
            }
        }

        if(odd==false && even==false)return false;
        return true;
    }
};