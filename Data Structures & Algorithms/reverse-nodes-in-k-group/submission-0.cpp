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
    pair<ListNode*, ListNode*> reverse(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return {head, head};

        auto r = reverse(head -> next);
        ListNode* newhead = r.first;
        head -> next -> next = head;
        head -> next = nullptr;
        return {newhead, head};

    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        ListNode* curr = head;
        ListNode* currhead = head;
        ListNode* temp;
        ListNode* temp2;
        ListNode* temp3;
        ListNode* prevtail = nullptr;
        while (curr) {
            cnt++;
            if (cnt % k == 0) {
                temp = curr -> next;
                curr -> next = nullptr;
                auto r = reverse(currhead);
                temp3 = r.first;
                if (cnt / k == 1) head = temp3;
                temp2 = r.second;
                temp2 -> next = temp;
                currhead = temp;
                curr = currhead;
                if (prevtail) prevtail -> next = temp3;
                prevtail = temp2;
            }
            else curr = curr -> next;
        }
        return head;
    }
};