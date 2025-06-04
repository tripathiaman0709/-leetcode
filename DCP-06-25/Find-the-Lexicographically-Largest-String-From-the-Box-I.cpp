class Solution {
public:
    string answerString(string s, int k) {
        int n=s.size();
                
        //finding lexicographically largest string
        //n=max 10^3

        //so O(n^2) solution could work

        char maxi='a';
        for(int i=0;i<n;i++){
            maxi=max(maxi,s[i]);
        }

        

        if(n==k){
            string ans="";
            ans+=maxi;
            return ans;
        }
        if(k==1){
            return s;
        }

        vector<int>pos;

        for(int i=0;i<n;i++){
            if(s[i]==maxi){
                pos.push_back(i);
            }
        }

        vector<string>v;

        for(int i=0;i<pos.size();i++){
            int x=n-(k-1);
            int maxlen=min(x,n-pos[i]);

            v.push_back(s.substr(pos[i],maxlen));
        }

        sort(v.rbegin(),v.rend());

        string ans=v[0];
        return ans;
    }
};