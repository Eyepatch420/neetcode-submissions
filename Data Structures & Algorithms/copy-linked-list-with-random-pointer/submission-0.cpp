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
        Node* curr = head;
        unordered_map<Node*, Node*> mp;

        if (head == nullptr) return nullptr;

        while (curr != nullptr) {
            Node* copy = new Node(curr->val);
            mp[curr] = copy;
            curr = curr->next;
        }
        curr = head;

        while (curr != nullptr) {
            Node* copy = mp[curr];
            copy->next = (curr->next != nullptr) ? mp[curr->next] : nullptr;

            copy->random = (curr->random != nullptr) ? mp[curr->random] : nullptr;

            curr = curr->next;


        }
        return mp[head];
    }
};
