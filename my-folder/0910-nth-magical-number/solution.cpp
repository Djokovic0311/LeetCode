# define ll long int
class Solution {
public:
    int mod = 1e9 + 7;

    int gcd(int a, int b) {
      if (b == 0)
        return a;
      return gcd(b, a%b);
    };
  
    int lcm(int a, int b) {
      return (a * b) / gcd(a, b);
    };
  
    int nthMagicalNumber(int n, int a, int b) {
      ll low, mid, high, target;
      ll lcmOfAB = lcm(a, b);
      
      low = 1;
      high = 1e17;
	  
      while (low < high) {
        mid = (low + high) / 2;
        target = (mid / a) + (mid / b) - (mid / lcmOfAB);

		
        if (target < n) {
          low = mid + 1;
        } else {
          high = mid;
        }
      }
      
      return high % mod;
    }
};
