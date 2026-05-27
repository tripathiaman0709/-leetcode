1class Solution {
2public:
3    int numberOfSpecialChars(string s) {
4        int n=s.size();
5
6        unordered_map<char,int>lmpp;
7        unordered_map<char,int>umpp;
8
9        //storing the last index of small letter
10        for(int i=0;i<n;i++){
11            //storing for lower case
12            if(s[i]>92){
13                lmpp[s[i]]=i+1;
14            }
15        }
16        //storing the first index of big letter
17
18        for(int i=n-1;i>=0;i--){
19            //storing for upper case
20            if(s[i]<92){
21                umpp[s[i]]=i+1;
22            }
23        }
24
25        int count=0;
26        for(int i=0;i<n;i++){
27            if(s[i]>92){
28                int last_ind=lmpp[s[i]];
29                int first_ind=umpp[s[i]-32];
30
31                if(lmpp[(s[i])]==0 || umpp[(s[i]-32)]==0)continue;
32
33                if(last_ind < first_ind){
34                    count++;
35                }
36                lmpp[s[i]]=0;
37                umpp[s[i]-32]=0;
38            }
39        }
40        return count;
41    }
42};