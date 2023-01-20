class Solution {
public:
    int minimumKeypresses(string s) {
        int res = 0;
        unordered_map<char, int> mp;
        for(char c : s) mp[c]++;
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        vector<int> times;
        for(auto it : mp) times.push_back(it.second);

        sort(times.begin(), times.end());
        reverse(times.begin(), times.end());
        for(int t : times) {
            if(cnt1 < 9) {
                cnt1++;
                res += t;
                continue;
            }
            else if(cnt2 < 9) {
                cnt2++;
                res += 2 * t;
                continue;
            }
            else {
                cnt3++;
                res += 3 * t;
                
            }
        }
        return res;
    }
};
