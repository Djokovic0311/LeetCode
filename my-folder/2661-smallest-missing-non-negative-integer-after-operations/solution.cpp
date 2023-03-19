class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        // Create a map to store the frequency of
        // remainder of all element by K
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            int tmp = nums[i] % value;
            if(tmp < 0) tmp += value;
            mp[tmp]++;
        }
        // for(auto item : mp) {
        //     cout << item.first << " " << item.second << endl;
        // }
        for (int i = 0; i < n; i++) {

            // In order to generate i find an
            // element whose modulo value is equal
            // to i%K, return i as answer if no
            // such value is found
            // cout << i << endl;
            if (mp.find(i % value) == mp.end()) {
                return i;
            }

            // If we find element whose modulo
            // value equal to i%K
            mp[i % value]--;
            if (mp[i % value] == 0)
                mp.erase(i % value);
        }

        return n;
    }
};
