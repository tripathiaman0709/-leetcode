class Solution {
public:

    int find(string s){
        int n=s.size();
        int ans=0;
        int k=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                ans+=pow(2,k);
            }
            k++;
        }
        return ans;
    }

    string fun(int n){
        string x="";
        while(n){
            if(n%2){
                x+='1';
            }else{
                x+='0';
            }
            n/=2;
        }
        reverse(x.begin(),x.end());
        return x;
    }

    int maxGoodNumber(vector<int>& a) {
        int n=a.size();
        vector<string>s;

        for(int i=0;i<n;i++){
            s.push_back(fun(a[i]));
        }

        sort(s.begin(),s.end(),[](const string &a, const string &b) {
        return (b + a) > (a + b); 
    });
        string sol="";
        for(int i=n-1;i>=0;i--){
            sol+=s[i];
        }

        return find(sol);
    }
};