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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //using the property of binary tree itself to solve it

        if(root==nullptr){
            return new TreeNode(val);
        }

        TreeNode* node = root;

        while(true){
            if(node->val>=val){
            //we go left
            if(node->left!=nullptr){
                node=node->left;
            }else{
                node->left=new TreeNode(val);
                break;
            }
        }else{
            //we go right
            if(node->right!=nullptr){
                node=node->right;
            }else{
                node->right=new TreeNode(val);
                break;
            }
        }
        }

        return root;
    }
};