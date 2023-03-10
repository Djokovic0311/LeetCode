class node {
    public:
        int key;
        int val;
        node* prev;
        node* next;
        node(int _key, int _val) {
            key = _key;
            val = _val;
        }
};

class LRUCache {
public:
    // head(-><-)tail
    int cap;
    unordered_map<int, node*> mp;
    node* head= new node(-1, -1);
    node* tail = new node(-1, -1);

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            node* resultNode = mp[key];
            int result = resultNode->val;
            mp.erase(key);
            deleteNode(resultNode);
            addNode(resultNode);
            mp[key] = resultNode;
            return result;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            node* tmp = mp[key];
            mp.erase(key);
            deleteNode(tmp);
        } else if(mp.size() == cap) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        node* add = new node(key, value);
        addNode(add);
        mp[key] = add;
    }

    void addNode(node* tmp) {
        tmp->next = head->next;
        tmp->prev = head;
        head->next = tmp;
        tmp->next->prev = tmp;
    }

    void deleteNode(node* tmp) {
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
