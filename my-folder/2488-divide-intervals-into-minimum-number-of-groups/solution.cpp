const int N = 1e5 + 10;
struct Range
{
    int l, r;
    bool operator<(const Range& R)const
    {
        return l < R.l;
    }
}range[N];

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int res = 0;
        priority_queue<int, vector<int>, greater<int>> heap;
        for (int i = 0; i < n; i++)
        {
            if (heap.empty() || heap.top() >= intervals[i][0])
            {
                res++;//建立新的分组
                heap.push(intervals[i][1]);
            }
            else
            {
                //弹出第一组右端点的值并更新
                heap.pop();
                heap.push(intervals[i][1]);
            }
            // cout << res;
        }
        return res;
    }
};
