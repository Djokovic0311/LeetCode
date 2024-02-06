class MRUQueue {
public:
    vector<int> vec;
    
    MRUQueue(int n) {
        // So no recopying is done
        vec.resize(n+1);
        vec.reserve(n+2);
        for (int i = 1; i <= n; ++i) {
            vec[i] = i;
        }        
    }
    
    int fetch(int k) {
        vec.push_back(vec[k]);
        vec.erase(vec.begin() + k);
        return vec.back();
    }
};
/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */
