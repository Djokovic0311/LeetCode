class Bitset {
public:
    string s, flipp;
    int ones = 0, siz = 0;
    Bitset(int size) {
        s = string(size, '0'); flipp = string(size, '1');
        siz = size;
    }
    void fix(int idx) {
        if(s[idx] == '0') ones++;  
        s[idx] = '1'; flipp[idx] = '0'; 
    }
    void unfix(int idx) {
        if(s[idx] == '1') ones--;
        s[idx] = '0'; flipp[idx] = '1';
    }
    void flip() {
        ones = siz - ones;
        s.swap(flipp);
    }
    bool all() { return ones == siz; }
    bool one() { return ones; }
    int count() { return ones; }
    string toString() { return s; }
};
/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
