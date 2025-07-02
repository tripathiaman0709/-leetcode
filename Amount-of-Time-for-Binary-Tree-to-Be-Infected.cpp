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

    void fun(TreeNode* node,unordered_map<TreeNode*,TreeNode*>&mpp){
        if(node==nullptr){
            return;
        }
        //bfs style traversal maarenge
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

    TreeNode* find(TreeNode* node, int start){
        if (node == nullptr) return nullptr;
        if (node->val == start) return node;

        TreeNode* left = find(node->left, start);
        if (left) return left;

        TreeNode* right = find(node->right, start);
        return right;
    }

    int amountOfTime(TreeNode* root, int start) {
        //saare nodes ke parents ko map krdo 
        unordered_map<TreeNode*,TreeNode*>mpp;
        fun(root,mpp);
        TreeNode* target=find(root,start);

        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int count=0;

        while(!q.empty()){
            int sz=q.size();
            count++;
            for(int i=0;i<sz;i++){
                TreeNode* it=q.front();
                q.pop();

                if(it->left!=nullptr && !vis[it->left]){
                    vis[it->left]=true;
                    q.push(it->left);
                }
                if(it->right!=nullptr && !vis[it->right]){
                    vis[it->right]=true;
                    q.push(it->right);
                }
                if(mpp[it] && vis[mpp[it]]==false){
                    vis[mpp[it]]=true;
                    q.push(mpp[it]);
                }
            }
        }
        return count-1;
    }
};