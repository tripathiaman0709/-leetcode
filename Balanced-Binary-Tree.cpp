1class Solution {
2public:
3    int height(TreeNode* root) {
4        if (!root) return 0;
5
6        int lh = height(root->left);
7        if (lh == -1) return -1;
8
9        int rh = height(root->right);
10        if (rh == -1) return -1;
11
12        if (abs(lh - rh) > 1) return -1;
13
14        return 1 + max(lh, rh);
15    }
16
17    bool isBalanced(TreeNode* root) {
18        return height(root) != -1;
19    }
20};