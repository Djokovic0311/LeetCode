class SmallestInfiniteSet {
    private:
    set<int>st;
public:
    SmallestInfiniteSet() {
        for(int i=1;i<1001;i++) st.insert(i);
    }
    
    int popSmallest() {
        int p = *st.begin();
        st.erase(st.begin());
        return p;
    }
    
    void addBack(int num) {
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
