class Cashier {
public:
    int count=0;    
    int n , discount;
    unordered_map<int,int> prodPrice;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n = n ;
        this->discount = discount;
        for(int i =0;i<products.size();i++)        
            prodPrice[products[i]] = prices[i];
    }
    
    double getBill(vector<int> prod, vector<int> amount) {
        count++;
        bool flag = 0;
        if(count%n == 0 ) {
            flag = 1;
            count  = 0;
        }
        double cost = 0;
        for(int i=0;i<prod.size();i++){
            cost += (prodPrice[prod[i]] * amount[i]);
        }
        if(!flag)
            return cost; 
        cost = cost - ((discount*cost)/100);
        return cost; 
    }
};


/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */