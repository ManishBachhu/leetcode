/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Time Complexity O(N)
        // Space Complexity O(N) (There is a solution with O(1) complexity that uses 
        // the original list to store new the list and avoid the extra map use here.)
        // First iterate and create new list with help of nest
        // While creating the list, old nodePtr as key, new nodePtr as value
        // In second iteration, use the keys to set random ptrs in new list

        Node* oldPtr = head;
        Node* dummyHead = new Node(0);
        Node* newPtr = dummyHead;
        unordered_map<Node*, Node*> nodeMap;

        while (oldPtr != NULL) {
            Node* newNode = new Node(oldPtr->val);
            newPtr->next = newNode;
            newPtr = newPtr->next;
            nodeMap[oldPtr] = newPtr;
            oldPtr = oldPtr->next; 
        }

        oldPtr = head;
        newPtr = dummyHead->next;
        

        while (oldPtr != NULL) {
            newPtr->random = nodeMap[oldPtr->random];
            oldPtr = oldPtr->next;
            newPtr = newPtr->next;
        }

        Node* res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};
