class CustomStack {
public:
    CustomStack(int maxSize) {
        maxSz = maxSize;
    }
    
    void push(int x) {
        if(maxSz) {
            vec.push_back(make_pair(x, 0));
            maxSz--;
        }
    }
    
    int pop() {
        if(!vec.size()) return -1; // base case
        int res = vec.back().first + vec.back().second;
        int inc = vec.back().second;
        vec.pop_back();
        maxSz++;
        if(!vec.empty())
            vec.back().second += inc;
        return res;
    }
    
    void increment(int k, int val) {
        int n = vec.size();
        if(n == 0) return;
        int pos = n>=k ? k : n;
        // last element to change
        vec[pos-1].second += val;
    }
private:
    vector<pair<int,int>> vec;
    int maxSz;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
