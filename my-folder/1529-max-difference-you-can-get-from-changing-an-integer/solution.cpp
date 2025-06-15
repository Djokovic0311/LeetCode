class Solution {
public:
    string change(int num, int x, int y) {
        string num_s = to_string(num);
        for(char& c : num_s) {
            if(c-'0' == x) {
                c = '0'+y;
            }
        }
        return num_s;
    }
    int maxDiff(int num) {
        int max_num = num, min_num = num;
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                string res = change(num, i, j);
                if(res[0] != '0') {
                    int res_i = stoi(res);
                    max_num = max(res_i, max_num);
                    min_num = min(res_i, min_num);
                }
            }
        }
        return max_num - min_num;
    }
};
