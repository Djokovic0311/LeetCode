class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int> original(n, 0);

        // Check if the derived array can be formed
        for (int i = 0; i < n - 1; ++i) {
            original[i+1] = original[i] ^ derived[i];
        }

        // Validate last element of original array
        if ((original[0] ^ original[n-1]) != derived[n-1]) {
            return false;
        }

        return true;     
    }
};
