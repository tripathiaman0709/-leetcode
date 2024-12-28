class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;  // Start from the first node after the initial zero
        ListNode* result = head;     // We'll reuse the existing list
        int sum = 0;

        while (temp != nullptr) {
            if (temp->val == 0) {
                // Assign the sum to the current result node and move result forward
                result->val = sum;
                sum = 0;
                if (temp->next != nullptr) {
                    result = result->next; // Only move result if there's more data
                }
            } else {
                sum += temp->val; // Accumulate the sum
            }
            temp = temp->next;
        }

        // Truncate the list after the last valid result node
        result->next = nullptr;
        return head;
    }
};
