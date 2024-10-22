class Solution {
public:
    vector<int> searchRange(vector<int>& a, int k) {
        int n=a.size();
        //find the first and last position of element in array

        vector<int>ans;
        if(binary_search(a.begin(),a.end(),k)==0){
            return {-1,-1};
        }else{
            int first = lower_bound(a.begin(),a.end(),k) -a.begin();
            int last  = upper_bound(a.begin(),a.end(),k) -a.begin();

            ans.push_back(first);
            ans.push_back(last-1);
            return ans;
        }
    }  
};