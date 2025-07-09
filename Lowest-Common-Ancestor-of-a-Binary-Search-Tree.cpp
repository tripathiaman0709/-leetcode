/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    void fun(TreeNode* root,TreeNode* node,vector<TreeNode*>&v){
        while(root){
            if(root->val>node->val){
                v.push_back(root);
                root=root->left;
            }
            else if(root->val<node->val){
                v.push_back(root);
                root=root->right;
            }else{
                v.push_back(root);
                break;
            }
        }        
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>v1;
        vector<TreeNode*>v2;

        fun(root,p,v1);
        fun(root,q,v2);

        int i = 0;
        int minLen = min(v1.size(), v2.size());

        while (i < minLen && v1[i] == v2[i])
            i++;

        return v1[i - 1]; 
    }
};