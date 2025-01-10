class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Doing any type of traversal on both root nodes
        // If the ordering is the same then same tree else not
        vector<vector<int>> ans1;
        vector<vector<int>> ans2;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        q1.push(p);
        q2.push(q);

        while (!q1.empty()) {
            int sz = q1.size();
            vector<int> row;
            for (int i = 0; i < sz; i++) {
                auto node = q1.front();
                q1.pop();
                if (node) {
                    row.push_back(node->val);
                    q1.push(node->left);
                    q1.push(node->right);
                } else {
                    row.push_back(-101); // Placeholder for null
                }
            }
            ans1.push_back(row);
        }

        while (!q2.empty()) {
            int sz = q2.size();
            vector<int> row;
            for (int i = 0; i < sz; i++) {
                auto node = q2.front();
                q2.pop();
                if (node) {
                    row.push_back(node->val);
                    q2.push(node->left);
                    q2.push(node->right);
                } else {
                    row.push_back(-101); // Placeholder for null
                }
            }
            ans2.push_back(row);
        }

        return ans1 == ans2;
    }
};
