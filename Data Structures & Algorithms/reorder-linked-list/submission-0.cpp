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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* curr = head;
        while (curr) {
            st.push(curr);
            curr = curr -> next;
        }

        curr = head;
        bool flag = true;
        while (curr != st.top()) {
            ListNode* temp = curr -> next;
            if (temp == st.top()) {
                temp -> next = nullptr;
                flag = false;
                break;
            }
            curr -> next = st.top();
            st.pop();
            curr = curr -> next;
            curr -> next = temp;
            curr = curr -> next;
        }

        if (flag) curr -> next = nullptr;

    }
};
