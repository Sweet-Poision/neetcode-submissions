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
    ListNode * findMid(ListNode * head) {
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode * reverse(ListNode * head) {
        if(head->next == nullptr) return head;
        ListNode * n = reverse(head->next);
        head->next->next = head;
        return n;
    } 

    void reorder(ListNode * head, ListNode * mid, ListNode * end) {
        while(true) {
            if(head == end) {
                head->next = nullptr;
                break;
            }
            if(head->next == end) {
                end->next = nullptr;
                break;
            }
            ListNode * temp1 = head->next;
            ListNode * temp2 = end->next;
            head->next = end;
            end->next = temp1;
            head = temp1;
            end = temp2;
        }
    }

    void reorderList(ListNode* head) {
        ListNode * mid = findMid(head);
        ListNode * itr = head;
        itr = mid;
        cout << endl;
        ListNode * end = reverse(mid);
        itr = end;
        reorder(head, mid, end);
    }
};
