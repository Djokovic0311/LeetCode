class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    int dx = std::abs(fx - sx);
    int dy = std::abs(fy - sy);
    int max_t = dx + dy;
    
    // Compute the maximum moves required
    int max_moves = std::max(dx, dy);

    int min_t = max_moves;
    // If diff is non-negative and even, return true.
        if(t == 1  && max_t == 0) return false;
    if(t >= min_t) return true;
        return false;
    }
};
