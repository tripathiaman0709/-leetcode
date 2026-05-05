1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* rotateRight(ListNode* head, int k) {
14        //making a vector
15        //solving the problem as vector and then at last replacing the values in the linked list
16
17        vector<int>v;
18        ListNode* temp=head;
19        while(temp!=nullptr){
20            v.push_back(temp->val);
21            temp=temp->next;
22        }
23        vector<int>rotate=v;
24        int n=v.size();
25        for(int i=0;i<n;i++){
26            rotate[(i+k)%n]=v[i];
27        }
28        ListNode* start=head;
29        int x=0;
30        while(start!=nullptr){
31            start->val=rotate[x++];
32            start=start->next;
33        }
34        return head;
35    }
36};