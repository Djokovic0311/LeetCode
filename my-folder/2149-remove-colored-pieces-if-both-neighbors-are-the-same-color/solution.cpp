class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0;
        int n = colors.length();
        int i = 0,j = 0;

        while(i < n) {
            cout << i << endl;
            int flg = -1;
            int tmp_a = 1, tmp_b = 1;
            for(j = i+1; j < n; j++) {
                if (colors[i] == colors[j] && colors[i] == 'A') {tmp_a++; flg = 0;}
                else if (colors[i] == colors[j] && colors[i] == 'B') {tmp_b++; flg = 1;}
                else break;
            }
            cout << tmp_a << ' ' << tmp_b << endl;
            // cout << a << ' ' << b << endl;
            if(flg == 0) a += max(0,tmp_a-2);
            else if(flg == 1) b += max(0,tmp_b-2);
            i = j;            
        }
        return a > b;
    }
};

