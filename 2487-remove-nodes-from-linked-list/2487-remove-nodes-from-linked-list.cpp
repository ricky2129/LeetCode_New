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
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr!=nullptr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }

        return prev;


    }
    ListNode* removeNodes(ListNode* head) {
        ListNode* newHead=reverseLL(head);
        ListNode* prev=newHead; 
        ListNode* curr=prev->next;

        int value=prev->val;

        while(curr){
            if(curr->val >=value){
                value=curr->val;
                prev=curr;
                curr=curr->next;
            }

            else{
                prev->next=curr->next;
                curr=prev->next;
            }
        }

        ListNode* revHead=reverseLL(newHead);
        return revHead;
    }
};