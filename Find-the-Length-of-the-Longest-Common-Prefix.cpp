1class Solution {
2public:
3    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
4        //putting elements in the hashset
5        vector<int>a;
6        vector<int>b;
7        unordered_set<string>hash;
8        if(arr1.size()>arr2.size()){
9            a=arr2;
10            b=arr1;
11        }else{
12            a=arr1;
13            b=arr2;
14        }
15
16        for(int i=0;i<a.size();i++){
17            int num=a[i];
18            while(num){
19                hash.insert(to_string(num));
20                num/=10;
21            }
22        }
23        int maxi=0;
24        for(int i=0;i<b.size();i++){
25            int num=b[i];
26            while(num && hash.count(to_string(num))==0){
27                num/=10;
28            }
29            if(num){
30                string s=to_string(num);
31                int size=s.size();
32                maxi=max(maxi,size);
33            }
34        }
35        return maxi;
36    }
37};