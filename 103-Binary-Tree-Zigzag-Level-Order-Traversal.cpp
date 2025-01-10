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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //simple level wise traversal 
        //just introducing a left to right bool to check whether to go left to right or right to left

        vector<vector<int>>ans;
        if(root==nullptr){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        bool ltor=true;
        while(!q.empty()){
            int sz=q.size();
            vector<int>row;
            
            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();
                row.push_back(node->val);
                if(node->left!=nullptr){
                    q.push(node->left);
                }
                if(node->right!=nullptr){
                    q.push(node->right);
                }
            }
            if(!ltor){
                reverse(row.begin(),row.end());
            }
            ans.push_back(row);
            ltor=!ltor;
        }
        return ans;
    }
};