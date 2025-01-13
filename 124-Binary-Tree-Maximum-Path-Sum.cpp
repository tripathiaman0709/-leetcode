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

    int fun(TreeNode* node,int &maxi){
        //base case
        if(node==nullptr){
            return 0;
        }

        int lh=max(0,fun(node->left,maxi));
        int rh=max(0,fun(node->right,maxi));
        maxi=max(maxi,node->val + lh + rh);
        return node->val + max(lh,rh);
    }

    int maxPathSum(TreeNode* root) {
        //mann!!
        //how come it comes under hard problem
        //lets try simple recursive approach

        int maxi=INT_MIN;
        fun(root,maxi);
        return maxi;
    }
};