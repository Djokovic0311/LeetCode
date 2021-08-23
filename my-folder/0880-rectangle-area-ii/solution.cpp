class Solution {
public:
    void addlist(list<pair<int, int>>& ylist, int left, int right)
    {
        auto it = ylist.begin();
        while(it != ylist.end() && it->second < left) {
            it++;
        }
        if (it == ylist.end() || it->first > right) {
            ylist.insert(it, {left, right});
        } else {
            it->first = min(left, it->first);
            it->second = max(right, it->second);
            auto preit = it++;
            while(it != ylist.end() && preit->second > it->first) {
                preit->second = max(preit->second, it->second);
                it = ylist.erase(it);
            }
        }
    }

    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<int> xlist;
        int area = 0;
        int mod = 7 + 1e9;

        for (auto c : rectangles) {
            xlist.push_back(c[0]);
            xlist.push_back(c[2]);
        }
        sort(xlist.begin(), xlist.end());
        xlist.erase(unique(xlist.begin(), xlist.end()), xlist.end());

        for (int i = xlist.size() - 2; i >= 0; i--) {
            list<pair<int, int>> ylist;
            for (auto r : rectangles) {
                // 区间有数据
                if (xlist[i] >= r[0] && xlist[i+1] <= r[2]) {
                    addlist(ylist, r[1], r[3]);
                }
            }
            long dist = 0;
            for (auto c : ylist) {
                dist += (c.second - c.first);
            }
            area = (area + (xlist[i+1] - xlist[i]) * dist) % mod;
        }
        return area;
    }
};

