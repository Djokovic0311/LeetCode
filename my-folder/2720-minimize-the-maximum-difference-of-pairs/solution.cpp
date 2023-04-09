class Solution {
public:
int minimizeMax(vector<int>& n, int p) {
    sort(begin(n), end(n));
    int l = 0, r = 1000000000;
    while (l < r) {
        int m = (l + r) / 2, cnt = 0;
        for (int i = 0; i + 1 < n.size(); ++i)
            if (m >= (n[i + 1] - n[i])) {
                ++cnt;
                ++i;
            }
        if (cnt >= p)
            r = m;
        else
            l = m + 1;
    }
    return l;
}
};

