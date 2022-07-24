class FoodRatings {
public:
    struct SortByYX
    {
      bool operator ()(const pair<int, string>& l, const pair<int, string>& r) const
      {
        if(l.first != r.first){
            return l.first > r.first;
        }
        else return l.second < r.second;
      }
    };
    
    unordered_map<string, set<pair<int, string>, SortByYX>> m;
    unordered_map<string, int> rate;
    unordered_map<string, string> s;
    
    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        for(int i=0; i<f.size(); i++){
            m[c[i]].insert({r[i], f[i]});
            s.insert({f[i], c[i]});
            rate.insert({f[i], r[i]});
        }
    }
    
    void changeRating(string f, int nr) {
        string c = s[f];
        int r = rate[f];
        rate[f] = nr;
        m[c].erase({r, f});
        m[c].insert({nr, f});
    }
    
    string highestRated(string c) {
        
        pair<int, string> p = *(m[c].begin());
        return p.second;
    }
};
/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
