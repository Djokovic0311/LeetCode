class Solution {
public:
    long long flowerGame(int n, int m) {
        // odd (n+1)/2 even (n-1)/2
        // odd (m+1)/2 even (m-1)/2
        // nm-1/2 
        return (long long) m * (long long) n /2;
    }
};
