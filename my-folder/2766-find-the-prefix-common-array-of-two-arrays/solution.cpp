class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<int> commonArray(n, 0);
    unordered_set<int> commonSet;

    for (int i = 0; i < n; i++) {
        commonSet.insert(B[i]);
        int count = 0;

        for (int j = 0; j <= i; j++) {
            if (commonSet.count(A[j]) > 0) {
                count++;
            }
        }

        commonArray[i] = count;
    }

    return commonArray;    
    }
};
