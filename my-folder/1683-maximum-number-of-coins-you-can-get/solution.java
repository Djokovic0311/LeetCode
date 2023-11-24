class Solution {
    public int maxCoins(int[] piles) {
        Arrays.sort(piles);
        int maxCoins = 0;
        int n = piles.length / 3;

        for (int i = 0; i < n; i++) {
            maxCoins += piles[piles.length - (2 * i) - 2];
        }

        return maxCoins;
    }
}
