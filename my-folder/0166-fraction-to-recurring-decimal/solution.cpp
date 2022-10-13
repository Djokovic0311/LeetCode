class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        
        string res = "";
        if(!numerator) return "0";
        if(numerator>0 ^ denominator>0) {
            res += '-';
        }
        long num = labs(numerator), den = labs(denominator);
        long q = num / den;
        long r = num % den;
        res += to_string(q);
        if(r == 0) return res;
        unordered_map<long, int> mp;
        res += '.';
        while(r) {
            if(mp.find(r) != mp.end()) {
                int pos = mp[r];
                res.insert(pos,"(");
                res+= ')';
                break;
            }
            else {
                mp[r] = res.length();
                r *= 10;
                q = r / den;
                r = r % den;
                res += to_string(q);
            }
        }
        return res;
    }
};
