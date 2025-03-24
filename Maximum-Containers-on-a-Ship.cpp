class Solution {
public:
    int maxContainers(int n, int w, int m) {
        int total=n*n;
        // int sum=0;
        // int count=0;
        // for(int i=0;i<total;i++){
            
        //     sum+=w;
        //     count++;

        //     if(sum>m){
        //         return i;
        //     }
        // }
        // return count;
        int count=0;
        while(total>0 && m>0){
            total--;
            m-=w;
            if(total>=0 && m>=0)
            count++;
        }
        return count;
    }
};