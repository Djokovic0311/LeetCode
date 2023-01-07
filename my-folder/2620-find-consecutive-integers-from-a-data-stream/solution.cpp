class DataStream {
public:
    int count = 0;
    int value,k;
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
        
    }
    
    bool consec(int num) {
        if(num == value) {
            count++;
        }
        else {
            count = 0;
        }
        if(count >= k) return true;
        else return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
