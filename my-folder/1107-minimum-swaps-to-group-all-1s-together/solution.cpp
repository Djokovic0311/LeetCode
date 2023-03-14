class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n = data.size();
        int ones = 0;
        for(int d : data) if(d == 1) ones++;
        int res = 0;
        int tmp = 0;
        for(int i = 0; i < ones; i++) {
            if(data[i] == 0) tmp++;
        }
        res = tmp;

        for(int i = ones; i < n; i++) {
            if(data[i] != data[i-ones]) {
                if(data[i] == 1) tmp--;
                else tmp++;
            }
            res = min(res, tmp);
        }

        return res;
    }
};
