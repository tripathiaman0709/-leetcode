/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool fun(TreeNode* node,TreeNode* p,vector<TreeNode*>&v){
        if(node==NULL){
            return false;
        }
        v.push_back(node);
        if(node==p){
            return true;
        }
        if(fun(node->left,p,v)||fun(node->right,p,v)){
            return true;
        }

        v.pop_back();

        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //finding the lowest common ancestor of two nodes

        //firstly making the root to node path of both the nodes
        //then going through the path and finding the last common node

        if(root==nullptr){
            return root;
        }

        vector<TreeNode*>v1;
        vector<TreeNode*>v2;

        fun(root,p,v1);
        fun(root,q,v2);

        int i=0;
        int j=0;

        TreeNode* ans;

        while(i < v1.size() && j < v2.size() && v1[i] == v2[j]){
            ans=v1[i];
            i++;
            j++;
        }

        return ans;
    }
};