class LRUCache {
private:
    
    int max_size, cur_size;
    struct Node {
        pair<int, int> val;
        Node * prev;
        Node * next;
        Node(pair<int,int> val, Node * a, Node * b) {
            this->val = val;
            prev = a;
            next = b;
        }
    };
    void moveToEnd(Node * pre, Node * suc, Node * cur, int key) {
        if(mp[key] == head) {
            head = head->next;
            head->prev = nullptr;
            end->next = cur;
            cur->next = nullptr;
            cur->prev = end;
            end = cur;
            return;
        }
        cur->prev = end;
        cur->next = nullptr;

        pre->next = suc;
        suc->prev = pre;

        end->next = cur;
        end = end->next;
        return;
    }
    unordered_map<int, Node * > mp;
    Node * head, * end;
    
public:
    
    
    LRUCache(int capacity) {
        max_size = capacity;
        cur_size = 0;
        head = nullptr;
        end = nullptr;
    }

    ~LRUCache() {
        Node * temp = head;
        while(temp != nullptr) {
            Node * n = temp->next;
            delete temp;
            temp = n;
        }
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        Node * temp = mp[key];
        if(temp == end) return end->val.second;
        moveToEnd(temp->prev, temp->next, temp, key);
        return temp->val.second;
    }
    
    void put(int key, int value) {
        if(max_size == 0) return;
        if(cur_size == 0) {
            Node * temp = new Node({key, value}, nullptr, nullptr);
            head = temp;
            end = temp;
            mp[key] = temp;
            cur_size++;
            return;
        }
        if(mp.find(key) != mp.end()) {
            Node * temp = mp[key];
            temp->val.second = value;
            if(temp != end) moveToEnd(temp->prev, temp->next, temp, key);
            return;
        }
        Node * newHead = new Node({key, value}, end, nullptr);
        end->next = newHead;
        mp[key] = newHead;
        end = end->next;
        if(cur_size == max_size) {
            cur_size--;
            mp.erase(head->val.first);
            Node * temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        cur_size++;
    }


};
