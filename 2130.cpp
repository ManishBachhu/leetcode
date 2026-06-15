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
    int pairSum(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        int count = 1;

        while(fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            count++;
        }

        // Reverse the second half of the linked list
        ListNode *first = slow->next;
        ListNode *second = slow->next->next;
        slow->next = nullptr;

        while(second != nullptr) {
            first->next = slow;
            slow = first;
            first = second;
            second = second->next;
        }
        first->next = slow;

        first = head;
        second = fast;

        int ans = INT_MIN;
        while(count--) {
            int sum = first->val + second->val;
            ans = max(sum, ans);
            first = first->next;
            second = second->next;
        }

        return ans;
    }
};
