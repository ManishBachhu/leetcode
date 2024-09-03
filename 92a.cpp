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

// This solution uses backtracking for reversing right ptr.
// Only values of the nodes are swapped.
class Solution {
public:
    ListNode* left = nullptr;
    bool stop = false;
    void recurseAndReverse(ListNode* right, int l, int r) {
        if (r == 1) return; // right ptr already reached destination
        right = right->next;
        if (l > 1) left = left->next;
        recurseAndReverse(right, l - 1, r - 1);
        if (left == right || right->next == left) stop = true; // no more swaps needed
        
        // swap values
        if (!stop) {
            int tmp = left->val;
            left->val = right->val;
            right->val = tmp;
            left = left->next;
        }
    }

    ListNode* reverseBetween(ListNode* head, int l, int r) {
        left = head;
        ListNode* right = head;
        recurseAndReverse(right, l, r);
        return head;
    }
};
