class Solution {
public:
int modExpo(int base, int exponent, int mod) {
    int result = 1;
    base = base % mod;
    while (exponent > 0) {
        // If exponent is odd, multiply base with result
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        // Exponent must be even now
        exponent = exponent >> 1; // equivalent to exponent /= 2
        base = (base * base) % mod;
    }
    return result;
}

    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
    vector<int> goodIndices;
    
    for (int i = 0; i < variables.size(); ++i) {
        int a = variables[i][0];
        int b = variables[i][1];
        int c = variables[i][2];
        int m = variables[i][3];

        // Calculate (ai^bi % 10)
        int abMod10 = modExpo(a, b, 10);

        // Calculate ((ai^bi % 10)^ci) % mi
        int result = modExpo(abMod10, c, m);

        // Check if the result matches the target
        if (result == target) {
            goodIndices.push_back(i);
        }
    }

    return goodIndices;     
    }
};
