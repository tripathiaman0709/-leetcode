class Solution {
public:
    int majorityElement(vector<int>& a) {
        //solving in O(n) time complexity and O(1) space complexity
        int n=a.size();
        int count=0;
        int ans;
        for(int i=0;i<n;i++){
            if(count==0){
                ans=a[i];
                count=1;
            }else if(ans==a[i]){
                count++;
            }else{
                count--;
            }
        }
        return ans;

    }
};