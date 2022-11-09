class LRUCache {
public:

    class node{
      public:
        int key;
        int val;
        node* prev;
        node* next;
        node(int _key,int _val){
            key=_key;
            val=_val;
        }
    };
    
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    
    unordered_map<int,node*> mp;
    int cap;

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
   void addNode(node* temp){
        temp->next=head->next;
        temp->prev=head;
        head->next=temp;
        temp->next->prev=temp;
    }
    
    void deleteNode(node* temp){
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }

    int get(int key) {
         if(mp.find(key)!=mp.end()){
            node* resultNode=mp[key];
            int result=resultNode->val;
            mp.erase(key);
            deleteNode(resultNode);
            addNode(resultNode);
            mp[key]=resultNode;
            return result;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node* temp=mp[key];
            mp.erase(key);
            deleteNode(temp);
        }
        else if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        node* add=new node(key,value);
        addNode(add);
        mp[key]=add;
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
