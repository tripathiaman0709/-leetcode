1class Solution {
2public:
3
4    // bool check(vector<int>&v,int k){
5    //     int n=v.size();
6    //     int count=0;
7    //     for(auto it:v){
8    //         if(it==k){
9    //             count++;
10    //         }
11    //     }
12    //     int mid=n/2;
13    //     return (count>mid);
14    // }
15
16    int countMajoritySubarrays(vector<int>& v, int k) {
17        //simply making all subarrays and counting as the constraints are pretty small
18        int n=v.size();
19        int count=0;
20        //rather than checking the count of k by iterating the entire array we can use prefix array 
21        vector<int>pre(n+1,0);
22        int sum=0;
23        for(int i=1;i<=n;i++){
24            if(v[i-1]==k){
25                sum++;
26                pre[i]=sum;
27            }else{
28                pre[i]=sum;
29            }
30        }
31        for(int i=0;i<n;i++){
32            for(int j=i;j<n;j++){
33                int total=j-i+1;
34                int half=total/2;
35                int freqk=pre[j+1]-pre[i];
36                if(freqk>half){
37                    count++;
38                }
39            }
40        }
41        return count;
42    }
43};