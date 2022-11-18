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
        // cout << "push " << x << endl;
        // for(auto v : vec) {
        //     cout << v.first << ' ' << v.second << endl;
        // }
        // cout << endl;
    }
    
    int pop() {
        if(!vec.size()) return -1; // base case
        int res = vec.back().first + vec.back().second;
        int inc = vec.back().second;
        vec.pop_back();
        maxSz++;
        if(!vec.empty())
            vec.back().second += inc;
        // cout << "pop " << res << endl;
        // for(auto v : vec) {
        //     cout << v.first << ' ' << v.second << endl;
        // }
        // cout << endl;
        return res;
        // for(auto v : vec) {
        //     cout << v.first << ' ' << v.second << endl;
        // }
        // cout << endl;
    }
    
    void increment(int k, int val) {
        int n = vec.size();
        if(n == 0) return;
        int pos = n>=k ? k : n;
        // last element to change
        vec[pos-1].second += val;
        // cout << "increase " << k << " by " << val << endl;
        // for(auto v : vec) {
        //     cout << v.first << ' ' << v.second << endl;
        // }
        // cout << endl;

    }
private:
    vector<pair<int,int>> vec;
    int maxSz;
};

