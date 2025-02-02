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

    void traversal(TreeNode* root,vector<int>&v){
        if(root==nullptr){
            return;
        }
        //left root right

        traversal(root->left,v);
        v.push_back(root->val);
        traversal(root->right,v);
    }

    int kthSmallest(TreeNode* root, int k) {
        //doing and storing a simple inorder traversal

        vector<int>v;
        traversal(root,v);

        int ans=v[k-1];

        return ans;    
    }
};