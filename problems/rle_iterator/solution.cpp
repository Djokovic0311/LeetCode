class RLEIterator {
public:
    RLEIterator(vector<int>& encoding) {
        rle = encoding;
        size = encoding.size();
    }
    
    int next(int n) {
        while(idx < size) {
            if(n <= rle[idx]) {
                rle[idx] -= n;
                return rle[idx+1];
            }
            if(n > rle[idx]) {
                // rle[idx] = 0;
                n -= rle[idx];
                idx += 2;
                
            }
        }
        return -1;
    }
private:
    vector<int> rle;
    int idx = 0,size;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */