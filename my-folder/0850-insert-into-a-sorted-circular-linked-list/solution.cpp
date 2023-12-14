/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(!head) {
            Node* node = new Node(insertVal, nullptr);
            node->next = node;
            return node;
        }
        Node* prev = head;
        Node* curr = head->next;
        bool toInsert = false;
        do {
            if(prev->val <= insertVal && insertVal <= curr->val) {
                toInsert = true;
            } else if(prev->val > curr->val) {
                if(insertVal >= prev->val || insertVal <= curr->val) {
                    toInsert = true;
                }
            }
            if(toInsert) {
                prev->next = new Node(insertVal, curr);
                return head;
            }
            prev = curr;
            curr = curr->next;
        } while (prev != head);
        prev->next = new Node(insertVal, curr);
        return head;
    }
};
