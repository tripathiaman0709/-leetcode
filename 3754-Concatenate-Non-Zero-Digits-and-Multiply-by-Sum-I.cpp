class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int>v;
        int x=n;
        while(x){
            int digit=x%10;
            if(digit!=0){
                v.push_back(digit);
            }
            x/=10;
        }
        reverse(v.begin(),v.end());
        int sum=0;
        for(auto it:v){
            sum+=it;
        }
        string s="";
        for(auto it:v){
            s+=(it+48);
        }
        long long num;
        if(s==""){
            num=0;
        }else{
            num=stoi(s);
        }
        long long ans=sum*num;
        return ans;
    }
};