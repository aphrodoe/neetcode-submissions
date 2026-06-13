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
    ListNode* merge2(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1 -> val < l2 -> val) {
                curr -> next = l1;
                curr = l1;
                l1 = l1 -> next;
            }
            else {
                curr -> next = l2;
                curr = l2;
                l2 = l2 -> next;
            }
            curr -> next = nullptr;
        }
        if (l1) curr -> next = l1;
        else curr -> next = l2;

        return head -> next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;

        for (int i = 1; i < lists.size(); i++) lists[0] = merge2(lists[0], lists[i]);

        return lists[0];
    }
};
