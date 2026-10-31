class Solution {
public:
    ListNode* reversePart(ListNode* head, ListNode* tail, ListNode* nextNode) {
        ListNode* prev = nextNode;
        ListNode* curr = head;

        while (curr != nextNode) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return tail;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;

        int length = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        int groups = length / k;

        ListNode* curr = head;
        ListNode* prevGroupTail = nullptr;
        ListNode* newHead = nullptr;

        for (int i = 0; i < groups; i++) {
            ListNode* groupHead = curr;
            ListNode* groupTail = curr;

            for (int j = 1; j < k; j++) {
                groupTail = groupTail->next;
            }

            ListNode* nextGroup = groupTail->next;

            ListNode* reversedHead = reversePart(groupHead, groupTail, nextGroup);

            if (newHead == nullptr) {
                newHead = reversedHead;
            }

            if (prevGroupTail != nullptr) {
                prevGroupTail->next = reversedHead;
            }

            prevGroupTail = groupHead;
            curr = nextGroup;
        }

        if (prevGroupTail != nullptr) {
            prevGroupTail->next = curr;
        }

        return newHead;
    }
};