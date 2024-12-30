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
    int pairSum(ListNode* head) {
        //first easy technique
        //making a vector and turning it into a super easy question

        vector<int>v;
        ListNode* temp=head;
        while(temp!=nullptr){
            v.push_back(temp->val);
            temp=temp->next;
        }
        int maxi=0;
        for(int i=0;i<v.size()/2;i++){
            int x=v[i]+v[v.size()-1-i];
            maxi=max(maxi,x);
        }
        return maxi;
    }
};