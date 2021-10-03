class Solution {
public:
    int minimumMoves(string s) {
        int count = 0;
        int n = s.length(); 
        int head = 0;
        int flag = 0;
        // for(int i = 0; i < n; i++) {
        //     if(s[i] == 'X')  flag = 1;
        // }
        // if(flag == 0) return 0;
        while(head < n) {
            while(s[head] == 'O' && head < n) head++;
            if(head == n) return count;
            int tmp = 0;
            while(head < n && tmp < 3) {
                tmp++;
                head++;
            }
            count++;
        }
        return count;
    }
};
