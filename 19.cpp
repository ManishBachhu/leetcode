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

// Backtracking solution : O(N)
/**
class Solution {
public:
    ListNode* prevNode = nullptr;
    ListNode* nextNode = nullptr;
    int backtrackAndMark(ListNode* node, int n) {
        // base case
        if (node == nullptr) {
            return 1;
        }
        int currPos = backtrackAndMark(node->next, n);
        if (currPos == n) {
            nextNode = node->next;
        }
        else if (currPos == n + 1) {
            prevNode = node;
        }
        return currPos + 1;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = backtrackAndMark(head, n);
        if (prevNode != nullptr) {
            prevNode->next = nextNode;
        } else {
            // n == sz case
            head = head->next;
        }
        return head;
    }
};
*/

// Two pointer, one-pass solution
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Move two pointers such that when end pointer is at nullptr,
        // start pointer points to the node before the node to be deleted
        ListNode dummyHead(0);
        dummyHead.next  = head;
        ListNode* start = &dummyHead;
        ListNode* end = &dummyHead;

        // Move n + 1 steps to create gap
        n = n + 1;
        while(n--) {
            end = end->next;
        }

        while(end != nullptr) {
            end = end->next;
            start = start->next;
        }

        // Delete node
        start->next = start->next->next;

        return dummyHead.next;
    }
};
