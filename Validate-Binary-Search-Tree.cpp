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

    void inorder(TreeNode* node,vector<int>&v){
        if(node==nullptr){
            return;
        }
        //left root right
        inorder(node->left,v);
        v.push_back(node->val);
        inorder(node->right,v);

    }

    bool isValidBST(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        vector<int>v;
        inorder(root,v);
        if(v.size()==1){
            return true;
        }
        for(int i=0;i<v.size()-1;i++){
            if(v[i]>=v[i+1]){
                return false;
            }
        }
        return true;
    }
};