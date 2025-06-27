class Solution {
public:

    bool subseq(string s,string curr,int k){
        int n=s.size();
        int m=curr.size()*k;

        int i=0;
        int j=0;

        while(i<n && j<m){
            if(s[i]==curr[j%curr.size()]){
                j++;
            }
            i++;
        }

        return (j==m);
    }

    bool backtrack(string s,string curr,vector<int>&reqfreq,int k,int maxlen,string &ans){
        int n=s.size();

        if(curr.size()==maxlen){
            if(subseq(s,curr,k)){
                ans=curr;
                return true;
            }
            return false;
        }

        for(int i=25;i>=0;i--){
            if(reqfreq[i]==0){
                continue;
            }
            char ch=i+'a';
            curr.push_back(ch);
            reqfreq[i]--;
            if(backtrack(s,curr,reqfreq,k,maxlen,ans)==true){
                return true;
            }
            curr.pop_back();
            reqfreq[i]++;
        }
        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n=s.size();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }

        int maxlen=n/k;
        //saare elements jo required hai unki frequency minimum k toh honi chahiye

        for(int i=0;i<n;i++){
            if(freq[s[i]-'a']<k){
                s[i]='?';
            }
        }
        string str="";
        for(int i=0;i<n;i++){
            if(s[i]!='?'){
                str+=s[i];
            }
        }

        vector<int>reqfreq(26,0);
        //max usable frequency of each element
        for(int i=0;i<str.size();i++){
            (reqfreq[str[i]-'a']=freq[str[i]-'a']/k);
        }
        string ans="";
        for(int i=maxlen;i>0;i--){
            vector<int>temp=reqfreq;
            string curr="";

            if(backtrack(str,curr,reqfreq,k,i,ans)==true){
                return ans;
            }
        }
        return ans;
    }
};