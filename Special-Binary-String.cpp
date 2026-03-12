1class Solution {
2public:
3    string makeLargestSpecial(string s) {
4        int n=s.size();
5        int sum=0;
6        int start=0;
7        vector<string>v;
8        for(int i=0;i<n;i++){
9            if(s[i]=='1')sum++;
10            else sum--;
11
12            if(sum==0){
13                string str=s.substr(start+1,i-start-1);
14                v.push_back("1"+makeLargestSpecial(str)+"0");
15                start=i+1;
16            }
17        }
18        sort(v.rbegin(),v.rend());
19        string ans="";
20        for(int i=0;i<v.size();i++){
21            ans+=v[i];
22        }
23        return ans;
24    }
25};