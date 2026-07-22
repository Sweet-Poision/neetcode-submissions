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

    ListNode * solve(ListNode * head, int k, int cur, bool& flag) {
        if(head == nullptr) return head;
        ListNode * reversedHead = solve(head->next, k, cur + 1, flag);
        if(cur % k == 0) flag = true;
        if(!flag) return head;
        if(cur % k == 0) {
            head->next = reversedHead;
            return head;
        }
        ListNode * temp = head->next->next;
        head->next->next = head;
        head->next = temp;
        return reversedHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        bool flag = false;
        return solve(head, k, 1, flag);
    }
};
