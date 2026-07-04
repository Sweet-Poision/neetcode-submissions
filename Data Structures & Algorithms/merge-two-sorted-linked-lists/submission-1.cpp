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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        ListNode * left = list1;
        ListNode * right = list2;
        ListNode * res = nullptr;
        ListNode * cur = res;
        while(left != nullptr && right != nullptr) {
            if(left->val <= right->val) {
                if(res == nullptr) {
                    res = left;
                    cur = res;
                }
                else {
                    cur -> next = left;
                    cur = cur->next;
                }
                left = left ->next;
            }
            else {
                if(res == nullptr) {
                    res = right;
                    cur = res;
                }
                else {
                    cur -> next = right;
                    cur = cur->next;
                }
                right = right->next;
            }
        }
        if(left != nullptr) cur -> next = left;
        if(right != nullptr) cur -> next = right;
        return res;
    }
};
