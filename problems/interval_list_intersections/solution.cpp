class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> v;
        int i = 0, j = 0;
        while(i < firstList.size() && j < secondList.size()) {
            int left = max(firstList[i][0], secondList[j][0]);
            int right = min(firstList[i][1], secondList[j][1]);
            if(left <= right) v.push_back({left, right});
            if(firstList[i][1] < secondList[j][1])   i++;
            else j++;
        }
        return v;
    }
};