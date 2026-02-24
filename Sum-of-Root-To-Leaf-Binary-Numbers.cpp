1class Solution {
2public:
3    int sumRootToLeaf(TreeNode* root) {
4        return dfs(root, 0);
5    }
6
7private:
8    int dfs(TreeNode* node, int curr) {
9        if (!node) return 0;
10
11        curr = curr * 2 + node->val; // append this bit
12
13        if (!node->left && !node->right) // leaf
14            return curr;
15
16        return dfs(node->left, curr) + dfs(node->right, curr);
17    }
18};