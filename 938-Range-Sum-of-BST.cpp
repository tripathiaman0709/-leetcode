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
    int rangeSumBST(TreeNode* root, int low, int high) {
        //super easy problem
        //barely an inconvinience

        //doing simple level wise traversal 
        //using queue
        // int sum=0;
        // queue<TreeNode*>q;
        // q.push(root);
        // while(!q.empty()){
        //     int sz=q.size();
        //     for(int i=0;i<sz;i++){
        //         auto node=q.front();
        //         q.pop();
        //         if(node->val >=low && node->val <=high){
        //             sum+=node->val;
        //         }
        //         if(node->left!=nullptr){
        //             q.push(node->left);
        //         }
        //         if(node->right!=nullptr){
        //             q.push(node->right);
        //         }
        //     }
        // }
        // return sum;

        if(root==nullptr){
            return 0;
        }
        if(root->val>=low && root->val<=high){
            return root->val +rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
        }
        else {
             return rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
        }
    }
};