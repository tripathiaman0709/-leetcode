1class Solution {
2public:
3    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
4        int m = box.size();
5        int n = box[0].size();
6
7        vector<vector<char>> result(n, vector<char>(m));
8
9        //Transpose
10        for(int i = 0; i < n; i++) {
11            for(int j = 0; j < m; j++) {
12                result[i][j] = box[j][i];
13            }
14        }
15
16        //90 degree k lie - Reverse kardo ahr row ko
17        for(vector<char>& row : result) {
18            reverse(begin(row), end(row));
19        }
20
21
22        //Apply the gravity
23        //O(col * row)
24        for(int j = 0; j < m; j++) {
25            int spaceBottomRow = n-1;
26            for(int i = n-1; i >= 0; i--) {
27                if(result[i][j] == '*') {
28                    spaceBottomRow = i-1;
29                    continue;
30                }
31
32                if(result[i][j] == '#') {
33                    result[i][j] = '.';
34                    result[spaceBottomRow][j] = '#';
35                    spaceBottomRow--;
36                }
37            }
38        }
39
40        return result;
41    }
42};
43