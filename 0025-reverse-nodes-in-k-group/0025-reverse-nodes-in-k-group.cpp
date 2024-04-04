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
    int length(ListNode* head){
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            len++;

        }
        return len;
    }
    ListNode* reverseKNodes(ListNode* head,int k){
        if(head==NULL){
            return NULL;
        }
        int len=length(head);
        if(k>len){
            return head;
        }
        //step A reverse K nodes first
        int count=0;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward=curr->next;
        while(count<k){
            forward=curr->next;
             curr->next=prev;
             prev=curr;
             curr=forward;
             count++;
        }

        //step B head->next will be attached to recursion

        if(forward!=NULL){
            head->next=reverseKNodes(forward,k);
        }

        //step C return head of the changed linked list
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseKNodes(head,k);
        
    }
};