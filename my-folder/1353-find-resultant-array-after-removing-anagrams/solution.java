class Solution {
    private String sortString(String s) {
        char[] chars = s.toCharArray();
        Arrays.sort(chars);
        String sorted = new String(chars);
        return sorted;
    }
    public List<String> removeAnagrams(String[] words) {
        ArrayList res = new ArrayList<>();
        int n = words.length;
        Stack<String> stk = new Stack<>();

        for(String word : words) {
            
            if(!stk.empty()){
                String s = sortString(stk.peek());
                if(sortString(word).equals(s)) {
                    
                    continue;
                } else {
                    stk.push(word);
                }
            } else {
                // System.out.println(word);
                stk.push(word);
            }
        }
        while(!stk.empty()) {
            res.add(stk.peek());
            stk.pop();
        }
        Collections.reverse(res);
        return res;
    }
}
