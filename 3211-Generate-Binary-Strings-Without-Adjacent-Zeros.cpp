class Solution {
public:
    string s;
    vector<string> ans;
    void backtrack(int n, int i) 
    {
        if (i == n) {
            ans.push_back(s);
            return;
        }

        if(s.empty() or s.back() == '1')
        {
            s += '0';
            backtrack(n, i + 1);
            s.pop_back();
        }
        s += '1';
        backtrack(n, i + 1);
        s.pop_back();
    }

    vector<string> validStrings(int n) 
    {
        backtrack(n, 0);
        return ans;
    }
};