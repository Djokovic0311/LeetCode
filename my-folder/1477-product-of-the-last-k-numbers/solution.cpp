class ProductOfNumbers {
public:
    vector<int> prefix = {1};
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num) {
            prefix.push_back(prefix.back() * num);
        } else {
            prefix = {1};
        }
    }
    
    int getProduct(int k) {
        if(prefix.size() > k) {
            return prefix.back() / prefix[prefix.size()-1-k];
        } else return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
