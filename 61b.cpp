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

// Solution is to connect the head and tail nodes to create a circular list
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr)
            return head;
        
        int n = 1;
        ListNode* tail = head;
        while(tail->next != nullptr) {
            tail = tail->next;
            n++;
        }
        tail->next = head;

        k = n - k%n - 1;
        
        ListNode* newTail = head;
        while(k--) {
            newTail = newTail->next;
        }

        
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;

    }
};
