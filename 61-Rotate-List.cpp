/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //making a vector
        //solving the problem as vector and then at last replacing the values in the linked list

        vector<int>v;
        ListNode* temp=head;
        while(temp!=nullptr){
            v.push_back(temp->val);
            temp=temp->next;
        }
        vector<int>rotate=v;
        int n=v.size();
        for(int i=0;i<n;i++){
            rotate[(i+k)%n]=v[i];
        }
        ListNode* start=head;
        int x=0;
        while(start!=nullptr){
            start->val=rotate[x++];
            start=start->next;
        }
        return head;
    }
};