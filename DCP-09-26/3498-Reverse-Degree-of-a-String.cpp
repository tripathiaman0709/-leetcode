class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int sum=0;

        for(int i=0;i<n;i++){
            int ind=i+1;
            int val=s[i]-97;
            int rev=(26-val);

            int total=(ind * rev);
            sum+=total;
        }

        return sum;
    }
};