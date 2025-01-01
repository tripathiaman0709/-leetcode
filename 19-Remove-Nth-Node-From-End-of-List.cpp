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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        //trying naive approach
        //finding total length
        k++;
        ListNode* temp=head;
        int n=1;
        while(temp!=nullptr){
            n++;
            temp=temp->next;
        }
        int pos=n-k+1;
        //now question simply becomes deleting node from position pos
        if(pos==1 && n==1){
            return nullptr;
        }
        if(pos==1 && n>1){
            ListNode* start=head;
            return head->next;
            delete start;
        }

            int count=1;
            ListNode* temp1=head;
            while(count!=pos-1){
                temp1=temp1->next;
                count++;
            }
            if(pos==n){
                temp1->next=nullptr;
                return head;
            }else{
                temp1->next=temp1->next->next;
                // ListNode* todelete=temp1->next;
                // delete todelete;
                return head;
            }
        

    }
};