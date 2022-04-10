class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        // vector<int> record(10,0);
        priority_queue<int> odd,even;
        for(char c : s) {
            int tmp = c-'0';
            if(tmp % 2 == 0) even.push(tmp);
            else odd.push(tmp);
        }
        int res = 0;
        for(int i = 0; i < s.length(); i++) {
            if((s[i]-'0') % 2 == 0) {
                res = res * 10 + even.top();
                // cout << even.top() << endl;
                even.pop();
            }
            else {
                res = res * 10 + odd.top();
                // cout << odd.top() <<endl;
                odd.pop();
            }
            // cout << res << endl;
            // res 
        }
        return res;
    }
};
