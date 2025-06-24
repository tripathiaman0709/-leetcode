class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& v, int key, int k) {
        int n=v.size();

        vector<int>vec;
        for(int i=0;i<n;i++){
            if(v[i]==key){
                vec.push_back(i);
            }
        }

        vector<int>ans;

        for(int i=0;i<n;i++){
            int ind1=i;
            for(int j=0;j<vec.size();j++){
                int ind2=vec[j];

                if(abs(ind1-ind2)<=k){
                    ans.push_back(ind1);
                    break;
                }
            }
        }

        return ans;
    }
};