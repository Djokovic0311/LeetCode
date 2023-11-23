class Solution {
    public String longestCommonPrefix(String[] strs) {
        int n = strs.length;
        if(n == 0) return "";
        String prefix = strs[0];
        for(int i = 1; i < n; i++) {
            while(strs[i].indexOf(prefix) != 0) {
                prefix = prefix.substring(0, prefix.length()-1);
                if(prefix.isEmpty()) return "";
            }
        }
        return prefix;
    }
}
