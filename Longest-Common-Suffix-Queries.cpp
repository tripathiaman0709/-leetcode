1class Solution {
2public:
3    struct TrieNode {
4        int idx;
5        TrieNode* child[26];
6
7        ~TrieNode() {
8            for (int i = 0; i < 26; i++) {
9                if (child[i] != nullptr) {
10                    delete child[i];
11                    child[i] = nullptr;
12                }
13            }
14        }
15    };
16
17    TrieNode* getNode(int i) {
18        TrieNode* newNode = new TrieNode();
19        newNode->idx = i;
20
21        for (int k = 0; k < 26; k++) {
22            newNode->child[k] = NULL;
23        }
24        return newNode;
25    }
26
27    void insert(TrieNode* root, vector<string>& s, int id) {
28        int n = s[id].size();
29        TrieNode* crawl = root;
30        for (int i = n - 1; i >= 0; i--) {
31            int index = s[id][i] - 'a';
32
33            if (crawl->child[index] == NULL) {
34                crawl->child[index] = getNode(id);
35            }
36
37            crawl = crawl->child[index];
38            if (s[crawl->idx].size() > n) {
39                crawl->idx = id;
40            }
41        }
42    }
43    int search(string& s, TrieNode* root) {
44        int res = root->idx;
45        int n = s.size();
46        TrieNode* crawl = root;
47        for (int i = n - 1; i >= 0; i--) {
48            int char_idx = s[i] - 'a';
49
50            crawl = crawl->child[char_idx];
51            if (crawl == NULL) {
52                return res;
53            }
54            res = crawl->idx;
55        }
56        return res;
57    }
58    vector<int> stringIndices(vector<string>& s, vector<string>& q) {
59
60        TrieNode* root = getNode(0);
61
62        for (int i = 0; i < s.size(); i++) {
63            if (s[i].size() < s[root->idx].size()) {
64                root->idx = i;
65            }
66
67            insert(root, s, i);
68        }
69
70        vector<int> ans;
71
72        for (auto& it : q) {
73            ans.push_back(search(it, root));
74        }
75        delete root;
76        return ans;
77    }
78};