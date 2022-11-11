class CustomStack {
public:
    CustomStack(int maxSize) {
        maxSz = maxSize;
    }
    
    void push(int x) {
        if(maxSz) {
            vec.push_back(x);
            maxSz--;
        }
    }
    
    int pop() {
        if(vec.size()) {
            int res = vec.back();
            vec.pop_back();
            maxSz++;
            return res;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int n = vec.size();
        for(int i = 0; i < min(k,n); i++) {
            vec[i] += val;
        }
    }
private:
    int maxSz;
    vector<int> vec;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
