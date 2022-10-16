class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i = num; i >= num/2 ; i--) {
            string tmp = to_string(i);
            reverse(tmp.begin(), tmp.end());
            if(num == i + stoi(tmp))
                return true;
        }
        return false;
    }
};
