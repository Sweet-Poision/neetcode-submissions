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
    ListNode * reverse(ListNode * head) {
        if(head == nullptr) return nullptr;
        if(head-> next == nullptr) return head;
        ListNode * n = reverseList(head->next);
        int val = head->val;
        head->next->next = head;
        head->next = nullptr;
        return n;
    }

    ListNode* reverseList(ListNode* head) {
        return reverse(head);
    }
};
