class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long total_min = 0;
        long long total_max = 0;
        int n = differences.size();
        long long tmp = 0;
        
        for(int i = 0; i < n; i++) {
            tmp += differences[i];
            total_min = min(total_min, tmp);
            total_max = max(total_max, tmp);
        }
        cout << total_min << total_max <<endl;
        return (upper-total_max)-(lower-total_min)+1 > 0 ? (upper-total_max)-(lower-total_min)+1 : 0;
    }
};
