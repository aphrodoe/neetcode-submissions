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
    int GetGCD(int a, int b) {
        while (a > 0 && b > 0) {
            if (a > b) a = a % b;
            else b = b % a;
        }
        return (a == 0) ? b : a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        while (curr -> next) {
            int n1 = curr -> val;
            int n2 = curr -> next -> val;
            int gcd = GetGCD(n1, n2);
            curr -> next = new ListNode(gcd, curr -> next);
            curr = curr -> next -> next;
        }
        return head;
    }
};