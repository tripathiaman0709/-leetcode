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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //ek bekaar tareeka
        //vector lo , values stores kro , reverse kro and list me values change krdo bass
        vector<int>v;
        ListNode* temp=head;
        int count=1;
        while(temp!=nullptr){
            if(count>=left && count<=right){
                v.push_back(temp->val);
            }
            count++;
            temp=temp->next;
        }
        reverse(v.begin(),v.end());
        int start=1;
        ListNode* temp1=head;
        while(start<left){
            temp1=temp1->next;
            start++;
        }
        //now temp1 will point at left postion
        //now exchange of values will start
        int x=right-left;
        int s=0;
        while(x>=0){
            temp1->val=v[s];
            temp1=temp1->next;
            s++;
            x--;
        }
        return head;
    }
};