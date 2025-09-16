class Solution {
public:
    int gcd(int a, int b) {
        return b == 0? a : gcd(b, a % b);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> stk;
        for(int num : nums) {
            while(!stk.empty()) {
                int top = stk.back();
                int g = gcd(top, num);
                if(g == 1) {
                    break;
                }
                stk.pop_back();
                long long lcm = (long long) top / g * num;
                num = lcm;
            }
            stk.push_back(num);
        }
        return stk;
    }
};
