class NumberContainers {
public:
    unordered_map<int, set<int>> numToConts; 
    unordered_map<int, int> contToNum; 
    
    NumberContainers() {}
    
    void change(int index, int number) {
        if(contToNum.find(index) == contToNum.end()) {          // if there is no number in the container with given index, 
                                                                // we straight-away insert the given number at given index
            numToConts[number].insert(index);
            contToNum[index] = number;
        } else if (contToNum[index] == number) {                // if there is a number in given index but that matches the given 
                                                                // number, we need not do any thing as end result will be the same 
            return;             
        } else {                                                // if there is a number(say x) in given index and it is different than given number then.
            numToConts[contToNum[index]].erase(index);          // unassign the given index from x
            numToConts[number].insert(index);                   // assign the index to the given number 
            contToNum[index] = number;                          // update the number in corresponding to the given index
        }
    }
    
    int find(int number) {
        // if the number exists and there is a possible index for it then return that
        if(numToConts.find(number) != numToConts.end()  and  numToConts[number].size() != 0)    
            return *(numToConts[number].begin());
        return -1;                                               // else return -1
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
