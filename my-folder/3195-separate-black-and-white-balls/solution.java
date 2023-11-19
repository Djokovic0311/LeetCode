class Solution {
    public long minimumSteps(String s) {
        long totalSwaps = 0;
        int whiteBalls = 0;


        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == '0') {
                whiteBalls++;
            } else {
                totalSwaps += (long) whiteBalls;
            }
        }

        return totalSwaps;   
    }
}
