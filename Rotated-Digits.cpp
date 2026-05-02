1class Solution {
2public:
3    int rotatedDigits(int n) {
4        int ans=0;
5        for(int i=1;i<=n;i++){
6            int num=i;
7            bool valid=1;
8            bool change=0;
9            while(num){
10                int digit=num%10;
11                if(digit==3 || digit==4 || digit==7){
12                    valid=0;
13                    break;
14                }
15                if(digit==5 || digit==2 || digit==6 || digit==9){
16                    change=1;
17                }
18                num/=10;
19            }
20            if(valid && change>0){
21                ans++;
22            }
23        }
24        return ans;
25    }
26};