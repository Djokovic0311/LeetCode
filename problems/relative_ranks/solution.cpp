class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int,int, greater<int>> mp;
        int n = score.size();
        vector<string> result(n);

        for(int i = 0; i < n; i++) {
            mp[score[i]] = i;
        }
        int sum = 1;
        for(auto iter = mp.begin(); iter != mp.end(); iter++) {
            if(sum == 1)
                result[iter->second] = "Gold Medal";
            if(sum == 2)
                result[iter->second] = "Silver Medal";
            if(sum == 3)
                result[iter->second] = "Bronze Medal";
            if(sum > 3)
                result[iter->second] = to_string(sum);
            sum++;
            // cout << iter->second << endl;
        }
        
        return result;
    }
};