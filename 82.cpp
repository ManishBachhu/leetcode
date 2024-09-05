class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode dummy(0, head);
        ListNode* a = &dummy;

        while (a->next && a->next->next) {
            if (a->next->val == a->next->next->val) {
                int dupVal = a->next->val;
                while (a->next && a->next->val == dupVal) {
                    a->next = a->next->next;
                }
            } else {
                a = a->next;
            }
        }

        return dummy.next;
    }
};
