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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* curr=head;
        ListNode* ptr=curr->next;

        while((curr && ptr)){
            if(curr->val != ptr->val){
                curr=curr->next;
                ptr=curr->next;
            }
            else{
                while(curr!=NULL && ptr!=NULL &&(curr->val==ptr->val)){
                    ptr=ptr->next;
                }
                curr->next=ptr;
                curr=ptr;
                if(ptr!=NULL){
                    ptr=ptr->next;
                }

            }
        }
        return head;
        
    }
};