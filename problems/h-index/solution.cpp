class Solution {
public:
    int hIndex(vector<int>& citations) {
        int res;
        sort(citations.begin(),  citations.end());
        int s = 0;
        int e = citations.size()-1;
        int avg;
        while (s <= e) {
            if (citations[avg = (e + s) / 2] < citations.size() - avg) s = avg + 1;
            else e = avg - 1;
        }
        return citations.size() - s;
    }
};