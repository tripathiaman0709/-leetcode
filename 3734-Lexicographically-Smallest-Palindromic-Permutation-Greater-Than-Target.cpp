#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string ans;

    bool go(vector<char>& p, vector<int>& cnt, string& t, bool big, char mid, int n){
    if(!ans.empty()) return true;
    int h = n/2;
    if((int)p.size() == h){
        string l(p.begin(), p.end());
        string r = l; reverse(r.begin(),r.end());
        string cur = (n%2 ? l + mid + r : l + r);
        if(cur > t){
            ans = cur;
            return true;
        }
        return false;
    }
    int i = p.size();
    for(int c=0; c<26; c++){
        if(!cnt[c]) continue;
        if(!big && c+'a' < t[i]) continue;
            p.push_back(c+'a');
        cnt[c]--;
        bool nb = big || (c+'a' > t[i]);
        if(go(p, cnt, t, nb, mid, n)) return true;
        p.pop_back();
        cnt[c]++;
    }
    return false;
}

string lexPalindromicPermutation(string s, string t) {
    vector<int> cnt(26,0);
    for(char c:s) cnt[c-'a']++;
    ans = "";
    int odd = 0; char mid = 0;
    for(int i=0;i<26;i++){
        if(cnt[i]%2){
            odd++;
            mid = 'a'+i;
        }
        cnt[i]/=2;
    }
    if(odd>1) return "";
    vector<char> p;
    go(p, cnt, t, false, mid, s.size());
    return ans;
}
};