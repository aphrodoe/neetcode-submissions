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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int curr = 1;
        ListNode* temp = head;
        ListNode* before = NULL;
        while (curr < left) {
            before = temp;
            temp = temp -> next;
            curr++;
        }
        if (before) before -> next = NULL;
        ListNode* first = temp;
        ListNode* prev = temp;
        temp = temp -> next;
        while (curr < right) {
            ListNode* nxt = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = nxt;
            curr++;
        }
        first -> next = temp;
        if (before) before -> next = prev;
        if (left == 1) return prev;
        return head;
    }
};