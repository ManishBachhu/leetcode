class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Get the size of the list and the last node
        ListNode* endPtr = head;
        int sz = 1;
        while (endPtr->next) {
            sz++;
            endPtr = endPtr->next;
        }

        // Calculate the effective rotations needed
        k %= sz;
        if (k == 0) return head;

        // Find the new head after rotation
        ListNode* newEnd = head;
        for (int i = 1; i < sz - k; i++) {
            newEnd = newEnd->next;
        }
        ListNode* newHead = newEnd->next;

        // Rotate the list
        newEnd->next = nullptr;
        endPtr->next = head;

        return newHead;
    }
};
