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
    int minDepth(TreeNode* root) {
        //finding the minimum height or deth of a binary tree
        //firstly trying simple easy way 
        //level wise traversal
        //the moment we encounter both left and right nodes as nullptr then that means we encountered leaf node

        int count=0;
        if(root==nullptr){
            return count;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            count++;
            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();

                if(node->left==nullptr && node->right==nullptr){
                    //leaf node encountered
                    return count;
                }
                if(node->left!=nullptr){
                    q.push(node->left);
                }
                if(node->right!=nullptr){
                    q.push(node->right);
                }
                
            }
        }
        return count;
    }
};