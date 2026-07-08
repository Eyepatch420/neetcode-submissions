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
        if (head == nullptr) return nullptr;
        Node* curr = head;
        while (curr != nullptr) {
            Node* copy = new Node(curr->val);
            Node* nextNode = curr->next;
            curr->next = copy;
            copy->next = nextNode;
            curr = nextNode;
        }

        curr = head;

        while (curr != nullptr) {
            curr->next->random = (curr->random != nullptr) ? curr->random->next : nullptr;
            curr = curr->next->next;
        }

        curr = head;
        Node* copyHead = head->next;

        while (curr != nullptr) {
            Node* copy = curr->next;
            curr->next = copy->next;
            if (copy->next != nullptr) copy->next = copy->next->next;
            curr = curr->next;
        }

        return copyHead;
    }
};
