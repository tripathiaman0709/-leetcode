1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    TreeNode* createBinaryTree(vector<vector<int>>& v) {
15        int n=v.size();
16        unordered_set<int>st;
17        unordered_map<int,TreeNode*>mpp;
18        for(int i=0;i<n;i++){
19            int parent=v[i][0];
20            int child=v[i][1];
21            int left=v[i][2];
22
23            if(mpp.find(parent)==mpp.end()){
24                mpp[parent]=new TreeNode(parent);
25            }
26            if(mpp.find(child)==mpp.end()){
27                mpp[child]=new TreeNode(child);
28            }
29
30            if(left){
31                mpp[parent]->left=mpp[child];
32            }else{
33                mpp[parent]->right=mpp[child];
34            }
35
36            st.insert(child);
37        }
38
39        for(int i=0;i<n;i++){
40            int parent=v[i][0];
41
42            if(st.find(parent)==st.end()){
43                return mpp[parent];
44                //returns the root node
45            }
46        }
47
48        return nullptr;
49    }
50};