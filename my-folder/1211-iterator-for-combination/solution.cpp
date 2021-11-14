class CombinationIterator {
public:
    void backtrack(string curr, string chars, int n, int start) {
        if (curr.size() == n) {
            combs.push_back(curr);
            return;
        }
        
        for (int i = start; i < chars.size(); i++) {
            curr.push_back(chars[i]);
            backtrack(curr, chars, n, i+1);
            curr.pop_back();
        }
    }
    
    CombinationIterator(string characters, int combinationLength) {
        backtrack("", characters, combinationLength, 0);
    }
    
    string next() {
        return combs[i++];
    }
    
    bool hasNext() {
        return i < combs.size();
    }
    
private:
    vector<string> combs;
    int i = 0;
};


/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
