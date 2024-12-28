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
    bool isPalindrome(ListNode* head) {
        //reversing it and checking if its same 
        ListNode* temp=head;
        vector<int>v1;
        vector<int>v2;
        while(temp!=nullptr){
            v1.push_back(temp->val);
            temp=temp->next;
        }
        //now reversing the linked list
        ListNode* prevptr=nullptr;
        ListNode* currptr=head;
        ListNode* nextptr;

        while(currptr!=nullptr){
            nextptr=currptr->next;
            currptr->next=prevptr;

            prevptr=currptr;
            currptr=nextptr;
        }
        ListNode* temp2=prevptr;
        while(temp2!=nullptr){
            v2.push_back(temp2->val);
            temp2=temp2->next;
        }
        if(v1==v2){
            return true;
        }
        return false;
    }
};