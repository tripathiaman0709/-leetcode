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
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false; // Empty list or single node cannot have a cycle
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // Use Floyd's Cycle Detection Algorithm
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;            // Move slow pointer by one step
            fast = fast->next->next;      // Move fast pointer by two steps

            if (fast == slow) {           // If the two pointers meet, a cycle exists
                return true;
            }
        }

        return false; // If fast pointer reaches the end, no cycle exists
    }
};