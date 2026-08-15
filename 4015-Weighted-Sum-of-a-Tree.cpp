class Solution {
public:
    long long weightedSum(vector<int>& p, vector<int>& v) {

        int n = p.size();

        vector<vector<int>> adj(n);

        // Build tree
        for(int i = 1; i < n; i++) {
            adj[p[i]].push_back(i);
        }

        // Find depth of every node and height
        vector<int> depth(n);

        queue<int> q;
        q.push(0);

        depth[0] = 1;
        int h = 1;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            h = max(h, depth[node]);

            for(int child : adj[node]) {
                depth[child] = depth[node] + 1;
                q.push(child);
            }
        }

        // Calculate weighted sum
        long long ans = 0;

        for(int i = 0; i < n; i++) {
            ans += 1LL * v[i] * (h - depth[i] + 1);
        }

        return ans;
    }
};