class Solution {
    public int findMinimumOperations(String s1, String s2, String s3) {
        // Iterate while all strings have length greater than 0
        int operations = 0;
        while (s1.length() > 0 && s2.length() > 0 && s3.length() > 0) {
            // Check if all strings are equal
            if (s1.equals(s2) && s2.equals(s3)) {
                return operations;
            }
            // If not equal, remove the rightmost character from the longest string(s)
            if (s1.length() >= s2.length() && s1.length() >= s3.length()) {
                s1 = s1.substring(0, s1.length() - 1);
                operations++;
            } else if (s2.length() >= s1.length() && s2.length() >= s3.length()) {
                s2 = s2.substring(0, s2.length() - 1);
                operations++;
            } else {
                s3 = s3.substring(0, s3.length() - 1);
                operations++;
            }
        }
        return -1;
    }
}
