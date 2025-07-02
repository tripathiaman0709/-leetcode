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

    void fun(TreeNode* node,unordered_map<TreeNode*,TreeNode*>&mpp){
        if(node==nullptr){
            return;
        }
        //doing level order traversal bfs style

        queue<TreeNode*>q;
        q.push(node);

        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* it=q.front();
                q.pop();

                if(it->left!=nullptr){
                    mpp[it->left]=it;
                    q.push(it->left);
                }
                if(it->right!=nullptr){
                    mpp[it->right]=it;
                    q.push(it->right);
                }
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //finding all the nodes at distance k from the target node

        unordered_map<TreeNode*,TreeNode*>mpp;
        fun(root,mpp);
        //made the map to connect all nodes to their parents
        unordered_map<TreeNode*,bool>vis;
        
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int count=0;

        while(!q.empty()){
            int sz=q.size();
            if(count==k){
                break;
            }else{
                count++;
            }

            for(int i=0;i<sz;i++){
                TreeNode* it=q.front();
                q.pop();

                if(it->left!=nullptr && vis[it->left]==false){
                    vis[it->left]=true;
                    q.push(it->left);
                }
                if(it->right!=nullptr && vis[it->right]==false){
                    vis[it->right]=true;
                    q.push(it->right);
                }
                if(mpp[it] && vis[mpp[it]]==false){
                    vis[mpp[it]]=true;
                    q.push(mpp[it]);
                }
            }
        }
        vector<int>ans;
            while(!q.empty()){
                ans.push_back(q.front()->val);
                q.pop();
            }
            return ans;
    }
};