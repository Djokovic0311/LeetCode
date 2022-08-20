class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length(), m = shifts.size();
        vector<int> record(n+1,0);
        for(auto shift : shifts) {
            
                if(shift[2] == 1)
                    record[shift[0]] = (record[shift[0]]+1)%26, record[shift[1]+1] = (record[shift[1]+1]-1+26)%26;
                else record[shift[1]+1] = (record[shift[1]+1]+1)%26, record[shift[0]] = (record[shift[0]]-1+26)%26;
            
        }
        vector<int> pre(n,0);
        // cout << 'a'+24;
        if(n==1) {
            int k = (s[0]-'a'+(record[0]))%26;
            char r = 'a'+k;
            char s1[2] = {r, 0};
            string s2;
            return s2 = s1;
        }
        pre[0] = record[0];
        for(int i = 1; i < n; i++)
            pre[i] = pre[i-1]+record[i];
        string res = "";
        for(int i = 0; i < n; i++) {
            // cout << record[i] << ' ';
            res += (s[i]-'a'+(pre[i]))%26+'a';
        }
        // cout << endl;
        return res;
    }
};
