class Solution {
public:
    static int numberof1s(int a){
            int count = 0;
            while(a){
                a = a&(a-1);
                count++;
            }
            return count;
        }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> res;
        int n = arr.size();
        sort(arr.begin(), arr.end(), [](const int& a, const int& b) {
            return numberof1s(a) == numberof1s(b)?a<=b:numberof1s(a) < numberof1s(b);});
        return arr;
    }
};