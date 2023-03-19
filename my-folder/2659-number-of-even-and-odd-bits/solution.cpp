class Solution {
public:
    
    string toBinary(int n)
    {
        string r;
        while (n != 0){
            r += ( n % 2 == 0 ? "0" : "1" );
            n /= 2;
        }
        return r;
    }
    vector<int> evenOddBit(int n) {
        int even = 0, odd = 0;
        string s = toBinary(n);
        int l = s.length();
        // reverse(s.begin(), s.end());
        // cout << s << endl;
        for(int i = 0; i < l; i++) {
            if(s[i] == '1') {
                if(i % 2 == 0)even++;
                else odd++;
            }
        }
        return {even, odd};        
    }
};
