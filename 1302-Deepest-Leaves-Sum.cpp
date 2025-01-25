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
    int deepestLeavesSum(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=-1;
        while(!q.empty()){
            int sz=q.size();
            int sum=0;
            for(int i=0;i<sz;i++){
                auto x=q.front();
                q.pop();
                TreeNode* node=x.first;
                int lvl=x.second;

                sum+=node->val;
                if(node->left!=nullptr){
                    q.push({node->left,lvl+1});
                }
                if(node->right!=nullptr){
                    q.push({node->right,lvl+1});
                }
            }
            ans=sum;
        }
        return ans;
    }
};