class Solution {
public:
    bool isBalance(int x) {
        vector<int> cnt(10);
        while(x) {
            int digit = x % 10;
            x /= 10;
            cnt[digit]++;
        }
        for(int d = 0; d < 10; d++) {
            if(cnt[d] != 0 && cnt[d] != d) {
                return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for(int i = n+1; i <= 1224444; i++) {
            if(isBalance(i)) {
                return i;
            }
        }
        return -1;
    }
};
