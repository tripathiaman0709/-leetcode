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
    TreeNode* insertIntoBST(TreeNode* node, int key) {
        if(node==nullptr){
            return new TreeNode(key);
        }
        TreeNode* root=node;
        while(true){            
            if(key<root->val){
                if(root->left!=nullptr){
                    root=root->left;
                }else{
                    root->left=new TreeNode(key);
                    break;
                }
            }
            else{
                if(root->right!=nullptr){
                    root=root->right;
                }else{
                    root->right=new TreeNode(key);
                    break;
                }
            }            
        }
        return node;
    }
};