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
    bool hasCycle(ListNode* head) {
        set<ListNode*> st;
        if(head == nullptr) return false;
        ListNode* curr = head;
        while(curr != nullptr){
            if(st.count(curr)){
                return true;
            }
            else{
                st.insert(curr);
                curr = curr->next;
            }
        }
        return false;
    }
};
