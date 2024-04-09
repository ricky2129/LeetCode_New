class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // First, handle the case where the head needs to be removed.
        while (head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp; // free the memory of the removed node (if required)
        }

        ListNode* curr = head; // The current node we are looking at.
        ListNode* prev = nullptr; // The previous node before the current node.

        // Now traverse the rest of the list.
        while (curr != nullptr) {
            if (curr->val == val) {
                // Remove the current node.
                prev->next = curr->next;
                delete curr; // free the memory of the removed node (if required)
                curr = prev->next; // Move to the next node.
            } else {
                // Move both pointers forward if we don't remove the node.
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
