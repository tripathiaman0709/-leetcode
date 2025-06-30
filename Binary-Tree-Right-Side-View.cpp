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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==nullptr){
            return ans;
        }

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int sz=q.size();
            vector<int>temp;
            for(int i=0;i<sz;i++){
                auto it=q.front();
                q.pop();
                temp.push_back(it->val);

                if(it->left!=nullptr){
                    q.push(it->left);
                }
                if(it->right!=nullptr){
                    q.push(it->right);
                }
            }
            ans.push_back(temp[sz-1]);
        }

        return ans;
        
    }
};