class Solution {
    public List<String> letterCombinations(String digits) {
        if (digits == null || digits.isEmpty()) return new ArrayList<>();
        String[] mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        List<String> ans = new ArrayList<>();
        ans.add("");

        for (char digit : digits.toCharArray()) {
            List<String> extendCombination = new ArrayList<>();
            for (String currentCombination : ans) {
                for (char newChar : mappings[digit - '2'].toCharArray()) {
                    extendCombination.add(currentCombination + newChar);
                }
            }
            ans = extendCombination;
        }

        return ans;     
    }
}
