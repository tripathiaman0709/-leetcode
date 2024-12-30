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
    ListNode* partition(ListNode* head, int x) {
        //making a new list altogether
        //so will need dummy node
        vector<int>v1;
        vector<int>v2;

        //ListNode* dummy=head;
        ListNode* temp1=head;

        while(temp1!=nullptr){
            if(temp1->val >= x){
                v2.push_back(temp1->val);
            }else{
                v1.push_back(temp1->val);
            }
            temp1=temp1->next;
        }
        int sz1=v1.size();
        int sz2=v2.size();
        int s=0;
        int p=0;
        ListNode* temp2=head;
        while(sz1--){
            temp2->val=(v1[s++]);
            if(sz1==0 && sz2==0){
                break;
            }
            temp2=temp2->next;
        }
        while(sz2--){
            temp2->val=(v2[p++]);
            if(sz2==0){
                break;
            }
            temp2=temp2->next;
        }
        return head;
                
    }
};