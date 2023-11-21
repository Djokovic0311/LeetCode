class Solution {
    private static final int MOD = 1000000007;
    public int countNicePairs(int[] nums) {
        
        Map<Integer, Integer> freq = new HashMap<>();
        int count = 0;

        for (int num : nums) {
            int diff = num - rev(num);
            count = (count + freq.getOrDefault(diff, 0)) % MOD;
            freq.put(diff, freq.getOrDefault(diff, 0) + 1);
        }

        return count;        
    }

    private int rev(int num) {
        int revNum = 0;
        while (num > 0) {
            revNum = revNum * 10 + num % 10;
            num /= 10;
        }
        return revNum;
    }
}
