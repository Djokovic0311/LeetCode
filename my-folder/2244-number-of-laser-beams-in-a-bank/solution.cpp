class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, res = 0;
        for(string s : bank) {
            int count = 0;
            for(char c : s) {
                count += c == '1';
            }
            if(count) {
                res += prev * count;
                prev = count;
            }
            
        }

        return res;
    }
};
