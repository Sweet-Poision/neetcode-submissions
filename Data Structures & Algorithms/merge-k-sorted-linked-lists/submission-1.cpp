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

    void sortTwoList(ListNode * &a, ListNode * &b) {
        if(a == nullptr) {
            a = b;
            return;
        }
        if(b == nullptr) return;
        ListNode * i = new ListNode(-1, a);
        ListNode * head = i;
        ListNode * j = new ListNode(-1, b);

        while(i->next != nullptr && j->next != nullptr) {
            if(i->next->val >= j->next->val) {
                ListNode * temp = i->next;
                i->next = j->next;
                j->next = j->next->next;
                i->next->next = temp;
            }
            i = i->next;
        }
        if(j -> next != nullptr) {
            i->next = j->next;
        }
        a = head->next;
        delete head;
        delete j;
        return;
        
    }

    void mergeSort(vector<ListNode*> & lists, int left, int right) {
        if(right <= left) return;
        int mid = left + (right - left) /2;
        mergeSort(lists, left, mid);
        mergeSort(lists, mid+1, right);
        sortTwoList(lists[left], lists[mid+1]);
    }


public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        mergeSort(lists, 0, lists.size()-1);
        return lists[0];
    }
};
