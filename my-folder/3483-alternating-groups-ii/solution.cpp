class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        for(int i = 0; i < n; i++) {
            colors.push_back(colors[i]);
        }
        int result = 0;
        int start = 0, end = 1;

        while(start < n && end < 2 * n) {
            if(colors[end] == colors[end-1]) {
                start = end;
                end++;
                continue;
            }
            if(end-start+1 < k) {
                end++;
                continue;
            }
            else {
                start++;
                end++;
                result++;
            }
        }

        return result;
    }
};
