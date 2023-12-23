class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int n1 = firstList.size(), n2 = secondList.size();
        int i = 0, j  = 0;
        while(i < n1 && j < n2) {
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);
            cout << start << " " << end << endl;
            if(start <= end) {
                res.push_back({start, end});
            }
            if(firstList[i][1] < secondList[j][1]) i++;
            else j++;
        } 

        return res;
    }
};

