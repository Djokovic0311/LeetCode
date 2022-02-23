class Solution {
public:
    void reverseString(vector<char>& s) {
        int right = s.size()-1, left = 0;
        while(left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};