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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return head;
        ListNode* prev = head;
        ListNode* curr = head -> next;
        ListNode* n = head -> next -> next;
        head -> next = nullptr;
        while (curr) {
            curr -> next = prev;
            prev = curr;
            curr = n;
            if (n) n = n -> next;
        }
        return prev;
    }
};
