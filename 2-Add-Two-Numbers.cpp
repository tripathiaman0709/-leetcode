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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //we just need to add the numbers using carry 
        //and return head of newly made linked list

        ListNode* t1=l1;
        ListNode* t2=l2;
        //creating a dummy node whenever we require to make a new linked list
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        int carry=0;
        while(t1!=nullptr || t2!=nullptr){
            int sum=carry;
            if(t1!=nullptr){
                sum+=t1->val;
            }
            if(t2!=nullptr){
                sum+=t2->val;
            }
            carry=sum/10;
            int newval=sum%10;
            ListNode* nodetoadd=new ListNode(newval);

            curr->next=nodetoadd;
            curr=curr->next;

            if(t1!=nullptr){
                t1=t1->next;
            }
            if(t2!=nullptr){
                t2=t2->next;
            }
        }
        if(carry){
            ListNode* newnodetoadd=new ListNode(carry);
            curr->next=newnodetoadd;
        }
        return dummy->next;
    }
};