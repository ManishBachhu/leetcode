class Solution {
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0), *tail = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) swap(l1, l2);
            tail->next = l2;
            l2 = l2->next;
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
    
    ListNode* splitSort(ListNode* head, int L) {
        if (L <= 1) return head;
        
        ListNode* mid = head;
        for (int i = 0; i < L / 2 - 1; i++) mid = mid->next;
        ListNode* h2 = mid->next;
        mid->next = nullptr;
        
        return merge(splitSort(head, L / 2), splitSort(h2, L - L / 2));
    }
    
public:
    ListNode* sortList(ListNode* head) {
        int L = 0;
        for (ListNode* nd = head; nd; nd = nd->next) L++;
        return splitSort(head, L);
    }
};
