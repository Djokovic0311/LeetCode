class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val)!=m.end())
            return false;
        else{
            a.push_back(val);  
            m[val]=a.size()-1; 
            return true;
        }
    }
    
    bool remove(int val) {
        if(m.find(val)==m.end()) 
            return false;
        else{
            int last=a.back();  
            a[m[val]]=a.back();
            a.pop_back();	   
            m[last]=m[val];	    
            m.erase(val);	   
            return true;
        }
    }
    int getRandom() {
        return a[rand()%a.size()];
    }
private:
    vector<int> a;
    unordered_map<int, int> m;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */