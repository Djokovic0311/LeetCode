class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.length();
        vector<string> record;
        for(int i = 0; i < n; i++) {
            if(number[i] == digit) {
                string tmp = number.substr(0,i) + number.substr(i+1);
                // cout << tmp <<endl;
                record.push_back(tmp);
            }
        }
        // cout << record.size();
        sort(record.begin(),  record.end());
        return record[record.size()-1];
    }
};