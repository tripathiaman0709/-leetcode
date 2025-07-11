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
    TreeNode* invertTree(TreeNode* root) {
        //matlab mirror krna hai
        //swapping hogi
        //left node right ban jaayegi and vice versa

        //pehle swap kro
        //fir left aur right vale cases ko call kro

        //and base case hoga when root == NULL
        

        //base case
        if(root==nullptr){
            return root;
        }
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;

    }
};