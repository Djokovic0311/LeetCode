class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int k = (intLength + 1) /2;
        vector<long long> res;
        int start = pow(10, k-1), end = pow(10, k) - 1;
        for(auto q : queries) {
            int a = start + q - 1;
            cout << a << " ";
            if(a > end) {
                res.push_back(-1);
                continue;
            } else if (intLength % 2 == 0){
                string tmp = to_string(a);
                string reversed = tmp;
                reverse(reversed.begin(), reversed.end());
                res.push_back(stoll(tmp + reversed));
            } else {
                string tmp = to_string(a);
                string reversed = tmp;
                reverse(reversed.begin(), reversed.end());
                res.push_back(stoll(tmp + reversed.substr(1)));               
            }

        }
        return res;
    }
};
