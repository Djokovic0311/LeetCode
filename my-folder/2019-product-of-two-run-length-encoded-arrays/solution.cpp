class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        int n1 = encoded1.size(), n2 = encoded2.size();
        vector<vector<int>> res;
        int i = 0, j = 0;
        while(i < n1 && j < n2) {
            int freq1 = encoded1[i][1], freq2 = encoded2[j][1];
            if(!res.empty() && res.back()[0] == encoded1[i][0]*encoded2[j][0]) {
                res.back()[1] += min(freq1,freq2);
            } else {
                res.push_back(vector<int>{encoded1[i][0]*encoded2[j][0], min(freq1,freq2)});
            }
            if(freq1 < freq2) {
                encoded2[j][1] -= encoded1[i][1];
                i++;
            } else if(freq2 < freq1) {
                encoded1[i][1] -= encoded2[j][1];
                j++;
            } else {
                i++;
                j++;
            }
        }
        return res;
    }
};
