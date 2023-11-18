class Solution {
    public String toHexspeak(String num) {
        long n = Long.valueOf(num);
        StringBuilder sb = new StringBuilder();
        while(n > 0) {
            long r = n % 16;
            if(r == 0)
                sb.insert(0,'O');
            else if (r == 1)
                sb.insert(0,'I');
            else if(r >= 10) {
                sb.insert(0, (char)(r - 10 + (int)'A'));

            } else return "ERROR";
            n /= 16;
        }

        return sb.toString();
    }
}
