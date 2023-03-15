class Solution {
public:
    string toBinary(int n)
    {
        string r;
        while (n != 0){
            r += ( n % 2 == 0 ? "0" : "1" );
            n /= 2;
        }
        reverse(r.begin(), r.end());
        return r;
    }
    bool queryString(string s, int n) {
        for(int i = 1; i <= n; i++) {
            string binary = toBinary(i);
            // cout << binary <<endl;
            if(s.find(binary) == -1)return false;
        }
        return true;
    }
};
