class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy; // <-- Change this line (add * and &)
        
        while (l1 && l2) {
            // Also note: standard merge order uses '<' for ascending lists, 
            // make sure your comparison matches your needs.
            if (l1->val < l2->val) { 
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;
            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
                mergedLists.push_back(mergeTwoLists(l1, l2));
            }
            lists = mergedLists;
        }
        return lists[0];
    }
};