class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int shift = count(begin(arr), end(arr), 0), size = arr.size();
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (!arr[i]) shift--;
            if (i + shift < size) {
                arr[i + shift] = arr[i];
                if (!arr[i] && i + shift + 1 < size)
                    arr[i + shift + 1] = 0;
            }
        }
    }
};