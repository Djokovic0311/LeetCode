class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n = operations.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(operations[i][1] == '-') res--;
            else res++;
        }
        return res;
    }
};
