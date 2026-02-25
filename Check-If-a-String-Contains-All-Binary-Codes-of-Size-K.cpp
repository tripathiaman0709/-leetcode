1class Solution {
2public:
3    bool hasAllCodes(string s, int k) {
4        //k size ke saare substrings set me daaldo 
5        //fir size of set se check krlo if all possiblities
6        //for size n = pow(2,n)
7
8        int n=s.size();
9        unordered_set<string>st;
10
11        for(int i=0;i<=n-k;i++){
12            string str=s.substr(i,k);
13            st.insert(str);
14        }
15        return (pow(2,k)==st.size());
16    }
17};