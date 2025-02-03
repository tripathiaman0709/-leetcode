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
        traversal(root->left,v);
        v.push_back(root->val);
        traversal(root->right,v);
    }

    bool findTarget(TreeNode* root, int k) {
        //doing simple inorder traversal and finding the sorted array
        //then using simple two pointer approach solving the problem
        vector<int>v;
        traversal(root,v);
        int n=v.size();
        int l=0;
        int r=n-1;
        while(l<r){
            if(v[l]+v[r]==k){
                return true;
            }else if(v[l]+v[r]>k){
                r--;
            }else{
                l++;
            }
        }
        return false;
    }
};