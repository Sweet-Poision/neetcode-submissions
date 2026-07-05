/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;
        unordered_map<Node *, pair<int, Node *>> mp;
        int i = 0;
        Node * itr = head;
        while(itr != nullptr) {
            mp[itr] = {i, itr->random};
            itr = itr->next;
            i++;
        }
        vector<int> v(i);
        for(auto &it: mp) {
            v[it.second.first] = (it.second.second == nullptr) ? -1 : mp[it.second.second].first;
        }
        vector<Node *> v2;
        itr = head;
        while(itr != nullptr) {
            Node * temp = new Node(itr->val);
            v2.push_back(temp);
            itr = itr->next;
        }
        for(int i = 1; i < v2.size(); ++i) {
            v2[i-1]->next = v2[i];
        }
        for(int i = 0; i < v2.size(); ++i) {
            v2[i]->random = (v[i] == -1) ? nullptr : v2[v[i]];
        }
        return v2[0];
    }
};
