1class Solution {
2public:
3    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& w) {
4        sort(w.begin(),w.end());
5        sort(h.begin(),h.end());
6
7        //finding longest continuous subarray in both height and width
8        int height=1;
9        int count=1;
10        
11        for(int i=1;i<h.size();i++){
12            if(h[i]==h[i-1]+1){
13                count++;
14            }else{
15                count=1;
16            }
17            height=max(height,count);
18        }
19
20        int width=1;
21        int mount=1;
22        
23        for(int i=1;i<w.size();i++){
24            if(w[i]==w[i-1]+1){
25                mount++;
26            }else{
27                mount=1;
28            }
29            width=max(width,mount);
30        }
31
32        int val=min(height,width);
33        val++;
34        return val*val;
35    }
36};