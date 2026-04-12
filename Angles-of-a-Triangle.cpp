1class Solution {
2public:
3    vector<double> internalAngles(vector<int>& vec) {
4        vector<int> v = vec;
5        int n = v.size();
6        vector<double> ans;
7
8        sort(v.begin(), v.end());
9
10        // Triangle validity
11        if (v[0] + v[1] <= v[2]) return ans;
12
13        // Law of Cosines
14        double a = v[0], b = v[1], c = v[2];
15
16        double A = acos((b*b + c*c - a*a) / (2.0 * b * c)) * 180.0 / M_PI;
17        double B = acos((a*a + c*c - b*b) / (2.0 * a * c)) * 180.0 / M_PI;
18        double C = 180.0 - (A + B);
19
20        ans.push_back(A);
21        ans.push_back(B);
22        ans.push_back(C);
23
24        sort(ans.begin(), ans.end());
25        return ans;
26    }
27};