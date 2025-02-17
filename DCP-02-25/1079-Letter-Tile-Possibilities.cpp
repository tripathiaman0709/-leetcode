class Solution {
public:

    void fun(string &curr,string &s,vector<bool>&used,unordered_set<string>&v){
        v.insert(curr);
        for(int i=0;i<s.size();i++){
            if(used[i]){
                continue;
            }

            curr.push_back(s[i]);
            used[i]=true;

            fun(curr,s,used,v);

            used[i]=false;
            curr.pop_back();
        }
    }

    int numTilePossibilities(string s) {
        //using backtracking to find all the ways possible
        //do
        //traverse
        //undo
        int n=s.size();
        vector<bool>used(n,false);
        unordered_set<string>v;
        string curr="";        
        fun(curr,s,used,v);

        return v.size()-1;
    }
};