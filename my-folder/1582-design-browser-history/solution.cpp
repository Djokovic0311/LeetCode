class BrowserHistory {
public:
    int n = 0, n_max = 0;
    unordered_map<int, string> mp;
    BrowserHistory(string homepage) {
        mp[n] = homepage;
    }
    
    void visit(string url) {
        n++;
        n_max = n;
        mp[n] = url;
    }
    
    string back(int steps) {
        n = n - steps;
        // n_max = n;
        if(n < 0) n = 0;
        return mp[n];
    }
    
    string forward(int steps) {
        n += steps;
        if(n > n_max) n = n_max;
        return mp[n];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
