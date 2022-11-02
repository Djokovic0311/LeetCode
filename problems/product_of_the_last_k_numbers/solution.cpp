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
        
        if(num==0 || products.back()==0)
        {
            if(num==0) last_zero = products.size();
            
            products.push_back(num);
        }
        else
        {
            products.push_back(products.back()*num);
        }
    }
    
    int getProduct(int k) {
        
        int limit = products.size()-k;
        
        if(last_zero>=limit) return 0;
        
        if(products[limit-1]==0) return products.back();
        
        return products.back()/products[limit-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */