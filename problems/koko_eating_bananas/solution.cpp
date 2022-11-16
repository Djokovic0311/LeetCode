class Solution {
public:
    int hoursRequired(const vector<int> &piles, int k)
    {
        int h = 0;
        if(k == 0) return INT_MAX;
        for(int i : piles)
        {
            if(i % k != 0)
            {
                h++;
            }
            h += (i / k);
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        long long sum = 0;
        for(auto p : piles) sum += p;
        int l, r;
        if(sum % h == 0) l = sum/h;
        else l = sum/h + 1;
        r = piles[n-1];
        // int res = INT_MAX;
        while(l < r) {
            int mid = l + (r - l) / 2;
            int ans = hoursRequired(piles, mid);
			// If hours required is greater than our limit, ignore mid
            if(ans > h)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
};