class Solution {
public:
    
    void pre_process(vector<vector<int>>& dp, string s)
    {

        // Get the size of the string
        int n = s.size();
        
        // Initially mark every
        // position as false
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                dp[i][j] = false;
        }

        // For the length
        for (int j = 1; j <= n; j++) {

            // Iterate for every index with
            // length j
            for (int i = 0; i <= n - j; i++) {

                // If the length is less than 2
                if (j <= 2) {

                    // If characters are equal
                    if (s[i] == s[i + j - 1])
                        dp[i][i + j - 1] = true;
                }

                // Check for equal
                else if (s[i] == s[i + j - 1])
                    dp[i][i + j - 1] = dp[i + 1][i + j - 2];
            }
        }
    }
     static bool sortbysec(const pair<int, int>& a,
                   const pair<int, int>& b)
    {
        return (a.second < b.second);
    }

    // Function to find maximal disjoint set
    int maxDisjointIntervals(vector<pair<int, int>> list)
    {
        int cnt = 1;
        // Sort the list of intervals
        sort(list.begin(), list.end(), sortbysec);

        // First Interval will always be
        // included in set
        // cout << "[" << list[0].first << ", "
        //      << list[0].second << "]" << endl;

        // End point of first interval
        int r1 = list[0].second;

        for (int i = 1; i < list.size(); i++) {
            int l1 = list[i].first;
            int r2 = list[i].second;

            // Check if given interval overlap with
            // previously included interval, if not
            // then include this interval and update
            // the end point of last added interval
            if (l1 > r1) {
                // cout << "[" << l1 << ", "
                //  << r2 << "]" << endl;
                cnt++;
                r1 = r2;
            }
        }
        return cnt;
    }
    int maxPalindromes(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n,false));
        pre_process(dp,s);
        int res = 0;
        vector<pair<int, int>> record;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++)
//                 cout << dp[i][j] << ' ';
//             cout << endl;
                    
//         }        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                if(dp[i][j] == 1 && j-i+1 >= k) {
                    // cout << i << ' ' << j << endl;
                    record.push_back(make_pair(i,j));
                }
                    
        }
        if(record.size() == 0) return res;
        return maxDisjointIntervals(record);
    }
};
