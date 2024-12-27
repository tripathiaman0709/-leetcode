/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        //checking if the last node is same or not
        //if not then will return nullptr
        //else will find the interection node

        ListNode* temp1=headA;
        ListNode* temp2=headB;
        int sizeA=1;
        int sizeB=1;
        while(temp1->next!=nullptr){
            temp1=temp1->next;
            sizeA++;
        }
        while(temp2->next!=nullptr){
            temp2=temp2->next;
            sizeB++;
        }

        if(temp1!=temp2){
            return nullptr;
        }

        //so now there existes an intersection point
        if(sizeA<=sizeB){
            ListNode* tempB=headB;
            ListNode* tempA=headA;
            int diff=sizeB-sizeA;
            while(diff>0){
                tempB=tempB->next;
                diff--;
            }
            //now both heads are at same difference from intersection node
            while(tempB != tempA){
                tempB=tempB->next;
                tempA=tempA->next;
            }
            return tempA;
        }else{
            ListNode* tempA=headA;
            ListNode* tempB=headB;
            int diff=sizeA-sizeB;
            while(diff>0){
                tempA=tempA->next;
                diff--;
            }
            //now both heads are at same difference from intersection node
            while(tempA != tempB){
                tempA=tempA->next;
                tempB=tempB->next;
            }
            return tempB;
        }
    }
};