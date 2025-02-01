/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int dfs(TreeNode* root,int maxi){
        if(root==nullptr){
            return 0;
        }
        int count=0;
        if(root->val>=maxi){
            count=1;
        }

        maxi=max(maxi,root->val);

        return count+dfs(root->left,maxi)+dfs(root->right,maxi);
    }

    int goodNodes(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        return dfs(root,root->val);
    }
};