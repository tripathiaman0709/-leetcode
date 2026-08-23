class Solution {
public:

    int summer(int n){
        int add=0;
        while(n){
            add+=(n%10);
            n/=10;
        }
        return add;
    }

    int multi(int n){
        int pro=1;
        while(n){
            pro*=(n%10);
            n/=10;
        }
        return pro;
    }

    bool checkDivisibility(int n) {
        //playing with digits
        int sum=summer(n);
        int pro=multi(n);

        int ans=sum+pro;
        return !(n%ans);
    }
};