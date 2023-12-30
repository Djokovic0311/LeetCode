class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1, j = b.length()-1;
        int carry = 0;
        string res = "";
        while(i>= 0 || j >= 0 ||carry > 0) {
            if(i>=0 && a[i--] == '1') carry++;
            if(j>=0 && b[j--] == '1') carry++;
            res.insert(0, carry % 2 == 0? "0":"1");
            carry /= 2;
        }
        return res;
    }
};
