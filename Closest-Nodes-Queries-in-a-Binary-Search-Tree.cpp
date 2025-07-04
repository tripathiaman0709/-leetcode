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

    int flr(TreeNode* node,int k){
        int x=-1;
        while(node){
            if(node->val<=k){
                x=node->val;
                node=node->right;
            }else{
                node=node->left;
            }
        }       

        return x;
    }


    int cl(TreeNode* node,int k){
        int x=-1;
        while(node){
            if(node->val>=k){
                x=node->val;
                node=node->left;
            }else{
                node=node->right;
            }
        }       

        return x;
    }
 

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& que) {
        //similar to finding floor and ceil of a bst
        // int n=q.size();
        // vector<vector<int>>ans;
        // for(int i=0;i<n;i++){
        //     vector<int>temp;
        //     int x=flr(root,q[i]);
        //     int y=cl(root,q[i]);
        //     temp.push_back(x);
        //     temp.push_back(y);

        //     ans.push_back(temp);
        // }

        // return ans;
        vector<int>v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* it=q.front();
                q.pop();

                v.push_back(it->val);

                if(it->left!=nullptr){
                    q.push(it->left);
                }
                if(it->right!=nullptr){
                    q.push(it->right);
                }
            }
        }

        sort(v.begin(),v.end());

        int n=que.size();
        vector<vector<int>>ans;
        for (int q : que) {
            int floor = -1, ceil = -1;

            // Floor: largest <= q
            auto it = upper_bound(v.begin(), v.end(), q);
            if (it != v.begin()) {
                floor = *(--it);
            }

            // Ceil: smallest >= q
            it = lower_bound(v.begin(), v.end(), q);
            if (it != v.end()) {
                ceil = *it;
            }

            ans.push_back({floor, ceil});
        }

        return ans;


    }
};