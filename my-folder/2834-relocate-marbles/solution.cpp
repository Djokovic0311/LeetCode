class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int, int> positions;

        for (auto num : nums) {
            positions[num]++;
        }

        int n = moveFrom.size();
        for (int i = 0; i < n; ++i) {
            //     for (auto const& position : positions) {
            // cout << position.first << " " << position.second << endl;}
            int from = moveFrom[i], to = moveTo[i];
            if(from == to) continue;
            if (positions.count(from)) {
                positions[to] += positions[from];
                positions[from] = 0;
            }
            // cout << endl;
        }

        vector<int> result;
        for (auto const& position : positions) {
            // cout << position.first << " " << position.second << endl;
            if(position.second > 0)
                result.push_back(position.first);
        }

        return result;        
    }
};
