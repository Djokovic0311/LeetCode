class ZigzagIterator {
public:
    vector<int> vector1, vector2;
    int flag = 0;
    int i = 0, j = 0;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        vector1 = v1;
        vector2 = v2;
    }

    int next() {
        if(flag == 0) {
            if(i < vector1.size()) {
                flag = 1;
                return vector1[i++];                
            } else {
                return vector2[j++];
            }
        } else {
            if(j < vector2.size()) {
                flag = 0;
                return vector2[j++];                
            } else {
                return vector1[i++];
            }

        } 
    }

    bool hasNext() {
        return !(i == vector1.size() && j == vector2.size());
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
