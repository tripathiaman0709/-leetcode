1class Solution {
2public:
3    bool uniformArray(vector<int>& v) {
4        int n=v.size();
5        //jo first element hai in sorted array
6        //uski parity toh change nhi ho payegi
7        //hence trying to make all elements parity equal to first element
8
9        sort(v.begin(),v.end());
10        int parity=v[0]%2;
11
12        int odd=0;
13        int even=0;
14
15        for(int i=0;i<n;i++){
16            if(v[i]%2 == parity){
17                if(v[i]%2)odd++;
18                else even++;
19                continue;
20            } 
21
22            if(parity==0 && odd==0){
23                return false;
24            }
25            if(parity==1 && odd==0){
26                return false;
27            }
28
29            if(v[i]%2)odd++;
30            else even++;
31        }
32        return true;
33    }
34};