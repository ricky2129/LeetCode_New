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
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* temp=curr->next;

        while(curr && temp){

            if(curr->val==temp->val ){
                while(temp && curr->val==temp->val){
                    curr=temp;
                    temp=temp->next;
                }
                curr=temp;

                if(temp){
                    temp=temp->next;
                }
                if(prev){
                    prev->next=curr;
                }
                else{
                    head=curr;
                }
            }

            else{
            prev=curr;
            curr=temp;
            temp=temp->next;
            }
        }

        return head;
        
    }
};