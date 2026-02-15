1class Solution {
2public:
3    string addBinary(string a, string b) {
4        int i = a.size() - 1;
5        int j = b.size() - 1;
6        int carry = 0;
7        
8        string result = "";
9        
10        while (i >= 0 || j >= 0 || carry) {
11            int sum = carry;
12            
13            if (i >= 0) {
14                sum += a[i] - '0';
15                i--;
16            }
17            
18            if (j >= 0) {
19                sum += b[j] - '0';
20                j--;
21            }
22            
23            result += (sum % 2) + '0';
24            
25            carry = sum / 2;
26        }
27        
28        reverse(result.begin(), result.end());
29        
30        return result;
31    }
32};