class Solution {
public:

    bool ispalindrome(string s){
        int i=0;
        int j=s.size()-1;

        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    string basek(long long n,int k){
        if(n==0){
            return "0";
        }
        string s="";
        while(n){
            s+=n%k;
            n/=k;
        }

        return s;
    }

    long long kMirror(int k, int n) {
        long long sum=0;
        int l=1;

        while(n){
            int half=(l+1)/2;

            int mini=pow(10,half-1);
            int maxi=pow(10,half)-1;

            for(int i=mini;i<=maxi;i++){
                string first=to_string(i);
                string second=first;

                reverse(second.begin(),second.end());

                string num="";

                if(l%2==0){
                    num=first+second;
                }else{
                    num=first+second.substr(1);
                }

                long long number=stoll(num);
                string val=basek(number,k);

                if(ispalindrome(val)){
                    sum+=number;
                    n--;
                    if(n==0){
                        break;
                    }
                }                                       
            }
            l++;
        }
        return sum;
    }
};