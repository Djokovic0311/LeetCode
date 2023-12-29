
class MyHashMap {
public:
    vector<pair<int,int>> vec;

    MyHashMap() {}

    void put(int key, int value) {
        for(int i=0;i<vec.size();i++) {
            if(vec[i].first == key) {
                vec[i].second = value; //update the existing key's value
                return;//exit the function after updating
            }
        }
        vec.push_back({key, value});//if the key doesn't exist, add a new key-value pair
    }

    int get(int key) {
        for(int i=0;i<vec.size();i++) {
            if(vec[i].first == key)return vec[i].second;//return the value if key is found
        }
        return -1;//return -1 if key is not found
    }

    void remove(int key) {
        for(int i = 0; i < vec.size(); i++) {
            if(vec[i].first == key) {
                vec.erase(vec.begin()+i);//remove the key-value pair
                return;//exit the function after removing
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
