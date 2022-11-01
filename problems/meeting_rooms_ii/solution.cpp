class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int res = 1;
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto inter : intervals) {
            int s = inter[0], e = inter[1];
            while(!pq.empty() && pq.top() <= s) pq.pop();
            pq.push(e);
            res = max(res, int(pq.size()));
        }
        return res;
    }
};