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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;

        stack<ListNode*> st;
        while (second != nullptr) {
            st.push(second);
            second = second->next;
        }

        ListNode* curr = head;

        while (!st.empty()) {
            ListNode* last = st.top();
            st.pop();

            ListNode* nextFirst = curr->next;

            curr->next = last;
            last->next = nextFirst;

            curr = nextFirst;

            if (curr == nullptr) break;
        }

        if (curr != nullptr) curr->next = nullptr;
    }
};