#define ff first
#define ss second
#define ll long long
class Solution {
public:
    string robotWithString(string s) {
        string ans, mid;
        int n = s.length();
        // auto st = s.begin();
        vector<int> record(n, n-1);
        char mi = 'z';
        for(int i = n-1; i >= 0; i--) {
            if(s[i] <= mi)
                record[i] = i;
            else
                record[i] = record[i+1];
            // record = min(mi, s[i]) + record;
            mi = min(mi, s[i]);
            // cout << mi << ' ';
        }
        // cout << endl;
        // for(int t : record) {
        //     cout << t << " ";
        // }
        // cout << endl;
        int st = 0;
        while(st < n) {
            int itr = record[st];
            if(mid.length() and mid.back() <= s[itr]) {
                ans += mid.back();
                mid.pop_back();
            }
            else {
                mid += s.substr(st, (itr-st) + 1);
                st = ++itr;
            }
        }
//         while (st != s.end()) {
//             auto itr = min_element(st, s.end());

//             if (mid.length() and mid.back() <= *itr) {
//                 ans += mid.back();
//                 mid.pop_back();
//             } else {
//                 mid += s.substr(st - s.begin(), (itr - st ) + 1);
//                 st = ++itr;
//             }
//         }
        
        if(mid.length()){
            reverse(mid.begin(),mid.end());
            ans+=mid;
        }
        return ans;
    }
};