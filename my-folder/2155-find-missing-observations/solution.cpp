class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int len = rolls.size();
        int sum = (len+n) * mean;
        for(int i = 0; i < len; i++) {
            sum -= rolls[i];
        }
        // cout << sum << endl;
        //n个和为sum的小于6的正整数
        if(sum > n*6 || sum < n*1) return {};
        int least = sum / n;
        vector<int> res(n,least);
        int left = sum % n;
        for(int i = 0; i < left; i++) {
            res[i]++;
        }
        return res;
    }
};
