class Solution {
public:
    // Function to calculate the number of combinations of 2 items from n items.
    long long comb2(int n) {
        return 1LL * n * (n - 1) / 2;
    }

    long long distributeCandies(int n, int limit) {
        // If the total number of candies exceeds 3 times the limit, return 0
        if (n > 3 * limit) {
            return 0;
        }

        // Calculate the total combinations without any limit
        long long ans = comb2(n + 2);

        // Subtract the combinations where at least one child gets more than 'limit' candies
        if (n > limit) {
            ans -= 3 * comb2(n - limit + 1);
        }

        // Add back the combinations where at least two children get more than 'limit' candies
        if (n >= 2 * limit + 2) {
            ans += 3 * comb2(n - 2 * limit);
        }

        return ans;
    }
};
