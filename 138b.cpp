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

// Solution without using hash table
// Hash table solution is straightforward
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;
        
        Node* oldNode = head;
        // Contruct new list and put cloned node next to old node
        while(oldNode != nullptr) {
            Node* newNode = new Node(oldNode->val);
            newNode->next = oldNode->next;
            oldNode->next = newNode;
            oldNode = newNode->next;
        }

        //Assign random
        Node* p1 = head;
        Node* newHead = p1->next;
        Node* p2 = newHead;
        while(p1 != nullptr) {
            if(p1->random == nullptr) {
                p2->random = nullptr;
            } else {
                p2->random = p1->random->next;
            }
            
            p1 = p2->next;
            if(p2->next != nullptr)
                p2 = p2->next->next;
        }

        // Reset lists back to original shape
        p1 = head, p2 = newHead;
        while(p1 != nullptr) {
            p1->next = p2->next;
            if(p2->next != nullptr) 
                p2->next = p2->next->next;
            else
                p2->next = nullptr; 
            p1 = p1->next;
            p2 = p2->next;
        }

        return newHead;
    }
};
