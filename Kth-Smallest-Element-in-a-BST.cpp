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

    int inorder(TreeNode* node,int &count){
        //left root right

        if(node==nullptr){
            return -1;
        }

        int left = inorder(node->left, count);
        if (left != -1) return left;

        // Visit current node
        count--;
        if (count == 0) return node->val;

        // Traverse right
        return inorder(node->right, count);
    }

    int kthSmallest(TreeNode* root, int k) {
        // queue<TreeNode*>q;
        // vector<int>v;

        // q.push(root);
        // // v.push_back(root->val);
        // while(!q.empty()){
        //     int sz=q.size();
        //     for(int i=0;i<sz;i++){
        //         TreeNode* it=q.front();
        //         q.pop();
        //         v.push_back(it->val);

        //         if(it->left!=nullptr){
        //             q.push(it->left);
        //         }
        //         if(it->right!=nullptr){
        //             q.push(it->right);
        //         }
        //     }
        // }
        // sort(v.begin(),v.end());

        // return v[k-1];
        //we know that inorder traversal of a bst gives a sorted array

        return inorder(root,k);

        // return v[k-1];
        
    }
};