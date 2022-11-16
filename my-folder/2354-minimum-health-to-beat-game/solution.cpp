class Solution {
public:
    long long minimumHealth(vector<int>& d, int a) {
return accumulate(begin(d), end(d), 1ll) - min(a, *max_element(begin(d), end(d)));
    }
};
