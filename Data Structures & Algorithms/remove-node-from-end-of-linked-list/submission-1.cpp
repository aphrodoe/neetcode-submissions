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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || head -> next == nullptr) return nullptr;

        int cnt = 0;
        ListNode* curr = head;
        while (curr) {
            cnt++;
            curr = curr -> next;
        }

        int pos = cnt - n;
        if (pos == 0) {
            ListNode* temp = head;
            head = head -> next;
            delete temp;
            return head;
        }

        curr = head;
        for (int i = 1; i < pos; i++) curr = curr -> next;
        ListNode* temp = curr -> next;
        curr -> next = temp -> next;
        delete temp;

        return head;
    }
};
