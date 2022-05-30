class ProductOfNumbers {
public:
    
    // store prefix product of numbers
    vector<int>products;
    
    // store position of last zero number
    int last_zero;
    
    ProductOfNumbers() {
        
        // insert initial value product value 1
        products.push_back(1);
        
        // initially no zero value
        last_zero  = -1;
    }
    
    void add(int num) {
        
        // insert number if num == 0 or last number was 0 
        if(num==0 || products.back()==0)
        {
            // update last zero position
            if(num==0) last_zero = products.size();
            
            products.push_back(num);
        }
        else
        {
            // insert prefix product of current number  = last product * current number
            products.push_back(products.back()*num);
        }
    }
    
    int getProduct(int k) {
        
        // position of the k th product from last
        int limit = products.size()-k;
        
        // product will be zero if there is a zero in last k numbers
        if(last_zero>=limit) return 0;
        
        // product will be prefix product[end] if prefix product[end-k] ==0 to avoid divide by zero
        if(products[limit-1]==0) return products.back();
        
        // return prefix product[end] / prefix product[end-k]
        return products.back()/products[limit-1];
    }
};
/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */