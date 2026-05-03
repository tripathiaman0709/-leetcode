1class Solution {
2public:
3    vector<int> countOppositeParity(vector<int>& v) {
4        int n=v.size();
5        vector<int>ans(n,0);
6
7        // for(int i=0;i<n-1;i++){
8        //     int count=0;
9        //     int parity=v[i]%2;
10        //     for(int j=i+1;j<n;j++){
11        //         int nparity=v[j]%2;
12        //         if(parity!=nparity)count++;
13        //     }
14        //     ans[i]=count;
15        // }
16
17
18        //now solving it in O(n) approach
19
20        vector<int>even(n,0);
21        vector<int>odd(n,0);
22        int codd=0;
23        int ceven=0;
24        for(int i=0;i<n;i++){
25            if(v[i]%2){
26                codd++;
27            }else{
28                ceven++;
29            }
30
31            odd[i]=codd;
32            even[i]=ceven;
33        }
34
35        for(int i=0;i<n-1;i++){
36            if(v[i]%2){
37                ans[i]=even[n-1]-even[i];
38            }else{
39                ans[i]=odd[n-1]-odd[i];
40            }
41        }
42        
43        return ans;
44    }
45};