class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = head;
        ListNode* prev = dummy;
        
        while (curr && curr->next) {
            if (curr->val <= curr->next->val) {
                curr = curr->next;
            } else {
                ListNode* toInsert = curr->next;
                curr->next = toInsert->next;
                
                prev = dummy;
                while (prev->next->val < toInsert->val) {
                    prev = prev->next;
                }
                
                toInsert->next = prev->next;
                prev->next = toInsert;
            }
        }
        return dummy->next;
    }
};
