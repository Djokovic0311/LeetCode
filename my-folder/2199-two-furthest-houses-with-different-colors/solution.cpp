class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int i = 0, j = n - 1;
        if(colors[n-1] != colors[0]) return n-1;
        while(i < j) {
            if(colors[i] == colors[j]) j--;
            else break;
        }
        int sum1 = j - i;
        i = 0;
        j = n - 1;
        while(i < j) {
            if(colors[i] == colors[j]) i++;
            else break;
        }
        int sum2 = j - i;
        return max(sum1, sum2);
        return 0;
    }
};
