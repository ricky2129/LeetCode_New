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
        ListNode* reverseLL(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev; // Return the new head of the reversed list
    }
bool isPalindrome(ListNode* head) {
    if(head == nullptr || head->next == nullptr) {
        return true;
    }

    // Find the middle of the list
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    ListNode* secondHalf = reverseLL(slow->next);

    // Compare the first half and the reversed second half
    ListNode* firstHalf = head;
    ListNode* temp = secondHalf; // Use temp to hold the start of reversed half to reverse it back later
    bool flag = true;
    while(secondHalf != nullptr) {
        if(firstHalf->val != secondHalf->val) {
            flag = false;
            break;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // Reverse the second half back to restore the original list structure
    reverseLL(temp);
    slow->next = temp; // Reconnect the two halves

    return flag;
}

};