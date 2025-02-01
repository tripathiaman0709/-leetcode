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
    vector<vector<int>>ans;

    void fill(TreeNode* root,int sum,int target,vector<int>&temp){
        if(root==nullptr){
            return;
        }
        sum+=root->val;
        temp.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr){
            if(sum==target){
                ans.push_back(temp);
            }
            sum-=root->val;
            temp.pop_back();

            return;
        }
        fill(root->left ,sum,target,temp);
        fill(root->right,sum,target,temp);

        sum-=root->val;
        temp.pop_back();

        return;

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<int>temp;
        int sum=0;

        if(root==nullptr){
            return ans;
        }
        fill(root,sum,targetSum,temp);
        return ans;
    }
};