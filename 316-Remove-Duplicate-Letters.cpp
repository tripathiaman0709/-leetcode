class Solution {
public:
    string removeDuplicateLetters(string s) {
        //using monotonic stack
        int n=s.size();
        vector<bool>taken(n,false);//at start didn't take any character
        vector<int>lastind(26);
        stack<char>ans;
        for(int i=0;i<n;i++){
            char ch=s[i];
            int ind=s[i]-'a';
            lastind[ind]=i;//stores last occuring index of each character
        }

        for(int i=0;i<n;i++){
            char ch=s[i];
            int ind=s[i]-'a';

            if(taken[ind]){
                continue;//if already taken then move on
            }

            while(ans.size()>0 && ans.top()>ch && lastind[ans.top()-'a']>i){
                taken[ans.top()-'a']=false;
                ans.pop();
            }
            ans.push(ch);
            taken[ch-'a']=true;
        }
        string sol="";
        while(!ans.empty()){
            sol+=ans.top();
            ans.pop();
        }
        reverse(sol.begin(),sol.end());
        return sol;
    }
};