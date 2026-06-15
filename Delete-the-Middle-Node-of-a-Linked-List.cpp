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
13    ListNode* deleteMiddle(ListNode* head) {
14        //it is a simple delete a node question 
15        //where the position turns out to be length/2
16
17        int n=0;
18        ListNode* temp=head;
19        while(temp!=nullptr){
20            n++;
21            temp=temp->next;
22        }
23        int pos=n/2;
24        if(pos==0){
25            return nullptr;
26        }   
27        
28        int count=1;
29        ListNode* start=head;
30        while(count<pos){
31            start=start->next;
32            count++;
33        }
34        start->next=start->next->next;
35        return head;
36
37    }
38};