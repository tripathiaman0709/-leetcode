class Solution {
public:

    int fun(int n){
        int count=0;
        while(n){
            n/=10;
            count++;
        }
        return count;
    }

    int minMaxDifference(int num) {
        // vector<int>maxi(10,-1);
        // vector<int>mini(10,-1);

        // int sz=fun(num);

        // vector<int>v(sz);
        // for(int i=0;i<sz;i++){
        //     v[i]=num%10;
        //     num/=10;
        // }
        // int bigi=9;
        // int smalli=0;

        // string big="";
        // string small="";

        // for(int i=0;i<sz;i++){
        //     if(maxi[v[i]]!=-1 && v[i]<bigi){
        //         char ch=bigi + 48;
        //         big+=ch;
        //         maxi[v[i]]=bigi;
        //         bigi--;
                
        //     }else{
        //         char ch=v[i]+48;
        //         big+=ch;
        //     }

        // }
        // for(int i=0;i<sz;i++){
        //     if(mini[v[i]]!=-1 && v[i]>smalli){
        //         char ch=smalli + 48;
        //         small+=ch;
        //         mini[v[i]]=smalli;
        //         smalli++;
        //     }else{
        //         char ch=v[i]+48;
        //         small+=ch;
        //     }
        // }

        // int mx=stoi(big);
        // int mn=stoi(small);


        // int ans=mx-mn;

        // return ans;



        int n=fun(num);
        vector<int>v(n);
        for(int i=0;i<n;i++){
            v[n-i-1]=num%10;
            num/=10;
        }
        int maxi=-1;
        int mini=-1;
        for(int i=0;i<n;i++){
            if(v[i]!=9){
                maxi=v[i];
                break;
            }
        }

        for(int i=0;i<n;i++){
            if(v[i]!=0){
                mini=v[i];
                break;
            }
        }

        vector<int>vec=v;
        string mxstr="";
        string mnstr="";

        for(int i=0;i<n;i++){
            if(v[i]==maxi){
                mxstr+='9';
            }else{
                mxstr+=v[i]+48;
            }
        }

        for(int i=0;i<n;i++){
            if(v[i]==mini){
                mnstr+='0';
            }else{
                mnstr+=v[i]+48;
            }
        }

        int big=stoi(mxstr);
        int small=stoi(mnstr);

        return big-small;


    }
};