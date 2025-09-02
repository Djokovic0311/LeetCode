class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int res = 0;
        int n = points.size();
        for(int i = 0; i < n; i++) {
            vector<int> A = points[i];
            for(int j = 0; j < n; j++) {
                vector<int> B = points[j];
                if(i == j || !(A[0] <= B[0] && A[1] >= B[1])) {
                    continue;
                }
                if(n == 2) {
                    res++;
                    continue;
                }
                bool flag = false;
                for(int k = 0; k < n; k++) {
                    if(k == i || k == j) {
                        continue;
                    }
                    auto tmp = points[k];
                    bool isXContained =
                        tmp[0] >= A[0] && tmp[0] <= B[0];
                    bool isYContained =
                        tmp[1] <= A[1] && tmp[1] >= B[1];
                    if(isXContained && isYContained) {
                        flag = true;
                        break;
                    }
                }
                res += (int)!flag;
            }
        }
        return res;
    }
};
