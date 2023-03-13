class Solution {
public:
    double angleClock(int hour, int minutes) {
        return min(abs((11 / 2.0) *minutes - 30 *hour), 360 - abs((11 / 2.0) *minutes - 30 *hour));
        }
    
};
