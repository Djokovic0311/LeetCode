class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(intervals.begin(),  intervals.end());
        int res = 1;
        for(auto interval : intervals) {
            int start = interval[0], end = interval[1];
            while(!pq.empty() && pq.top() <= start)
                pq.pop();
            pq.push(end);
            res = max(res, int(pq.size()));
        }
        return res;
    }
};