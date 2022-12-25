class Solution {
public:
int maximumTastiness(vector<int>& price, int k) {
    sort(price.begin(), price.end());
    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid, price, k)) lo = mid + 1;
        else hi = mid;
    }
    return lo - 1;
}
bool check(int x, vector<int>& price, int k) {
    int last = price[0], count = 1, i = 1;
    while (count < k && i < price.size()) {
        if (price[i] - last >= x)
            last = price[i], count++;
        i++;
    }
    return count == k;
}
};
