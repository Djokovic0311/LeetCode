class Solution {
    public int countLetters(String s) {
        int n = s.length();
        int res = 0;
        int l = 0, r = 0;

        while(r < n) {
            while(l < r && s.charAt(l) != s.charAt(r)) {
                l++;
            }
            res += (r-l) +1;
            r++;
        }

        return res;
    }
}
