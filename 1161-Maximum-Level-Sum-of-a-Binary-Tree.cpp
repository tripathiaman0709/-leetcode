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
    int maxLevelSum(TreeNode* root) {
        //using simple bfs or level order traversal to find the sum obtained on each level then updating the maximum
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int maxi=1;
        int level=1;
        int maxsum=INT_MIN;
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
            if(sum>maxsum){
                maxsum=sum;
                maxi=level;
            }
            level++;                        
        }
        return maxi;
    }
};