class Solution {
public:
    int subarrayBitwiseORs(vector<int>& v) {
        int n=v.size();
        //doing it in O(32*n) complexity

        unordered_set<int>curr;
        unordered_set<int>prev;
        unordered_set<int>res;

        for(int i=0;i<n;i++){
            int num=v[i];
            for(auto it:prev){
                curr.insert(it|num);
                res.insert(it|num);
            }
            curr.insert(num);
            res.insert(num);
            prev=curr;
            curr.clear();

        }
        return res.size();
    }
};