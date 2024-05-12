class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        ListNode* curr = head;
        
        while (curr) {
            int nextGreater = findNextGreater(curr);
            ans.push_back(nextGreater);
            curr = curr->next;
        }
        
        return ans;
    }
    
    int findNextGreater(ListNode* node) {
        ListNode* curr = node->next;
        while (curr) {
            if (curr->val > node->val) {
                return curr->val;
            }
            curr = curr->next;
        }
        return 0;
    }
};
