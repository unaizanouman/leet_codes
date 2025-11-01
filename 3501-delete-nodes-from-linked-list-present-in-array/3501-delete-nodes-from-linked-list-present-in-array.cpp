class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* cur = head;

        while(cur){
            if(st.count(cur->val)){
                prev->next = cur->next;
            } else {
                prev = cur;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};
