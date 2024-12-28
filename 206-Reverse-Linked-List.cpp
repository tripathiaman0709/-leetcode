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
    ListNode* reverseList(ListNode* head) {
        //most asked linked list question
        //using three nodes 
        //prev , curr , next

        ListNode* prevptr=nullptr;
        ListNode* currptr=head;
        ListNode* nextptr;

        while(currptr!=nullptr){
            nextptr=currptr->next;
            //link change
            currptr->next=prevptr;
            //aage move krenge
            prevptr=currptr;
            currptr=nextptr;
        }
        return prevptr;
        
    }
};