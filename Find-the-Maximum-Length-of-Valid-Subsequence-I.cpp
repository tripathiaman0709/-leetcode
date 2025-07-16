class Solution {
public:
    int maximumLength(vector<int>& v) {
        int n=v.size();
        //there are 4 cases
        //odd even odd even
        //even odd even odd
        //even even even
        //odd odd odd odd

        int case1=0;
        int case2=0;
        int case3=0;
        int case4=0;
        int x=1;
        for(int i=0;i<n;i++){
            if(v[i]%2==x){
                case1++;
                x=!x;
            }
        }
        int y=0;
        for(int i=0;i<n;i++){
            if(v[i]%2==y){
                case2++;
                y=!y;
            }
        }
        for(int i=0;i<n;i++){
            if(v[i]%2==0){
                case3++;
            }
        }
        for(int i=0;i<n;i++){
            if(v[i]%2){
                case4++;
            }
        }

        int ans=max({case1,case2,case3,case4});

        return ans;
    }
};