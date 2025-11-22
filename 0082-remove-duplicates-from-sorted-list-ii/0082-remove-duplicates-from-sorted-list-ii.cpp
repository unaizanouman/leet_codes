class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy; 
        ListNode* cur = head;

        while (cur) {
            if (cur->next && cur->val == cur->next->val) {
                int duplicateVal = cur->val;
                while (cur && cur->val == duplicateVal) {
                    cur = cur->next;
                }
                prev->next = cur; 
            }
            else {
                prev = prev->next;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
