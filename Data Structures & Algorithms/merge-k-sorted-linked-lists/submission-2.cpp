class Solution {

    void mergeTwoLists(ListNode* &a, ListNode* &b) {
        ListNode dummyA(-1, a);  
        ListNode dummyB(-1, b);
        ListNode* i = &dummyA;
        ListNode* j = &dummyB;

        while (i->next != nullptr && j->next != nullptr) {
            if (i->next->val >= j->next->val) {
                ListNode* temp = i->next;
                i->next = j->next;
                j->next = j->next->next;
                i->next->next = temp;
            }
            i = i->next;
        }
        if (j->next != nullptr) {
            i->next = j->next;
        }
        a = dummyA.next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return nullptr;
        for (int step = 1; step < n; step *= 2) {
            for (int i = 0; i + step < n; i += 2 * step) {
                mergeTwoLists(lists[i], lists[i + step]);
            }
        }
        return lists[0];
    }
};