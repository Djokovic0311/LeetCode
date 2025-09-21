class MovieRentingSystem {
public:
    unordered_map<int, set<pair<int, int> > > movies; // [movie] -> { {price, shop}, ...}
    unordered_map<int, unordered_map<int, int> > movies2; // [movie][shop] = [price]
    set<pair<int, pair<int, int> > > rented; // {price, {shop, movie} }
    set<pair<int, int> > available; // {shop, movie}
    
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto e : entries) // entries[i] = [shopi, moviei, pricei]
        {
            movies[e[1]].insert({e[2], e[0]});
            movies2[e[1]][e[0]] = e[2];
            available.insert({e[0], e[1]});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> v;
        int cnt = 0;
        for(auto it = movies[movie].begin(); it != movies[movie].end() && cnt < 5; ++it)
        {
            if(available.find({(*it).second, movie}) != available.end()) // if its available
            {
                v.push_back((*it).second);
                ++cnt;
            }
        }
        return v;
    }
    
    void rent(int shop, int movie) {
        available.erase(available.find({shop, movie})); // remove from available 
        rented.insert({movies2[movie][shop], {shop, movie}}); // insert in rented
    }
    
    void drop(int shop, int movie) {
        available.insert({shop, movie}); // insert in available
        rented.erase(rented.find({movies2[movie][shop], {shop, movie}})); // remove from rented
    }
    
    vector<vector<int>> report() {
        vector<vector<int> > ans;
        int cnt = 0;
        for(auto it = rented.begin(); cnt < 5 && it != rented.end(); ++it) // search in rented
        {
            cnt++;
            auto p = (*it).second;
            ans.push_back({p.first, p.second});
        }
        return ans;
    }
};
