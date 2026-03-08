1class Solution {
2public:
3    bool checkOnesSegment(string s) {
4        int n=s.size();
5        //bad question
6        //if ones are present then must be present in a single segment only
7        bool biilu=true;
8        for(int i=1;i<n;i++){
9            if(s[i]=='0'){
10                biilu=false;
11            }else{
12                if(s[i]=='1' && biilu==false){
13                    return false;
14                }
15            }
16        }
17        return true;
18    }
19};