class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> pairs;
        for(int i = 0; i < n; i++) {
            pairs.push_back({position[i], speed[i]});
        }
        sort(pairs.begin(), pairs.end());
        vector<float> time(n);
        for(int i = 0; i < n; i++) {
            time[i] = (float)(target - pairs[i].first) / pairs[i].second;
        }

        int fleets = n;
        for(int i = n-1; i > 0; i--) {
            if(time[i] >= time[i-1]) {
                time[i-1] = time[i];
                fleets--;
            }
        }

        return fleets;
    }
};
