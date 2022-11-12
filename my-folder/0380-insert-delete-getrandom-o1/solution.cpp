class RandomizedSet {
	// Average Time O(1) & Auxiliary Space O(N)
private:
    vector<int> a; 
    unordered_map<int,int> m; 
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(m.find(val)!=m.end())
            return false;
        else{
            a.push_back(val);  // insert val at the end of the array
            m[val]=a.size()-1; 
            return true;
        }
    }
    
    bool remove(int val) {
        if(m.find(val)==m.end()) 
            return false;
        else{
	        // val present in the array vector
	        // For example: a=[8,4,3,2], m={[8,0],[4,1],[3,2],[2,3]}, val=4, last=2
	        // After a[m[val]]=a.back(); a=[8,2,3,2], m={[8,0],[4,1],[3,2],[2,3]}
	        // After a.pop_back(); a=[8,2,3], m={[8,0],[4,1],[3,2],[2,3]}
	        // After m[last]=m[val]; a=[8,2,3], m={[8,0],[4,1],[3,2],[2,1]}
	        // After m.erase(val); a=[8,2,3], m={[8,0],[3,2],[2,1]}
            int last=a.back();  // back() fetches last element of the array vector
            a[m[val]]=a.back(); // m[val] locates the index of val in the array vector.
				                // Then we copy array last element value to the val location in the array
            a.pop_back();	    // Delete the last element of the array 
            m[last]=m[val];	    // In hashmap, assign index of val in array to the index of the last element   
            m.erase(val);	    // Delete the val entry from map
            return true;
        }
    }
    
    /** Get a random element from the array vector */
    int getRandom() {

        return a[rand()%a.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
