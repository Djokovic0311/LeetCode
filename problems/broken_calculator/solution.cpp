class Solution {
public:
    int brokenCalc(int x, int y) {
      int steps = 0;
        
      while (y > x) {
        steps += 1 + y % 2; 
        y += y % 2; 
        y /= 2;
      }
      return steps + (x - y);        
    }
};