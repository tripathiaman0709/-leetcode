1class Solution {
2public:
3    vector<bool> isPrime;
4    
5    void buildSieve(int maxEl) {
6        //fill isPrime
7        isPrime.resize(maxEl+1, true);
8
9        isPrime[0] = false;
10        isPrime[1] = false;
11
12        for(int num = 2; num*num <= maxEl; num++) {
13            if(isPrime[num]) {
14
15                for(int multiple = num*num; multiple <= maxEl; multiple += num) {
16                    isPrime[multiple] = false;
17                }
18            }
19        }
20    }
21
22    int minJumps(vector<int>& nums) {
23        int n = nums.size();
24
25        unordered_map<int, vector<int>> mp; //element -> indices
26        int maxEl = 0;
27        for(int i = 0; i < n; i++) {
28            mp[nums[i]].push_back(i);
29            maxEl = max(maxEl, nums[i]);
30        }
31
32        //build isPrime vector using Sieve
33        buildSieve(maxEl); //O(maxEL * loglog(maxEl));
34
35        queue<int> que;
36        vector<bool> visited(n, false);
37        que.push(0);
38        visited[0] = true;
39
40        unordered_set<int> seen;
41
42        int steps = 0;
43        //We visite each node only once - O(n)
44        //O(n + maxEL * loglog(maxEl));
45        while(!que.empty()) {
46            int size = que.size();
47            
48            while(size--) {
49                int i = que.front();
50                que.pop();
51
52                if(i == n-1) {
53                    return steps;
54                }
55
56                if(i-1 >= 0 && !visited[i-1]) {
57                    que.push(i-1);
58                    visited[i-1] = true;
59                }
60
61                if(i+1 <= n-1 && !visited[i+1]) {
62                    que.push(i+1);
63                    visited[i+1] = true;
64                }
65
66                if(!isPrime[nums[i]] || seen.count(nums[i])) {
67                    continue;
68                }
69
70                for(int multiple = nums[i]; multiple <= maxEl; multiple += nums[i]) {
71                    if(!mp.contains(multiple)) {
72                        continue;
73                    }
74
75                    for(int &j : mp[multiple]) {
76                        if(!visited[j]) {
77                            que.push(j);
78                            visited[j] = true;
79                        }
80                    }
81                }
82
83                seen.insert(nums[i]);
84            }
85
86            steps++;
87        }
88
89        return steps;
90    }
91};