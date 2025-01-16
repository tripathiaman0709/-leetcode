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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //so lets try to solve this supposedly or maybe really hard problem 
        //its just based on the use of node vertical and level 
        //and to store them we need map to store it

        map<int,map<int,multiset<int>>>mpp;
        //now simply doing level order traversal

        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});

        while(!q.empty()){
            auto it=q.front();
            q.pop();

            TreeNode* node=it.first;
            int ver=it.second.first;
            int lvl=it.second.second;

            mpp[ver][lvl].insert(node->val);
            if(node->left!=nullptr){
                q.push({node->left,{ver-1,lvl+1}});
            }
            if(node->right!=nullptr){
                q.push({node->right,{ver+1,lvl+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto it:mpp){
            vector<int>v;
            for(auto x:it.second){
                //inserting the sorted multiset to the back of vector v
                v.insert(v.end(),x.second.begin(),x.second.end());
            }
            ans.push_back(v);
        }
        return ans;      
    }
};