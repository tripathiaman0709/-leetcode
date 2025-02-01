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

    int fun(TreeNode* root,long long sum,int target,unordered_map<long long,int>&mpp){
        if(root==nullptr){
            return 0;
        }
        sum+=root->val;
        int count=mpp[sum-target];
        mpp[sum]++;

        count+=fun(root->left ,sum,target,mpp);
        count+=fun(root->right,sum,target,mpp);

        mpp[sum]--;

        return count;
    }

    int pathSum(TreeNode* root, int target) {
        //super simple solution 
        //just need to use unorordered map here
        //just need to store the prefix sum and the number of occurences

        if(root==nullptr){
            return 0;
        }

        unordered_map<long long,int>mpp;
        mpp[0]=1;
        int sum=0;

        return fun(root,sum,target,mpp);
    }
};