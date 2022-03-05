class Solution {

public:
    long long nint(const vector<int>& mapping, int v){
        long long d = 0, dd = 0, tens = 1;
        while(v >= 10){
            d += mapping[v % 10];
            d *= 10;
            v /= 10;
            tens *= 10;
        }
        d += mapping[v % 10];
        tens *= 10;
        while(tens){
            dd += (tens * (d % 10));
            d /= 10;
            tens /= 10;
        }        
        return dd;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int> nums) {
        sort(begin(nums), end(nums), [&](int a, int b){
            return nint(mapping, a) < nint(mapping, b);
        });
        return nums;
    
    }
};