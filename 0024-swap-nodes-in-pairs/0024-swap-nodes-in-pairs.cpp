class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Dummy node before head
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (head && head->next) {
            // Nodes to swap
            ListNode* first = head;
            ListNode* second = head->next;

            // Swapping
            prev->next = second;
            first->next = second->next;
            second->next = first;

            // Move prev and head
            prev = first;
            head = first->next;
        }

        return dummy.next;
    }
};
