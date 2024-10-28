class Solution {
public:

    unordered_map<string,bool>mpp;

    bool fun(string s,unordered_set<string>&st){
        int n=s.size();

        if(mpp.count(s)){
            return mpp[s];
        }
        for(int i=0;i<n;i++){
            string pre=s.substr(0,i+1);
            string suff=s.substr(i+1);

            if((st.count(pre) && st.count(suff))  || (st.count(pre) && fun(suff,st))){
                return mpp[s]=true;
            }
        }

        return mpp[s]=false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        int n=words.size();
        mpp.clear();
        vector<string>v;
        unordered_set<string>st;
        for(int i=0;i<n;i++){
            st.insert(words[i]);
        }

        for(int i=0;i<n;i++){
            string s=words[i];
            if(fun(s,st)){
                v.push_back(s);
            }
        }

        return v;
    }
};