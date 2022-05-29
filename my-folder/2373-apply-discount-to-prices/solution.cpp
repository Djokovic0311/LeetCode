class Solution {
public:
    bool isPrice(string s) {
        if(s.length() <= 1 || s[0] != '$') return false;
        for(int i = 1; i < s.length(); i++) {
            if(s[i]>'9'||s[i]<'0') return false;
        }
        return true;
    }
string doubleToString(const double &val)
{
    char* chCode;
    chCode = new char[20];
    sprintf(chCode, "%.2lf", val);
    std::string str(chCode);
    delete[]chCode;
    return str;
}

    string discountPrices(string sentence, int discount) {
        istringstream ss(sentence);
        string word;
        string res = "";
        while(ss >> word) {
            if(isPrice(word)) {
                long n = stol(word.substr(1));
                double tmp = n*((100.0-discount)/100.0);
                res += '$';
                res += doubleToString(tmp);
                res += ' ';
            }
            else {
                res += word;
                res += ' ';
            }
        }
        // cout << endl;
        return res.substr(0,res.length()-1);
    }
};
