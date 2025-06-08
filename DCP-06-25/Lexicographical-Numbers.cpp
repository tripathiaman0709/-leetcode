class Solution {
public:
    vector<int> lexicalOrder(int n) {
        //simplest approach

        vector<string>v;

        for(int i=1;i<=n;i++){
            string s=to_string(i);

            v.push_back(s);
        }

        sort(v.begin(),v.end());

        vector<int>ans;

        for(int i=0;i<v.size();i++){
            int x=stoi(v[i]);

            ans.push_back(x);
        }

        return ans;
    }
};