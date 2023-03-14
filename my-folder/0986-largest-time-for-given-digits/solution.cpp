class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        string res = "";
        sort(arr.begin(), arr.end());
        string s = "";
        for(int a : arr) s += to_string(a);
        for(int j = 23; j >= 0;j--) {
            for(int i = 59; i >= 0; i--) {
                string tmp = i>= 10? to_string(i) : "0"+to_string(i);
                tmp = ":" + tmp;
                tmp = (j>= 10? to_string(j) : "0"+to_string(j)) + tmp;
                string t = tmp;
                sort(t.begin(), t.end());
                if(t.substr(0,4) == s) {
                    return tmp;
                }
            }
        }
        return res;
    }
};
