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
    vector<int> inorderTraversal(TreeNode* root) {
        //writing a single code that will handle all pre , post and inorder traversal

        vector<int>pre;
        vector<int>post;
        vector<int>in;

        //using pair of node and int in stack

        stack<pair<TreeNode*,int>>st;
        st.push({root,1});

        while(!st.empty()){
            auto it=st.top();
            st.pop();

            if(it.second==1){
                if(it.first!=nullptr){
                pre.push_back(it.first->val);
                it.second++;
                st.push({it.first,it.second});
                if(it.first->left!=nullptr){
                    st.push({it.first->left,1});
                }
                }
            }else if(it.second==2){
                if(it.first!=nullptr){
                in.push_back(it.first->val);
                it.second++;
                st.push({it.first,it.second});
                if(it.first->right!=nullptr){
                    st.push({it.first->right,1});
                }
                }
            }else{
                if(it.first!=nullptr){
                post.push_back(it.first->val);
                }
            }
        }
        return in;
    }
};