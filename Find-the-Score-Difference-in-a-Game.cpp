1class Solution {
2public:
3    int scoreDifference(vector<int>& v) {
4        int n=v.size();
5        int first=0;
6        int second=0;
7        int count=0;
8        for(int i=0;i<n;i++){
9            if(v[i]%2){
10                swap(first,second);
11                count++;
12            }
13            if(i%6==5){
14                swap(first,second);
15                count++;
16            }
17
18            first+=v[i];
19        }
20        int diff=0;
21        if(count%2){
22            diff=(second-first);
23        }else{
24            diff=(first-second);
25        }
26        return diff;
27    }
28};