class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& v) {
        int n=v.size();

        //making a three digit number
        //from the array given

        int val=0;
        set<int>st;
        vector<int>ans;

        for(int i=0;i<n;i++){
            int x=v[i];
            if(x==0){
                continue;
            }
            val=(100*x);
            for(int j=0;j<n;j++){
                val=100*x;
                if(i==j){
                    continue;
                }
                int y=v[j];
                
                val+=(10*y);

                for(int k=0;k<n;k++){
                    val=100*x + 10*y;
                    if(j==k || k==i){
                        continue;
                    }
                    int z=v[k];
                    val+=z;

                    if(val%2==0){
                        st.insert(val);
                    }               
                }
            }
        }

        // sort(ans.begin(),ans.end());
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};