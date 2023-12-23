class node {
    public:
        int key;
        int val;
        node* pre;
        node* next;
        node(int _key, int _val) {
            key = _key;
            val = _val;
        }
};
class LRUCache {
public:
    unordered_map<int, node*> mp;
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            node* tmp = mp[key];
            int res = tmp->val;
            mp.erase(key);
            deleteNode(tmp);
            addNode(tmp);
            mp[key] = tmp;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            node* tmp = mp[key];
            mp.erase(key);
            deleteNode(tmp);
        } else if(mp.size() == cap) {
            mp.erase(tail->pre->key);
            deleteNode(tail->pre);
        }
        node* add = new node(key,value);
        addNode(add);
        mp[key] = add;

    }

    void addNode(node* tmp) {
        tmp->next = head->next;
        tmp->pre = head;
        head->next = tmp;
        tmp->next->pre = tmp;
    }        
    
    void deleteNode(node* tmp) {
        tmp->pre->next = tmp->next;
        tmp->next->pre = tmp->pre;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
