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

    // void fun(TreeNode* node,int &count){
    //     if(node==nullptr){
    //         return;
    //     }
    //     count++;
    //     fun(node->left,count);
    //     fun(node->right,count);
    // }

    int fun(TreeNode* node){
        if(node==nullptr){
            return 0;
        }
        if(lefth(node)==righth(node)){
            return (1<<lefth(node))-1;
        }

        return 1+fun(node->left)+fun(node->right);
    }

    int lefth(TreeNode* node){
        int count=0;
        while(node){
            count++;
            node=node->left;
        }
        return count;
    }

    int righth(TreeNode* node){
        int count=0;
        while(node){
            count++;
            node=node->right;
        }
        return count;
    }

    int countNodes(TreeNode* root) {
        return fun(root);
    }
};