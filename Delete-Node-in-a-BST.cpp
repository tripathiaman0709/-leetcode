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

    TreeNode* helper(TreeNode* node){
        if(node->left==nullptr){
            return node->right;
        }
        if(node->right==nullptr){
            return node->left;
        }
        TreeNode* right=node->right;
        TreeNode* lastright=last(node->left);
        lastright->right=right;

        return node->left;
    }

    TreeNode* last(TreeNode* node){
        if(node->right==nullptr){
            return node;
        }
        return last(node->right);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr){
            return nullptr;
        }
        if(root->val==key){
            return helper(root);
        }
        TreeNode* curr=root;
        while(curr){
            if(curr->val>key){
                if(curr->left!=nullptr && curr->left->val==key){
                    curr->left=helper(curr->left);
                    break;
                }else{
                    curr=curr->left;
                }
            }
            else{
                if(curr->right!=nullptr && curr->right->val==key){
                    curr->right=helper(curr->right);
                    break;
                }else{
                    curr=curr->right;
                }
            }
        }
        return root;

    }
};