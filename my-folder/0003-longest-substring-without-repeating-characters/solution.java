class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> chars = new HashMap();
        int l = 0, r = 0;
        int res = 0;
        while(r < s.length()) {
            char c = s.charAt(r);
            chars.put(c, chars.getOrDefault(c,0)+1);
            while(chars.get(c) > 1) {
                char left = s.charAt(l);
                chars.put(left, chars.get(left) - 1);
                l++;
            }

            res = Math.max(res, r-l+1);
            r++;
        }

        return res;
    }
}
