class Solution {
public:
    int minimumRecolors(string s, int k) {
        // int n = blocks.size();
        // int mi = INT_MAX;
        // int i = 0, j;
        // int tmp = 0;
        // for(j = 0; j < n; j++) {
        //     if(j < k && blocks[j] == 'W') {
        //         tmp++;
        //     }
        //     else if(j >= k && blocks[j] == 'W') {
        //         tmp++;
        //         if(blocks[j-k]=='W')
        //             tmp--;
        //         // cout << j << ' ' <<tmp << endl; 
        //         mi = min(mi, tmp);
        //     }
        //     else if(j >= k && blocks[j] == 'B') {
        //         if(blocks[j-k]=='W')
        //             tmp--;
        //         // cout << j << ' ' << tmp <<endl; 
        //         mi = min(mi, tmp);
        //     }
        //     // mi = min(mi, tmp);
        // }
        // return k == blocks.size()?tmp:mi;
        
        const int N = 2e5 + 50;
        int sum[N];
        for (int i = 1; i <= s.size(); i++)
        {
            sum[i] = sum[i - 1] + (s[i - 1] == 'W' ? 1 : 0);
        }
        int res=1e9;
        for (int i = k; i <= s.size(); i++)
        {
            res=min(res,sum[i]-sum[i-k]);}
        return res;
    }
};
