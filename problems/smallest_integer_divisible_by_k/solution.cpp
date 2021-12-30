class Solution {
public:
    int smallestRepunitDivByK(int k) {
            int n = 0, ans = 0;
        bool *hit = new bool[k];     
        for (int i = 0; i < k; i ++) hit[i] = false;
        while (true) { // at most k times, because 0 <= remainder < k
            ++ ans;
            n = (n * 10 + 1) % k; // we only focus on whether to divide, so we only need to keep the remainder.
            if (n == 0) return ans; // can be divisible
            if (hit[n]) return -1; // the remainder of the division repeats, so it starts to loop that means it cannot be divisible.
            hit[n] = true;  
    }}
};