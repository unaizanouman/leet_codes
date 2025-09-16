class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to simplify handling the head
        ListNode dummy;
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next; // move tail forward
        }

        // Attach the remaining nodes
        if (list1) tail->next = list1;
        if (list2) tail->next = list2;

        return dummy.next;
    }
};
