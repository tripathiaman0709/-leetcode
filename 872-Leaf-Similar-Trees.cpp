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

    void dfs1(TreeNode* root,vector<int>&r1){
        if(root==nullptr){
            return;
        }
        if(root->left==nullptr && root->right==nullptr){
            r1.push_back(root->val);
        }

        if(root->left!=nullptr){
            dfs1(root->left,r1);
        }
        if(root->right!=nullptr){
            dfs1(root->right,r1);
        }
    }

    void dfs2(TreeNode* root,vector<int>&r2){
        if(root==nullptr){
            return;
        }
        if(root->left==nullptr && root->right==nullptr){
            r2.push_back(root->val);
        }

        if(root->left!=nullptr){
            dfs2(root->left,r2);
        }
        if(root->right!=nullptr){
            dfs2(root->right,r2);
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        //super simple 
        //just the sum of all leaf nodes

        vector<int>r1;
        vector<int>r2;

        dfs1(root1,r1);
        dfs2(root2,r2);

        if(r1==r2){
            return true;
        } 
        return false;


        
    }
};