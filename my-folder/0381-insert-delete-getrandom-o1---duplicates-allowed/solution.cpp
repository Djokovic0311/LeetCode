class RandomizedCollection {
private:
    std::vector<int> lst;
    std::unordered_map<int, std::unordered_set<int>> idx;
    
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(nullptr)); // Seed for random number generation
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool notContain = idx[val].empty();
        lst.push_back(val);
        idx[val].insert(lst.size() - 1);
        return notContain;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (idx.find(val) == idx.end() || idx[val].empty()) return false;

        int remove_idx = *idx[val].begin();
        idx[val].erase(remove_idx);
        int last = lst.back();
        lst[remove_idx] = last;
        idx[last].insert(remove_idx);
        idx[last].erase(lst.size() - 1);

        lst.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return lst[rand() % lst.size()];
    }
};
