class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: Find if there are at least k nodes left
        ListNode* curr = head;
        int count = 0;
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }
        
        // If there are fewer than k nodes, leave them as they are
        if (count < k) {
            return head;
        }

        // Step 2: Reverse the first k nodes using a stack
        stack<ListNode*> st;
        curr = head;
        for (int i = 0; i < k; i++) {
            st.push(curr);
            curr = curr->next;
        }

        // Connect the reversed group
        ListNode* newHead = st.top();
        st.pop();
        ListNode* tail = newHead;

        while (!st.empty()) {
            tail->next = st.top();
            st.pop();
            tail = tail->next;
        }

        // Step 3: Recursively call for the rest of the list and connect it
        tail->next = reverseKGroup(curr, k);

        return newHead;
    }
};