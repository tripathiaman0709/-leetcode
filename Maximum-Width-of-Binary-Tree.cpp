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
    int widthOfBinaryTree(TreeNode* root) {
        //super simple
        //just using level order traversal
        //using zero based indexing
        if(root==nullptr){
            return 0;
        }
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int maxi=0;

        while(!q.empty()){
            int sz=q.size();
            int min=q.front().second;
            int first=0;
            int last=0;
            for(int i=0;i<sz;i++){
                int ind=q.front().second-min;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0){
                    first=ind;
                }
                if(i==sz-1){
                    last=ind;
                }
                if(node->left!=nullptr)
                q.push({node->left,(long long)2*ind + 1});
                if(node->right!=nullptr)
                q.push({node->right,(long long)2*ind + 2});

            }
            maxi=max(maxi,last-first+1);
        }
        return maxi;
    }
};