class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        int n = paint.size();
        vector<int> painted(n, 0);
        auto comp = [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; };
        int farthest_pt = (*max_element(paint.begin(), paint.end(), comp))[1];
        vector<vector<pair<int, bool>>> points(farthest_pt+1);
        for(int i = 0;i < n; i++) {
            points[paint[i][0]].push_back({i, true});
            points[paint[i][1]].push_back({i, false});
        }
        set<int> sweep_line;
        for(int x = 0; x <= farthest_pt; x++) {
            // if(points[x].size()) cout << x << endl;
            for(auto p : points[x]) {
                // cout << p.first << " " << p.second << endl;
                if(p.second)
                    sweep_line.insert(p.first);
                else
                    sweep_line.erase(p.first);
            }
            if(!sweep_line.empty())
                painted[*sweep_line.begin()] += 1;
        }
        return painted;
    }
};
