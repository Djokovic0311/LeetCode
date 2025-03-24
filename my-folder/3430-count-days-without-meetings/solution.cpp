class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int res = 0;
        int lastEnd = 0;
        sort(meetings.begin(), meetings.end());
        for(auto m : meetings) {
            int start = m[0], end = m[1];
            if(start > lastEnd + 1) {
                res += start - lastEnd - 1;
            }
            lastEnd = max(lastEnd, end);
        }

        res += days - lastEnd;

        return res;
    }
};
