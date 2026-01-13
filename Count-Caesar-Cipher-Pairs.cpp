1class Solution {
2public:
3    long long countPairs(vector<string>& words) {
4
5        unordered_map<string,int> mp;
6
7        int m = words[0].size();
8        for(auto x:words)
9            {
10                string s="";
11                for(int i=1;i<m;i++)
12                    {
13                        int diff = x[i]-x[i-1];
14                        if(diff<0){diff+=26;}
15                        char c = (char)(diff+'a');
16                        s+=c;
17                    }
18                mp[s]++;
19            }
20        
21        long long ans=0;
22        
23        for(auto it:mp){
24            long long fq = (long long)it.second;
25            ans+=((fq)*(fq-1))/2;
26        }
27        return ans;
28
29    }
30};