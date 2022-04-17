class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(int task : tasks) {
            mp[task]++;
        }
        int count = 0;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(it->second < 2) return -1; 
            // if(it->second == 2 || it->second == 3) 
            //     count += 1;
            else count += (it->second-1) / 3 +1;
        }
        return count;
    }
};