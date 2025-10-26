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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;
        ListNode* tail = head;
        int len = 1;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        tail->next = head;
        k = k % len;
        int stepsToNewHead = len - k;

        while (stepsToNewHead--) {
            tail = tail->next;
        }
        head = tail->next;
        tail->next = nullptr;

        return head;
    }
};
