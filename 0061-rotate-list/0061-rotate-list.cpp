class Solution {
public:
    int lengthLL(ListNode* head){
        int count = 0;
        ListNode* temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0) return head;

        int length = lengthLL(head);
        k = k % length; // Handling cases where k is greater than the length of the list

        if(k == 0) return head; // No rotation needed

        ListNode* prev = NULL;
        ListNode* curr = head;

        for(int i = 0; i < length - k; i++){
            prev = curr;
            curr = curr->next;
        }

        prev->next = NULL;
        ListNode* ptr = curr;

        while(ptr->next != NULL){
            ptr = ptr->next;
        }

        ptr->next = head;
        return curr;
    }
};
