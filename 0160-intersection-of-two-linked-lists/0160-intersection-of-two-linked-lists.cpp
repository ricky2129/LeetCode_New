class Solution {
public:
    int lengthLL(ListNode *head){
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            len++;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;

        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        int m = lengthLL(headA);
        int n = lengthLL(headB);
        int skip = abs(m - n);

        if (m > n) {
            for (int i = 0; i < skip; i++) {
                ptrA = ptrA->next;
            }
        } else {
            for (int i = 0; i < skip; i++) {
                ptrB = ptrB->next;
            }
        }

        while (ptrA != NULL && ptrB != NULL) {
            if (ptrA == ptrB) {
                return ptrA;
            }
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }

        return NULL;
    }
};
