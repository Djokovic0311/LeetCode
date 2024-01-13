class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = INT_MAX;
        for(i = s.length()-1; i > 0; i--) {
            if(s[i] > s[i-1]) break;
        }
        
        if(i == 0) return -1;
        
        reverse(s.begin()+i, s.end());

        int pos = upper_bound(s.begin()+i-1, s.end(), s[i-1]) - s.begin();
        // cout << pos << endl;
        swap(s[i-1], s[pos]);
        
        
        long long res = stoll(s);
        // cout << res;
        if(res > INT_MAX) return -1;
        return stoi(s);
    }
};
