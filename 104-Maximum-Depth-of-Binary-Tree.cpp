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
    int maxDepth(TreeNode* root) {
        //looks like counting the total number of levels
        //through traversal like bfs
        //that is level wise traversal 
        //so using queue
        if(root==nullptr){
            return 0;
        }
        TreeNode* node=root;
        queue<TreeNode*>q;
        q.push(node);
        int count=0;
        while(!q.empty()){
            int sz=q.size();
            count++;
            for(int i=0;i<sz;i++){
                TreeNode* nd=q.front();
                q.pop();
                if(nd->left!=nullptr){
                    q.push(nd->left);
                }
                if(nd->right!=nullptr){
                    q.push(nd->right);
                }
            }
        }
        return count;
    }
};