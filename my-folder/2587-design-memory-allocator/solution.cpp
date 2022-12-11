class Allocator {
public:
    vector<int> v;
    vector<vector<int>> empty;
    int n;
    Allocator(int n) {
        vector<int> v_(n,0);
        this->v = v_;
        this->n = n;
        this->empty.push_back({0,n-1});
    }
    
    int allocate(int size, int mID) {
        // cout << endl;
        // cout << size << ' ' << mID << endl;
        for(int i = 0; i < empty.size(); i++) {
            // cout << empty[i][0] << ',' << empty[i][1] << ' ';
            if(empty[i][1]-empty[i][0]+1 >= size) {
                for(int j = empty[i][0]; j < empty[i][0]+size; j++) {
                    v[j] = mID;
                }
                int start = empty[i][0] + size;
                int end = empty[i][1];
                
                empty.erase(empty.begin()+i);
                empty.push_back({start, end});
                sort(empty.begin(), empty.end());
                return start - size;
                
            }
            
        }
        // cout << endl;
        return -1;
    }
    
    int free(int mID) {
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(v[i] == mID) {
                v[i] = 0;
                res++;
                empty.push_back({i, i});
            }
        }
        empty = merge(empty);
        return res;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        if(intervals.size()<=1) return intervals;
        res.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= res.back()[1]+1)
            {
                int s = res.back()[0], e = max(res.back()[1], intervals[i][1]);
                res.pop_back();
                res.push_back({s,e});
            }
            else res.push_back(intervals[i]);
        }
        return res;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
